#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, a, b, da, db;
vector<int> g[N];
int dist, node, origdist;

void dfs(int u, int par, int d)
{
	if(d > dist)
	{
		dist = d;
		node = u;
	}
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, d + 1);
	}
}

void dfs2(int u, int par, int d)
{
	if(u == b)
		origdist = d;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs2(it, u, d + 1);
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)	
	{
		cin >> n >> a >> b >> da >> db;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dist = -1;
		dfs(1, 1, 0);
		dist = -1;
		dfs(node, node, 0);
		db = min(dist, db);
		dfs2(a, a, 0);
		if(db > 2 * da && origdist > da)
			cout << "Bob" << endl;
		else
			cout << "Alice" << endl;
	}
	return 0;
}