#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

void dumb (int n)
{
	vector <int> perm, best;

	for (int i = 0; i <= n; i++)
		perm.push_back (i);

	int bestAnswer = -1;

	do
	{
		int answer = 0;
		for (int i = 0; i <= n; i++)
			answer += i ^ perm[i];
		if (answer > bestAnswer)
		{
			bestAnswer = answer;
			best = perm;
		}
	}
	while (next_permutation (perm.begin(), perm.end()));

	printf ("n=%i:\n", n);
	printf ("%i\n", bestAnswer);

	perm.clear();
	for (int i = 0; i <= n; i++)
		perm.push_back (i);
	do
	{
		int answer = 0;
		for (int i = 0; i <= n; i++)
			answer += i ^ perm[i];
		if (answer == bestAnswer)
		{
			for (unsigned i = 0; i < perm.size(); i++)
				printf ("%i [%i] ", perm[i], perm[i] ^ i);
			printf ("\n");
		}
	}
	while (next_permutation (perm.begin(), perm.end()));
	printf ("\n");
}

vector <int> t;

void goBlessedx (int n)
{
	if (n < 0) return;

	if (n == 0)
	{
		t[0] = 0;
		return;
	}

	if (n == 1)
	{
		t[0] = 1;
		t[1] = 0;
		return;
	}

	int k = 1;
	while (k <= n) k *= 2;

	//printf ("blessed: n=%i, k=%i\n", n, k);

	int from = -1;

	for (int i = 0; i <= n; i++)
		if (k - i - 1 <= n)
		{
			if (from == -1) from = i;
			t[i] = n - (i - from);
		}
		else assert (from == -1);

	goBlessedx (from - 1);
}

void goBlessed (int n)
{
	t.resize (n + 1);
	goBlessedx (n);
	for (int i = 0; i <= n; i++)
		printf ("%i ", t[i]);
	printf ("\n");
}

int main()
{
	int n;
	scanf ("%i", &n);

	printf ("%I64d\n", ((long long)n) * (n + 1));
	goBlessed (n);
	return 0;

	for (int i = 1; i <= n; i++)
		dumb (i);

	goBlessed (7);
	goBlessed (6);
	goBlessed (3);
	goBlessed (2);
	goBlessed (5);

	return 0;
}