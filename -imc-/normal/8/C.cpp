#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

const int maxN = 40;
const int maxDistance = 1000000000;

int n;

int px[maxN], py[maxN];
int length[maxN][maxN];

int sqr (int a) { return a * a; }

const int maxStates = 1 << 24;
int answer[maxStates];
int previous[maxStates];

int getAnswer (int bitmask, int nbThen)
{
	if (nbThen <= 0)
		return maxDistance;

	int& ans = answer[bitmask], &prev = previous[bitmask];
	if (ans == -1)
	{
		ans = maxDistance;

		for (int firstp = 1; firstp <= n; firstp++)
		{
			if (!(bitmask & (1<<(firstp - 1)))) continue;
			int patched = bitmask & ~(1<<(firstp - 1));

			int candidate = getAnswer (patched, ans - 2 * length[0][firstp]) + 2 * length[0][firstp];
			if (candidate < ans)
			{
				ans = candidate;
				prev = patched;
			}

			for (int secondp = 1; secondp <= n; secondp++)
			{
				if (!(patched & (1<<(secondp - 1)))) continue;
				int xpatched = patched & ~(1<<(secondp - 1));

				candidate = getAnswer (xpatched, ans - (length[0][firstp] + length[firstp][secondp] + length[secondp][0])) + length[0][firstp] + length[firstp][secondp] + length[secondp][0];
				if (candidate < ans)
				{
					ans = candidate;
					prev = xpatched;
				}
			}
			break;
		}

		if (ans >= maxDistance)
		{
			ans = -1;
			return maxDistance;
		}

		//assert (ans != maxDistance);
	}

	return ans;
}

int main()
{
	scanf ("%i %i", &px[0], &py[0]);
	scanf ("%i", &n);

	for (int i = 1; i <= n; i++)
		scanf ("%i %i", &px[i], &py[i]);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			length[i][j] = sqr (px[i] - px[j]) + sqr (py[i] - py[j]);

	for (int j = 0; j < maxStates; j++)
		answer[j] = -1;

	answer[0] = 0;
	previous[0] = -1;

	getAnswer ((1 << n) - 1, maxDistance);

	int currentMask = (1 << n) - 1;
	printf ("%i\n", answer[currentMask]);

	printf ("0 ");
	while (true)
	{
		int next = previous[currentMask];
		if (next == -1) break;

		vector <int> inter;
		for (int i = 0; i < n; i++)
			if ((next & (1<<i)) != (currentMask & (1<<i)))
				inter.push_back (i);

		for (unsigned i = 0; i < inter.size(); i++)
			printf ("%i ", inter[i] + 1);
		printf ("0 ");

		currentMask = next;
	}
	printf ("\n");

	return 0;
}