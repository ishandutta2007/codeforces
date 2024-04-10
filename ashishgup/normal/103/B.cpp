#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, connected=0;
int vis[N];
vector<int> g[N];

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
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
		if(!vis[i])
		{
			dfs(i);
			connected++;
		}
	}
	if(n==m && connected==1)
		cout<<"FHTAGN!";
	else
		cout<<"NO";
	return 0;
}