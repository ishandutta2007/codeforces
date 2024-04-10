#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxN = 100005;

int size[maxN], profit[maxN];

struct compareByProfit
{
	bool operator() (int a, int b)
	{
		return profit[a] > profit[b];
	}
};

int main()
{
	int N, maxSize;
	scanf ("%i %i", &N, &maxSize);

	vector <int> first, second;

	for (int i = 0; i < N; i++)
	{
		scanf ("%i %i", &size[i], &profit[i]);
		if (size[i] == 1)
			first.push_back (i);
		else
			second.push_back (i);
	}

	sort (first.begin(), first.end(), compareByProfit());
	sort (second.begin(), second.end(), compareByProfit());

	int numFirstTaken = 0, numSecondTaken = 0;
	int freeSpace = maxSize, answer = 0;

	while (numFirstTaken < (int)first.size() && freeSpace >= size[first[numFirstTaken]])
	{
		answer += profit[first[numFirstTaken]];
		freeSpace -= size[first[numFirstTaken++]];
	}

	int bestAnswer = 0, bestFirst = 0, bestSecond = 0;

	while (true)
	{
		// Take as much seconds as possible

		while (numSecondTaken < (int)second.size() && freeSpace >= size[second[numSecondTaken]])
		{
			answer += profit[second[numSecondTaken]];
			freeSpace -= size[second[numSecondTaken++]];
		}

		// Rate current way

		if (answer > bestAnswer)
		{
			bestAnswer = answer;
			bestFirst = numFirstTaken;
			bestSecond = numSecondTaken;
		}

		// Remove one first

		if (numFirstTaken == 0) break;
		numFirstTaken--;
		answer -= profit[first[numFirstTaken]];
		freeSpace += size[first[numFirstTaken]];
	}

	printf ("%i\n", bestAnswer);
	for (int i = 0; i < bestFirst; i++) printf ("%i ", first[i] + 1);
	for (int i = 0; i < bestSecond; i++) printf ("%i ", second[i] + 1);
	printf ("\n");

	return 0;
}