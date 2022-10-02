#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[200005],vis[200005],dfn[200005],dfnow,sz[200005];
vector<pair<int,int> > e[200005];
void add(int u,int v,int w)
{
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
int f[20][200005],dep[200005];
void dfs(int u,int fa)
{
	dfn[u]=++dfnow,sz[u]=1;
	dep[u]=dep[fa]+1,f[0][u]=fa;
	for(auto v:e[u])
		if(vis[v.second]&&v.first!=fa) dfs(v.first,u),sz[u]+=sz[v.first];
}
vector<pair<int,int> > B;
int cnt[200005];
bool check(int x,int y)
{
	if(sz[x]<sz[y]) swap(x,y);
	if(dfn[y]>=dfn[x]&&dfn[y]<dfn[x]+sz[x]) return 1;
	return 0;
}
int fir(int x,int y)
{
	int D=dep[y]-dep[x]-1;
	for(int i=18;i>=0;i--)
		if(D&(1<<i)) y=f[i][y];
	return y;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		if(ff(u)!=ff(v))
		{
			vis[i]=1;
			add(u,v,i);
			fa[ff(u)]=ff(v);
		}
		else B.push_back({u,v});
	}
	dfs(1,0);
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][f[i-1][j]];
	for(auto x:B)
	{
		if(!check(x.first,x.second))
		{
			++cnt[dfn[x.first]];
			++cnt[dfn[x.second]];
			--cnt[dfn[x.first]+sz[x.first]];
			--cnt[dfn[x.second]+sz[x.second]];
		}
		else
		{
			if(sz[x.first]<sz[x.second]) swap(x.first,x.second);
			++cnt[1];
			int X=fir(x.first,x.second);
			--cnt[dfn[X]];
			++cnt[dfn[X]+sz[X]];
			++cnt[dfn[x.second]];
			--cnt[dfn[x.second]+sz[x.second]];
		}
	}
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;i++)
	{
		cout << (cnt[dfn[i]]==B.size());
	}
	return 0;
}