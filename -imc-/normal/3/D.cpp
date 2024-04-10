#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxN = 50005;
char theString[maxN];

const int infinity = 100000000;

struct SegmentTree
{
	int minIndex[maxN * 4];
	int array[maxN];
	int N;

	void init (int N_)
	{
		N = N_;
		for (int i = 0; i < N; i++)
			array[i] = infinity;
		build (0, 0, N - 1);
	}

	void build (int t, int l, int r)
	{
		minIndex[t] = l;
		if (l != r)
		{
			int m = (l + r) / 2;
			build (t * 2 + 1, l, m);
			build (t * 2 + 2, m + 1, r);
		}
	}

	int getMinIndex (int t, int l, int r, int x, int y)
	{
		if (x > r || y < l) return -1;
		if (l >= x && r <= y) return minIndex[t];

		int m = (l + r) / 2;
		int lm = getMinIndex (t * 2 + 1, l, m, x, y);
		int rm = getMinIndex (t * 2 + 2, m + 1, r, x, y);

		if (lm == -1) return rm;
		if (rm == -1) return lm;
		return (array[lm] < array[rm]) ? lm : rm;
	}

	void update (int cell, int newValue)
	{
		array[cell] = newValue;
		update (0, 0, N - 1, cell);
	}

	void update (int t, int l, int r, int cell)
	{
		if (l == r) return;

		int m = (l + r) / 2;
		if (cell <= m)
			update (t * 2 + 1, l, m, cell);
		else
			update (t * 2 + 2, m + 1, r, cell);

		if (array[minIndex[t * 2 + 1]] < array[minIndex[t * 2 + 2]])
			minIndex[t] = minIndex[t * 2 + 1];
		else
			minIndex[t] = minIndex[t * 2 + 2];
	}
};

SegmentTree minQuery;
int N;

int numOpen[maxN];

int querySum (int prefix)
{
	int answer = 0;
	while (prefix >= 0)
	{
		answer += numOpen[prefix];
		prefix = (prefix & (prefix + 1)) - 1;
	}
	return answer;
}

void increase (int cell)
{
	while (cell < N)
	{
		numOpen[cell]++;
		cell = cell | (cell + 1);
	}
}

struct Segtree
{
	int minimum[maxN * 4], add[maxN * 4];

	void intervalAdd (int t, int l, int r, int x, int y, int plus)
	{
		if (x > r || y < l) return;

		if (l >= x && r <= y)
		{
			add[t] += plus;
			return;
		}

		if (l == r)
		{
			minimum[t] += plus + add[t];
			add[t] = 0;
			return;
		}

		add[t * 2 + 1] += add[t];
		add[t * 2 + 2] += add[t];
		add[t] = 0;

		int m = (l + r) / 2;
		intervalAdd (t * 2 + 1, l, m, x, y, plus);
		intervalAdd (t * 2 + 2, m + 1, r, x, y, plus);
		minimum[t] = min (minimum[t * 2 + 1] + add[t * 2 + 1], minimum[t * 2 + 2] + add[t * 2 + 2]);
	}

	int getMin (int t, int l, int r, int x, int y)
	{
		if (x > r || y < l) return infinity;
		if (l >= x && r <= y) return minimum[t] + add[t];

		int m = (l + r) / 2;
		return min (getMin (t * 2 + 1, l, m, x, y), getMin (t * 2 + 2, m + 1, r, x, y)) + add[t];
	}
};

Segtree balanceSegtree;

int main()
{
	scanf ("%s", theString);
	N = strlen (theString);
	minQuery.init (N);
	long long answer = 0;
	int balance = 0;

	vector < pair <int, int> > possibleToClose; // cost - index

	for (int i = 0; i < N; i++)
	{
		if (theString[i] == '?')
		{
			int open, close;
			scanf ("%i %i", &open, &close);

			if (open <= close)
			{
				theString[i] = '(';
				balance++;
				answer += open;
				// close them later

				possibleToClose.push_back (make_pair (close - open, i));
			}
			else
			{
				theString[i] = ')';
				answer += close;
				balance--;
				minQuery.update (i, open - close);
			}
		}
		else
		{
			if (theString[i] == '(')
				balance++;
			else
				balance--;
		}

		if (balance < 0)
		{
			// open some brackets
			int best = minQuery.getMinIndex (0, 0, N - 1, 0, i);
			if (best == -1 || minQuery.array[best] == infinity) { printf ("-1\n"); return 0; }

			answer += minQuery.array[best];
			minQuery.update (best, infinity);
			assert (theString[best] == ')');
			theString[best] = '(';
			balance += 2;
		}

		//printf ("%s (balance %i)\n", theString, balance);
	}

	//printf ("%s (balance %i) final\n", theString, balance);

	balance = 0;
	for (int i = 0; i < N; i++)
	{
		if (theString[i] == '(')
			balance++;
		else
			balance--;

		balanceSegtree.intervalAdd (0, 0, N - 1, i, i, balance);
	}

	if (balance % 2 == 1) { printf ("-1\n"); return 0; }

	// close the rest of brackets
	sort (possibleToClose.begin(), possibleToClose.end());

	for (unsigned i = 0; i < possibleToClose.size() && balance > 0; i++)
	{
		int add = possibleToClose[i].first, index = possibleToClose[i].second;
		int before = balanceSegtree.getMin (0, 0, N - 1, index, N - 1) - 2;

		/*for (int t = 0; t < N; t++)
			printf ("%i ", balanceSegtree.getMin (0, 0, N - 1, t, t));
		printf ("\n");
		printf ("gmin %i\n", balanceSegtree.minimum[0] + balanceSegtree.add[0]);

		printf ("index %i after %i [%i, %i: %i]\n", index, before, index, N - 1, balanceSegtree.getMin (0, 0, N - 1, index, N - 1) );
		*/
		if (before >= 0)
		{
			answer += add;
			theString[index] = ')';
			balanceSegtree.intervalAdd (0, 0, N - 1, index, N - 1, -2);
			balance -= 2;
			//printf ("%s (balance %i)\n", theString, balance);
		}
	}

	if (balance != 0) { printf ("-1\n"); return 0; }

	printf ("%lld\n%s\n", answer, theString);

	return 0;
}