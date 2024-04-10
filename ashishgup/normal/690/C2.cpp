#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, node=1, dist=0;
vector<int> g[N];

void dfs(int k, int lvl, int par)
{
	if(lvl>dist)
	{
		dist=lvl;
		node=k;
	}
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, lvl+1, k);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 1);
	dfs(node, 0, node);
	cout<<dist;
	return 0;
}