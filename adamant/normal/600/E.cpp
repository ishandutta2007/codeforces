#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

map<int, int> cl[maxn];
int cn[maxn], d[maxn];
vector<int> g[maxn];

void dfs(int v = 0, int p = 0)
{
	for(auto u: g[v])
	{
		if(u == p)
			continue;
		dfs(u, v);
		if(cl[v].size() < cl[u].size())
		{
			swap(cl[v], cl[u]);
			cn[v] = cn[u];
			d[v] = d[u];
		}
		for(auto it: cl[u])
		{
			int a = it.first;
			int b = it.second;
			cl[v][a] += b;
			if(cl[v][a] == cn[v])
				d[v] += a;
			if(cl[v][a] > cn[v])
			{
				cn[v] = cl[v][a];
				d[v] = a;
			}
		}
		
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		d[i] = c;
		cn[i] = 1;
		cl[i][c] = 1;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs();
	for(int i = 0; i < n; i++)
		cout << d[i] << " \n"[i == n - 1];
    return 0;
}