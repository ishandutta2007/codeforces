#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 1005;

char strings[maxN][maxN];
int length[maxN];

int main()
{
	int numStrings = 0, maxLength = 0;
	while (std::cin.getline (strings[numStrings], maxN))
	{
		length[numStrings] = strlen (strings[numStrings]);
		if (length[numStrings] > maxLength)
			maxLength = length[numStrings];
		numStrings++;
	}

	for (int i = 0; i < maxLength + 2; i++) putchar ('*');
	putchar ('\n');

	int prev = 0;
	for (int i = 0; i < numStrings; i++)
	{
		putchar ('*');

		int start = (maxLength - length[i]);
		if (start % 2 == 1)
		{
			start += prev;
			prev = 1 - prev;
		}
		start /= 2;

		for (int j = 0; j < maxLength; j++)
		{
			int t = j - start;
			putchar ((t >= 0 && t < length[i]) ? strings[i][t] : ' ');
		}

		putchar ('*');
		putchar ('\n');
	}

	for (int i = 0; i < maxLength + 2; i++) putchar ('*');
		putchar ('\n');
	return 0;
}