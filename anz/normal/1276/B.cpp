#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, a, b;
vector <int> graph[200001];

int root = 0;
int rootDeg = 0;
int dfs_cnt = 0;
int dfs_par[200001];
int dfs_num[200001];
int dfs_low[200001];
bool isPoint[200001];

void DFS(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_cnt++;
	for (auto v : graph[u])
	{
		if (dfs_num[v] == -1)
		{
			dfs_par[v] = u;
			if (u == root) rootDeg++;
			
			DFS(v);
			if (dfs_low[v] >= dfs_num[u])
				isPoint[u] = true;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_par[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int sz[200001];
int cache[200001];
bool DFS2(int s, int p)
{
	bool res = false;
	cache[s] = 1;
	sz[s] = 0;
	for (auto v : graph[s])
	{
		if (v == p) res = true;
		if (cache[v]) continue;
		if (DFS2(v, p)) res = true;
		sz[s] += sz[v] + 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; i++)
		{
			root = 0;
			rootDeg = 0;
			dfs_cnt = 0;
			dfs_par[i] = dfs_num[i] = dfs_low[i] = -1;
			isPoint[i] = 0;
			graph[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		root = a;
		DFS(a);
		if (rootDeg > 1 && isPoint[b])
		{
			ll ansa = 0, ansb = 0;

			for (int i = 1; i <= n; i++) cache[i] = 0;
			cache[a] = 1, cache[b] = 1;

			for (auto v : graph[a])
			{
				if (cache[v]) continue;
				if(DFS2(v, b)) continue;
				ansa += sz[v] + 1;
			}

			for (auto v : graph[b])
			{
				if (cache[v]) continue;
				if (DFS2(v, a)) continue;
				ansb += sz[v] + 1;
			}

			cout << ansa * ansb << '\n';
		}
		else
		{
			cout << "0\n";
		}
	}
}