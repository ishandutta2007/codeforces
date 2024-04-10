#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const long long maxN = 100005;

long long opLeft[maxN], opRight[maxN], opAdd[maxN], nExecute[maxN];
long long theArray[maxN];

void prefixIncrease (long long* prefixes, int l, int r, long long d)
{
	prefixes[l] += d;
	prefixes[r + 1] -= d;
}

void toElements (long long* prefixes, int N)
{
	for (int i = 1; i < N; i++)
		prefixes[i] += prefixes[i - 1];
}

int main()
{
	int N, M, K;
	scanf ("%i %i %i", &N, &M, &K);

	long long previous = 0;
	for (int i = 0; i < N; i++)
	{
		scanf ("%lld", &theArray[i]);
		long long orig = theArray[i];
		theArray[i] -= previous;
		previous = orig;
	}

	for (int i = 0; i < M; i++)
	{
		scanf ("%lld %lld %lld", &opLeft[i], &opRight[i], &opAdd[i]);
		opLeft[i]--; opRight[i]--;
	}

	for (int i = 0; i < K; i++)
	{
		int l, r;
		scanf ("%i %i", &l, &r);
		l--; r--;
		prefixIncrease (nExecute, l, r, 1);
	}

	toElements (nExecute, M);

	for (int i = 0; i < M; i++)
		prefixIncrease (theArray, opLeft[i], opRight[i], opAdd[i] * nExecute[i]);

	toElements (theArray, N);

	for (int i = 0; i < N; i++)
		printf ("%lld ", theArray[i]);
	printf ("\n");

	return 0;
}