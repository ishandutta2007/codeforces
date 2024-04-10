#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, nodes, edges, ans=0;
bool vis[N];
vector<int> g[N];

void dfs(int k)
{	
	if(vis[k])
		return;
	vis[k]=1;
	nodes++;
	edges+=g[k].size();
	for(auto it:g[k])
		dfs(it);
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
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		nodes=0, edges=0;
		dfs(i);
		edges/=2;
		ans+=(edges<nodes);
	}
	cout<<ans;
	return 0;
}