#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n, m, src, dest, val;
int mn[N];
vector<pair<int, int> > g[N];

struct data
{
	int a, b, g;
};

data store[N];

bool dfs(int u, int par)
{
	if(u == dest)
		return 1;
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		if(dfs(it.first, u))
		{
			mn[it.second] = max(mn[it.second], val);
			return 1;
		}
	}
	return 0;
}

bool dfs2(int u, int par, int cur)
{
	if(u == dest)
		return (cur == val);
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		if(dfs2(it.first, u, min(cur, mn[it.second])))
			return 1;
	}
	return 0;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		mn[i] = 1;
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> store[i].a >> store[i].b >> store[i].g;
		src = store[i].a;
		dest = store[i].b;
		val = store[i].g;
		dfs(src, src);
	}
	for(int i = 1; i <= m; i++)
	{
		src = store[i].a;
		dest = store[i].b;
		val = store[i].g;
		if(!dfs2(src, src, 1e9))
		{
			cout << -1;
			return 0;
		}
	}
	for(int i = 1; i <= n - 1; i++)
		cout << mn[i] << " ";
	return 0;
}