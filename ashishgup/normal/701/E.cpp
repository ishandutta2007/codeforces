#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, nodes, ans=0;
int mark[N], subtree[N];
vector<int> g[N];

void dfs(int k, int par)
{
	subtree[k]=mark[k];
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
	ans+=min(subtree[k], 2*nodes-subtree[k]);
}

int32_t main()
{
	IOS;
	cin>>n>>nodes;
	for(int i=1;i<=2*nodes;i++)
	{
		int u;
		cin>>u;
		mark[u]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout<<ans;
	return 0;
}