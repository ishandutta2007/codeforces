#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

int nWorkers, nReads;

long long minTimeRead (long long from, long long to, long long start)
{
	if (start <= from)
		return to - start;
	else if (start >= to)
		return start - from;

	return min (2 * to - start - from, start + to - 2 * from);
}

const int maxN = 100500;
long long workerPos[maxN], readPos[maxN];

bool canRead (long long nTime)
{
	int readsDone = 0;

	for (int i = 0; i < nWorkers; i++)
	{
		int startRead = readsDone;
		while (readsDone < nReads && minTimeRead (readPos[startRead], readPos[readsDone], workerPos[i]) <= nTime)
			readsDone++;
	}

	return readsDone == nReads;
}

int main()
{
	scanf ("%d %d", &nWorkers, &nReads);

	for (int i = 0; i < nWorkers; i++)
		scanf ("%lld", &workerPos[i]);

	for (int i = 0; i < nReads; i++)
		scanf ("%lld", &readPos[i]);

	long long minTime = 0, maxTime = 1000000ll;
	maxTime *= maxTime;

	while (minTime != maxTime)
	{
		long long m = (minTime + maxTime) / 2;

		if (canRead (m))
			maxTime = m;
		else
			minTime = m + 1;
	}

	cout << minTime << endl;

	return 0;
}