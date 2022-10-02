#include <bits/stdc++.h>
using namespace std;
vector <int> e[500005],E[500005];
int a[500005],ans[500005],sz[500005],fa[500005];
inline void dfs(int u,int f)
{
	sz[u]=a[u],fa[u]=f;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dfs(v,u),sz[u]+=sz[v];
	}
}
queue <int> q;
int vis[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			++sum;
			ans[i]=1;
			for(auto v:e[i])
				ans[v]=1;
		}
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		for(auto v:e[i])
		{
			if(v!=fa[i])
			{
				if(sz[v]>=2)
					E[v].push_back(i);
			}
		}
		if(sum-sz[i]>=2)
		{
			E[fa[i]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto v:E[x])
		{
			if(!ans[v])
			{
				ans[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout << ans[i] << " ";
	return 0;
}