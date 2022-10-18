#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;

int n;
int color[maxn];
int g[maxn][maxn];
int used[maxn];

void fail()
{
	cout << "No\n";
	exit(0);
}

void dfs(int v)
{
	if(used[v] == 1)
		return;
	used[v] = 1;
	if(color[v] == 0)
		color[v] = 3;
	for(auto u = 0; u < n; u++)
	{
		if(u == v || g[v][u] == 1)
			continue;
		if(color[u] == 0)
			color[u] = color[v] ^ 1;
		else if(color[u] != (color[v] ^ 1))
			fail();
		dfs(u);
	}
	
}

signed main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u][v] = g[v][u] = 1;
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	for(int i = 0; i < n; i++)
		if(accumulate(g[i], g[i] + n, 0) == n - 1)
			color[i] = 4;
	for(int i = 0; i < n; i++)
	{
		if(color[i] == 2)
			color[i] = 0;
		else if(color[i] == 3)
			color[i] = 2;
		else if(color[i] == 4)
			color[i] = 1;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] && abs(color[i] - color[j]) > 1)
				fail();
		}
	cout << "Yes\n";
	for(int i = 0; i < n; i++)
		cout << char('a' + color[i]);
	cout << "\n";
	return 0;
}