#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

const int maxN = 150500;
long long bufferOne[maxN], bufferTwo[maxN];

long long *happinessNow, *happinessNext;

typedef vector < pair <long long, long long> > pqueue;
pqueue pushTo, popFrom;

void queueReset()
{
	pushTo.clear();
	popFrom.clear();
}

long long infinity = 1000000000;

long long mempty (pqueue& q)
{
	return q.empty() ? -infinity : q.back().second;
}

void queuePush (long long x, pqueue& q = pushTo)
{
	q.push_back (make_pair (x, max (x, mempty (q))));
}

void queuePop()
{
	if (popFrom.empty())
	{
		while (!pushTo.empty())
		{
			queuePush (pushTo.back().first, popFrom);
			pushTo.pop_back();
		}
	}
	assert (!popFrom.empty());
	popFrom.pop_back();
}

long long queueGetMax()
{
	return max (mempty (pushTo), mempty (popFrom));
}

int main()
{
	infinity *= infinity;

	happinessNow = bufferOne;
	happinessNext = bufferTwo;
	
	#ifdef LOCAL
	freopen ("c.in", "r", stdin);
	#endif
	
	long long nCells, nLaunches, maxGo;
	cin >> nCells >> nLaunches >> maxGo;
	
	long long lastT = 0;
	for (int i = 0; i < nLaunches; i++)
	{
		long long a, b, t;
		cin >> a >> b >> t;
		a--;
		
		queueReset();
		queuePush (happinessNow[0]);
		
		long long queueLeft = 0, queueRight = 0;
		long long deltaT = t - lastT;
		for (int x = 0; x < nCells; x++)
		{			
			while (queueRight + 1 < nCells && queueRight + 1 - maxGo * deltaT <= x)
			{
				queueRight++;
				queuePush (happinessNow[queueRight]);
			}
			
			
			while (queueLeft < nCells && queueLeft + maxGo * deltaT < x)
			{
				queueLeft++;
				queuePop();
			}
			
			happinessNext[x] = queueGetMax() + b - abs (x - a);
		}
		lastT = t;
		
		swap (happinessNow, happinessNext);
	}
	
	long long answer = -infinity;
	for (int i = 0; i < nCells; i++)
		answer = max (answer, happinessNow[i]);
	cout << answer << endl;
	
	return 0;
}