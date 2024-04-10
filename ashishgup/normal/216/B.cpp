#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, ct=0;
int vis[N], col[N];
vector<int> g[N];
vector<pair<int, int> > v;

void dfs(int k, int c)
{
	if(vis[k]&&col[k]!=c)
	{
		ct++;
		return;
	}
	if(vis[k])
		return;
	vis[k]=1;
	col[k]=c;
	for(auto &it:g[k])
		dfs(it, c^1);
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
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		ct=0;
		dfs(i, 0);
		ans+=ct/2;
	}
	int rem=n-ans;
	if(rem%2)
		ans++;
	cout<<ans;
	return 0;
}