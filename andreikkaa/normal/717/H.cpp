#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 50 * 1000 + 7;
vector<int> want[MAXN];
int color[MAXN];
int go[MAXN][22];
int res[MAXN];
int teamColor[1000 * 1000 + 228];
int golen[MAXN];
int u[2 * MAXN], v[2 * MAXN];
int perm[MAXN];
bool TL1()
{
	return 1.0 * clock() / CLOCKS_PER_SEC < 3.0;
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(228);
	int n, e;
	scanf("%d %d", &n, &e);
	vector<pair<int, int> > edges;
	for (int i = 1; i <= e; i++)
	{
		scanf("%d %d", &u[i], &v[i]);
	}
	bool ok = false;
	while (TL1())
	{
		for (int i = 1; i <= n; i++)
		{
			color[i] = (rand() & 1) + 1;
		}
		int cut = 0;
		for (int i = 1; i <= e; i++)
		{
			if (color[u[i]] != color[v[i]]) cut++;
		}
		if (cut >= (e + 1) / 2)
		{
			ok = true;
			break;
		}
	}
	assert(ok);
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &golen[i]);
		for (int j = 1; j <= golen[i]; j++)
		{
			scanf("%d", &go[i][j]);
			t = max(t, go[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		perm[i] = i;
	}
	while (1)
	{
		random_shuffle(perm + 1, perm + 1 + n);
		memset(teamColor, 0, sizeof(int) * (t + 5));
		bool OK = true;
		for (int ii = 1; ii <= n; ii++)
		{
			int i = perm[ii];
			if (!OK) break;
			res[i] = 0;
			for (int j = 1; j <= golen[i]; j++)
			{
				if (teamColor[go[i][j]] == color[i])
				{
					res[i] = go[i][j];
					break;
				}
			}
			if (res[i] != 0)
			{
				continue;
			}
			random_shuffle(go[i] + 1, go[i] + 1 + golen[i]);
			for (int j = 1; j <= golen[i]; j++)
			{
				if (teamColor[go[i][j]] == 0)
				{
					teamColor[go[i][j]] = color[i];
					res[i] = go[i][j];
					break;
				}
			}
			if (res[i] == 0)
			{
				OK = false;
				break;
			}
		}
		if (OK)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", res[i]);
			}
			printf("\n");
			for (int i = 1; i <= t; i++)
			{
				if (teamColor[i] == 0)
				{
					teamColor[i] = 1;
				}
				printf("%d ", teamColor[i]);
			}
			printf("\n");
			return 0;
		}
	}
}