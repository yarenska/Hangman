#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 11

int main(void)
{

	FILE *fPtr;

	int a;
	int pick;
	char selected[SIZE];
	char word[SIZE];
	int length;
	int letters[] = { 0,0,0,0,0,0,0,0,0,0 };
	char letter;
	int i;
	int num_correct = 0;
	int prev_correct = 0;
	int already = 0;
	int trials = 7;


	srand(time(NULL));
	a = 1 + (rand() % 16);

	fPtr = fopen("dictionary.txt", "r");

	if (fPtr == NULL)
	{
		printf("Game can not start..\n");
	}

	else
	{
		for (pick = 1; pick <= a; pick++)
		{
			fscanf(fPtr, "%s", word);
		}

		fclose(fPtr);

		strcpy(selected, word);
		length = strlen(selected);

		printf("Game words have only English alphabet letters..\n");
		printf("The hangman word contains %d letters\n", length);

		while (num_correct < length)
		{
			printf("\n");
			printf("Hangman word is: ");

			for (i = 0; i < length; i++)
			{
				if (letters[i] == 1)
				{
					printf("%c", selected[i]);
				}

				else {
					putchar('_');
				}

			}

			printf("\n");
			printf("Enter a letter: ");
			scanf(" %c", &letter);

			prev_correct = num_correct;

			for (i = 0; i < length; i++) {

				if (letters[i] == 1) {
					if (letter == selected[i]) {
						already = 1;
						break;
					}
					continue;
				}

				if (letter == selected[i]) {
					letters[i] = 1;
					num_correct++;
				}

			}

			if (prev_correct == num_correct && already == 0)
			{
				trials--;
				printf("Sorry, wrong guess\n");

				if (trials == 0)
				{
					break;
				}

			}

			else if (already == 1)
			{
				printf("Already Guessed!!\n");
			}

			else {
				printf("Correct guess :)\n");
			}

		}


		if (trials == 0)
		{
			printf("\nSorry you lose, the word was: %s\n",
				selected);
		}

		else {
			printf("\nYOU WIN!!! :)\n");
		}

	  }

	return 0;
}
