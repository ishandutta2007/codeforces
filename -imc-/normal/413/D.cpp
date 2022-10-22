#include <cstdio>
#include <vector>

using namespace std;

void add(int& x, int v)
{
	x = (x + v) % 1000000007;
}

void solve()
{


	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int nMasks = 1 << k;
	vector<int> nWays(nMasks), next(nMasks);

	for (int i = 0; i < n; i++)
	{
		nWays = next;
		next.assign(nMasks, 0);
		if (i == 0)
			nWays[0] = 1;

		for (int mask = 0; mask < nMasks; mask++)
		{
			if (!nWays[mask]) continue;
			int now = nWays[mask];
			//printf("nWays[%d items][mask %d] is %d\n", i + 1, mask, now);

			for (int current = 0; current <= 1; current++)
			{
				if (a[i] != 0 && current * 2 + 2 != a[i]) continue;

				int newMask = mask;
				if (!(newMask & (1 << (k - 1))))
				{
					if (current == 1 && (newMask & 1))
					{
						newMask = 2;
					}
					else
					{
						for (int i = current; i < k; i++)
						{
							if (i == k - 1 || !(newMask & (1 << i)))
							{
								newMask |= (1 << i);
								break;
							}
							newMask &= ~(1 << i);
						}
					}
				}

				add(next[newMask], now);
			}
		}
	}

	int answer = 0;
	for (int mask = 0; mask < nMasks; mask++)
		if (mask & (1 << (k - 1)))
			add(answer, next[mask]);

	printf("%d\n", answer);
}

int main()
{
#ifdef LOCAL
	freopen("d.in", "r", stdin);
	for (int i = 0; i < 5; i++)
#endif
	solve();

	return 0;
}