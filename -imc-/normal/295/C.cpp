#include <cstdio>

const int module = 1000000007;

const int maxN = 55;
long long numWays[maxN * 4][maxN][maxN];
long long select[maxN][maxN];

int main()
{
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				select[i][j] = 1;
			else
				select[i][j] = (select[i - 1][j] + select[i - 1][j - 1]) % module;
		}

	int n, k;
	scanf ("%i %i", &n, &k);
	k /= 50;

	int beginOne = 0, beginTwo = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf ("%i", &x);
		if (x == 50)
			beginOne++;
		else
			beginTwo++;
	}

	numWays[0][0][0] = 1;
	for (int i = 1; i <= 4 * n + 5; i++)
	{
		//printf ("Step %i:\n", i);
		for (int f = 0; f <= beginOne; f++)
			for (int s = 0; s <= beginTwo; s++)
			{
				if (!numWays[i - 1][f][s]) continue;

				int limitf = (i % 2 == 1) ? beginOne - f : f;
				int limits = (i % 2 == 1) ? beginTwo - s : s;
				int sign = i % 2 == 1 ? 1 : -1;

				for (int tf = 0; tf <= limitf; tf++)
					for (int ts = 0; ts <= limits; ts++)
					{
						if (!tf && !ts) continue;
						if (f + tf * sign < 0) break;
						if (s + ts * sign < 0) break;
						if (tf + 2 * ts > k) break;
						long long delta = (((numWays[i - 1][f][s] * select[limitf][tf]) % module) * select[limits][ts]);

						//printf ("move %i(/%i) %i(/%i) => +%lld ways to reach %i %i (from %lld: %i %i)\n", tf, limitf, ts, limits, delta, f + tf * sign, s + ts * sign, numWays[i - 1][f][s], f, s);
						numWays[i][f + tf * sign][s + ts * sign] += delta;
						numWays[i][f + tf * sign][s + ts * sign] %= module;
					}
			}
		//printf ("\n");

		if (numWays[i][beginOne][beginTwo])
		{
			printf ("%i\n%lld\n", i, numWays[i][beginOne][beginTwo]);
			return 0;
		}
	}

	printf ("-1\n0\n");

	return 0;
}