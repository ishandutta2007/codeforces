#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],deg[200005],cnt,ANS[200005],vis[200005],fa[200005];
pair <int,int> b[200005];
vector <int> e[200005];
inline void dfs(int u,int f)
{
	fa[u]=f;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dfs(v,u);
	}
}
inline void Add(int x,int y)
{
	cnt-=deg[x]==1,cnt-=deg[y]==1;
	++deg[x],++deg[y];
	cnt+=deg[x]==1,cnt+=deg[y]==1;
}
inline void ins(int x)
{
	while(!vis[x])
	{
		vis[x]=1,Add(x,fa[x]);
		x=fa[x];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]={a[i],i};
	}
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int r=b[n].second;
	dfs(r,0);
	vis[r]=1;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		ins(b[i].second);
		ANS[i]=max(2ll,cnt);
		ans+=(ANS[i]-ANS[i+1])*b[i].first;
	}
	cout << ans;
	return 0;
}