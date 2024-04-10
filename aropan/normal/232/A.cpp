#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 101;

int a[MAXN];
int n, m;
int k;
bool e[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d", &k);

	m = n = 0;
	for (int i = 100; i >= 3; i--)
		while (i + n <= 100 && i * (i - 1) * (i - 2) / 6 <= k)
		{
			k -= i * (i - 1) * (i - 2) / 6;
			a[m++] = i;
			n += i;
		}
	
	memset(e, 0, sizeof(e));
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < a[i]; j++)
			for (int k = 0; k < a[i]; k++)
				if (k != j)
					e[s + j][s + k] = true;
		s += a[i];
	}
	
	while (k)
	{
		vector < pair < pair <int, int>, int > > f;
		vector < pair < pair <int, int>, int > > g;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				int c = 0;
				for (int l = 0; l < n; l++)
					c += e[i][l] && e[j][l];

				if (e[i][j] && (k >= 0 || -k >= c))
					g.push_back(make_pair(make_pair(i, j), c));
				if (!e[i][j] && (k < 0 || c <= k))
					f.push_back(make_pair(make_pair(i, j), c));
			}

		if ((k < 0 && g.size()) || (int)f.size() == 0)
		{
			int t = rand() % g.size();
			int x = g[t].first.first;
			int y = g[t].first.second;
			e[x][y] = e[y][x] = false;
			k += g[t].second;
		}
		else
		{
			int t = rand() % f.size();
			int x = f[t].first.first;
			int y = f[t].first.second;
			e[x][y] = e[y][x] = true;
			k -= f[t].second;
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++, printf("\n"))
		for (int j = 0; j < n; j++)
			printf("%d", e[i][j]);
	return 0;
}