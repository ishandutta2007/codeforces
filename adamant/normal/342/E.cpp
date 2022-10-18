#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42, logn = 18;
vector<int> g[maxn];
int in[maxn], out[maxn];
int up[maxn][logn];
int lvl[maxn];
int t;

void dfs(int v = 0, int p = 0)
{
	in[v] = ++t;
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;
	for(int i = 1; i < logn; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(auto u: g[v])
		if(u != p)
			dfs(u, v);
	out[v] = t;
}

int is_par(int a, int b)
{
	return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b)
{
	for(int i = logn - 1; i >= 0; i--)
		if(!is_par(up[a][i], b))
			a = up[a][i];
	if(!is_par(a, b))
		a = up[a][0];
	return a;
}

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs();
	vector<int> red = {0};
	int root = 300;
	for(int i = 0; i < m; i += root)
	{
		int dist[n];
		fill(dist, dist + n, n);
		int que[n];
		int st = 0, fi = 0;
		for(auto it: red)
		{
			que[fi++] = it;
			dist[it] = 0;
			
		}
		while(st < fi)
		{
			int v = que[st++];
			for(auto u: g[v])
				if(dist[v] + 1 < dist[u])
				{
					dist[u] = dist[v] + 1;
					que[fi++] = u;
				}
		}
		vector<int> cur;
		for(int j = 0; j < root && i + j < m; j++)
		{
			int t, v;
			cin >> t >> v;
			v--;
			if(t == 1)
			{
				cur.push_back(v);
			}
			else
			{
				int ans = dist[v];
				for(auto it: cur)
					ans = min(ans, lvl[v] + lvl[it] - 2 * lvl[lca(v, it)]);
				cout << ans << "\n";
			}
		}
		for(auto it: cur)
			red.push_back(it);
	}
}