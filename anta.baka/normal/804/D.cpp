#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m, q;
int sz[100000], par[100000];
map<pair<int,int>, long double> ans;
int f[100000], d[100000];
vector<bool> was;
vector<int> pf[100000], sf[100000];
vector<int> comp[100000];
int D[100000];
vector<int> ssum[100000];
vector<int> g[100000];

int find(int v)
{
	return (par[v] == v ? v : par[v] = find(par[v]));
}

void unite(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u != v)
	{
		if(sz[u] < sz[v]) swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}
}

void dfs1(int v, int p)
{
	was[v] = true;
	int s = g[v].size();
	for(int i = 0; i < s; i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			g[v].erase(g[v].begin() + i);
			i--; s--;
			continue;
		}
		dfs1(to, v);
		f[v] = max(f[v], f[to] + 1);
	}
	if(!s) return;
	pf[v].resize(s);
	sf[v].resize(s);
	pf[v][0] = f[g[v][0]] + 1;
	sf[v][s - 1] = f[g[v][s - 1]] + 1;
	for(int i = 1; i < s; i++) pf[v][i] = max(pf[v][i - 1], f[g[v][i]] + 1);
	for(int i = s - 2; i >= 0; i--) sf[v][i] = max(sf[v][i + 1], f[g[v][i]] + 1);
}

void dfs2(int v, int up)
{
	int s = g[v].size();
	for(int i = 0; i < s; i++)
	{
		int up1 = up;
		if(i) up1 = max(up1, pf[v][i - 1]);
		if(i < s - 1) up1 = max(up1, sf[v][i + 1]);
		up1++;
		int to = g[v][i];
		d[to] = max(f[to], up1);
		dfs2(to, up1);
	}
}

main()
{
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		unite(u, v);
	}
	was.assign(n, false);
	for(int i = 0; i < n; i++)
	{
		if(was[i]) continue;
		dfs1(i, -1);
		d[i] = f[i];
		dfs2(i, 0);
	}
	for(int i = 0; i < n; i++)
	{
		int v = find(i);
		comp[v].push_back(d[i]);
		D[v] = max(D[v], d[i]);
	}
	for(int i = 0; i < n; i++)
		if(!comp[i].empty())
		{
			sort(comp[i].begin(), comp[i].end());
			int s = comp[i].size();
			ssum[i].resize(s);
			ssum[i][s - 1] = comp[i][s - 1];
			for(int j = s - 2; j >= 0; j--) ssum[i][j] = ssum[i][j + 1] + comp[i][j];
		}
	cout.precision(12);
	for(int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		u = find(u);
		v = find(v);
		if(u == v) { cout << -1 << '\n'; continue; }
		if(sz[u] > sz[v]) swap(u, v);
		if(ans.count({u, v})) { cout << ans[{u, v}] << '\n'; continue; }
		int sm = 0;
		int x = max(D[u], D[v]);
		for(int w : comp[u])
		{
			int y = x - w - 1;
			if(comp[v][0] >= y)
			{
				sm += sz[v] * (w + 1) + ssum[v][0];
			}
			else
			{
				int bl = 0, br = sz[v] - 1;
				while(bl < br)
				{
					int bm = (bl + br) / 2;
					if(bl == bm) bm++;
					if(comp[v][bm] < y) bl = bm;
					else br = bm - 1;
				}
				sm += x * (bl + 1) + (sz[v] - bl - 1) * (w + 1) + (bl < sz[v] - 1 ? ssum[v][bl + 1] : 0);
			}
		}
		cout << fixed << (ans[{u, v}] = (long double)sm / sz[u] / sz[v]) << '\n';
	}
}