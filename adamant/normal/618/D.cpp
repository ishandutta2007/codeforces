// Moscow IPT Hello
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 2e5;
int ma[maxn][2];
vector<int> g[maxn];

void dfs(int v = 0, int p = 0)
{
	for(auto u: g[v])
		if(u != p)
			dfs(u, v);
	ma[v][1] = 1;
	if(g[v].empty())
		return;
	int mx = -1;
	for(auto u: g[v])
	{
		if(u == p)
			continue;
		ma[v][1] += ma[u][0];
		ma[v][0] += ma[u][0];
		mx = max(mx, ma[u][1] - ma[u][0]);
	}
	if(mx > 0)
		ma[v][1] += mx;
	if(g[v].size() < 2)
	{
		if(mx > 0)
			ma[v][0] += mx;
		return;
	}
	int mx1 = -1, mx2 = -1;
	for(auto u: g[v])
	{
		if(ma[u][1] - ma[u][0] >= mx1)
		{
			mx2 = mx1;
			mx1 = ma[u][1] - ma[u][0];
		}
		else if(ma[u][1] - ma[u][0] > mx2)
			mx2 = ma[u][1] - ma[u][0];
	}
	mx = max(mx, mx1 + mx2);
	if(mx > 0)
		ma[v][0] += mx;
}


signed main()
{
	#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	#endif
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	dfs();
	if(x < y)
		cout << (n - 1) * y + (x - y) * ma[0][0] << "\n";
	else
	{
		for(int i = 0; i < n; i++)
		{
			if((int)g[i].size() == n - 1)
			{
				cout << (n - 1) * y + (x - y) << "\n";
				return 0;
			}
		}
		cout << (n - 1) * y << "\n";
	}
	return 0;
}