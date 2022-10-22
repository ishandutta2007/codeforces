#include <cstring>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 1000005;
char theString[maxN];
int N;

int prefixBalance[maxN];
int minIndex[maxN * 4];

inline void relax (int t)
{
	minIndex[t] = prefixBalance[minIndex[t * 2 + 1]] < prefixBalance[minIndex[t * 2 + 2]] ? minIndex[t * 2 + 1] : minIndex[t * 2 + 2];
}

void build (int t, int l, int r)
{
	if (l == r) { minIndex[t] = l; return; }

	int m = (l + r) / 2;
	build (t * 2 + 1, l, m);
	build (t * 2 + 2, m + 1, r);
	relax (t);
}

const int infinity = 100000000;

void update (int t, int l, int r, int cell)
{
	if (l == r) return;

	int m = (l + r) / 2;

	if (cell <= m)
		update (t * 2 + 1, l, m, cell);
	else
		update (t * 2 + 2, m + 1, r, cell);

	relax (t);
}

int getAnswer (int t, int l, int r, int value)
{
	if (l == r)
		return (prefixBalance[l] >= value) ? l : -1;

	int m = (l + r) / 2;

	if (prefixBalance[minIndex[t * 2 + 1]] >= value)
	{
		int tryRight = getAnswer (t * 2 + 2, m + 1, r, value);
		return tryRight == -1 ? m : tryRight;
	}
	else return getAnswer (t * 2 + 1, l, m, value);
}

int getMin (int t, int l, int r, int pref)
{
	if (l > pref) return -1;
	if (r <= pref)
		return minIndex[t];

	int m = (l + r) / 2;

	int lm = getMin (t * 2 + 1, l, m, pref), rm = getMin (t * 2 + 2, m + 1, r, pref);

	if (lm == -1) return rm;
	if (rm == -1) return lm;

	return prefixBalance[lm] < prefixBalance[rm] ? lm : rm;
}

int main()
{
	scanf ("%s", theString);
	N = strlen (theString);

	for (int i = 0; i < N; i++)
	{
		int t = (theString[i] == '(' ? 1 : -1);
		prefixBalance[i] = (i == 0) ? t : t + prefixBalance[i - 1];
		//printf ("%i ", prefixBalance[i]);
	}
	//printf ("\n");

	build (0, 0, N - 1);

	int total = 1, maxLength = 0;

	int prevBalance = 0;
	for (int i = 0; i < N; i++)
	{
		int index = getAnswer (0, 0, N - 1, prevBalance);
		if (index == -1) index = i - 1;
		//printf ("%i (not less %i): index %i\n", i, prevBalance, index);
		index = getMin (0, 0, N - 1, index);
		//printf ("%i (precisely %i): index %i\n", i, prevBalance, index);
		int delta = index - i + 1;

		if (theString[i] != '(' || prefixBalance[index] != prevBalance)
			delta = 0;

		if (delta > 0)
		{
			//assert (delta % 2 == 0);

			if (delta > maxLength)
			{
				maxLength = delta;
				total = 0;
			}

			if (delta == maxLength)
				total++;
			//printf ("length %i substring\n", delta);
		}

		prevBalance = prefixBalance[i];
		prefixBalance[i] = infinity;
		update (0, 0, N - 1, i);

		//for (int j = 0; j < N; j++)
		///	printf ("%i ", prefixBalance[j]);
		//printf ("\n");
	}

	if (maxLength == 0)
		total = 1;

	printf ("%i %i\n", maxLength, total);

	return 0;
}