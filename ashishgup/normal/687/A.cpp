#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int vis[N], color[N];
vector<int> g[N], ans[2];

void dfs(int k, int col)
{
	if(vis[k])
	{
		if(color[k]!=col)
		{
			cout<<"-1";
			exit(0);
		}
		return;
	}
	vis[k]=1;
	color[k]=col;
	ans[col].push_back(k);
	for(auto it:g[k])
		dfs(it, col^1);
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
		if(!vis[i])
			dfs(i, 0);
	}
	for(int i=0;i<=1;i++)
	{
		cout<<ans[i].size()<<endl;
		for(auto it:ans[i])
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}