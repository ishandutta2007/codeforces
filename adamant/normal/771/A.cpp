#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5;
vector<int> g[maxn];
int used[maxn];

void dfs(int v, vector<int> &st)
{
	if(used[v])
		return;
	used[v] = 1;
	for(auto u: g[v])
		dfs(u, st);
	st.push_back(v);
}

void fail()
{
	cout << "NO" << endl;
	exit(0);
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(used[i])
			continue;
		vector<int> t;
		dfs(i, t);
		for(auto it: t)
			if(g[it].size() != t.size() - 1)
				fail();
	}
	cout << "YES" << endl;
}