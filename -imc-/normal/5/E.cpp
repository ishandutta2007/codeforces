#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int maxN = 1000006;
int a[maxN], t[maxN];

int main()
{
	int N;
	scanf ("%i", &N);

	int maxIndex = 0;

	bool wereNot = false;
	for (int i = 0; i < N; i++)
	{
		scanf ("%i", &t[i]);
		if (t[i] > t[maxIndex] || (t[i] == t[maxIndex] && wereNot))
		{
			maxIndex = i;
			wereNot = false;
		}

		if (t[i] < t[maxIndex])
			wereNot = true;
	}

	int nMax = 0;

	for (int i = 0; i < N; i++)
	{
		a[i] = t[(maxIndex + i) % N];
		if (a[i] == t[maxIndex])
			nMax++;
		//printf ("%i ", a[i]);
	}
	//printf ("\n");
	a[N] = a[0];

	// Both are maximum

	long long answer = (long long)nMax * (nMax - 1) / 2;
	//printf ("Both max: %lld\n", answer);
	long long was = answer;

	// One of is maximum

	int firstMaximums = 0;
	int pBlockFrom = -1, pBlockTo = 0;
	int nBlocks = 0;

	for (int i = 0; i < N;)
	{
		int nMaximums = 0;
		while (i < N && a[i] == a[0])
			nMaximums++, i++;

		if (firstMaximums == 0)
			firstMaximums = nMaximums;

		int newpBlockTo = i;
		int minReq = 0;
		while (a[i] != a[0])
		{
			if (a[i] >= minReq)
			{
				//printf ("%i: +%i\n", i, nMaximums);
				answer++;
				minReq = a[i];
			}
			i++;
		}
		int newpBlockFrom = i - 1;

		minReq = 0;
		for (int j = pBlockFrom; j >= pBlockTo; j--)
			if (a[j] >= minReq)
			{
				answer ++;
				minReq = a[j];
			}

		pBlockFrom = newpBlockFrom;
		pBlockTo = newpBlockTo;

		nBlocks++;
	}

	int minReq = 0;
	for (int j = pBlockFrom; j >= pBlockTo; j--)
		if (a[j] >= minReq)
		{
			answer++;
			minReq = a[j];
		}

	if (nBlocks == 1 && firstMaximums == 1)
	{
		int secondMax = 0;
		for (int i = 0; i < N; i++)
			if (a[i] != a[0] && a[i] > secondMax)
				secondMax = a[i];

		int nFirstMax = 0, nSecondMax = 0;
		for (int i = 0; i < N; i++)
		{
			if (a[i] == a[0])
				nFirstMax++;
			if (a[i] == secondMax)
				nSecondMax++;
		}

		//printf ("Dec %lld %lld\n", nSecondMax, nFirstMax);
		answer -= nSecondMax * (long long)nFirstMax;
	}

	//printf ("With one max: %lld\n", answer - was);
	was = answer;

	// Neither is maximum

	vector < pair <int, int> > passed;

	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[0])
		{
			while (!passed.empty())
				passed.pop_back();
			continue;
		}

		while (!passed.empty() && passed.back().first < a[i])
		{
			answer += passed.back().second;
			passed.pop_back();
		}

		if (!passed.empty())
		{
			if (a[i] != passed.back().first)
			{
				answer++;
				passed.push_back (make_pair (a[i], 1));
			}
			else
			{
				answer += (passed.back().second++);
				if (passed.size() > 1)
					answer++;
			}
		}
		else
			passed.push_back (make_pair (a[i], 1));

		//printf ("After %i: answer %lld\n", i, answer);
	}

	cout << answer << endl;

	return 0;
}