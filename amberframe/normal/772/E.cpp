#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
const int maxn = 2005;
#define pb push_back
vector<int> adj[maxn],leaf,son;

int query(int x,int y,int z)
{
	printf("%d %d %d\n",x,y,z);fflush(stdout);
	char op[5];scanf("%s",op);
	return (*op=='X')?2:(*op=='Y');
}
int siz[maxn],cnt[maxn],vis[maxn],rt,sum;
int n,tot,par[maxn],now,o;

void dfs1(int u,int fa)
{
	siz[u]=1;cnt[u]=0;
	int _siz=adj[u].size();
	for (int v,j=0;j<_siz;j++)
	if ((v=adj[u][j])!=fa&&!vis[v])
		dfs1(v,u),siz[u]+=siz[v],cnt[u]=max(cnt[u],siz[v]);
}
void dfs2(int u,int fa)
{
	int _siz=adj[u].size();
	for (int v,j=0;j<_siz;j++)
		if ((v=adj[u][j])!=fa&&!vis[v]) dfs2(v,u);
	cnt[u]=max(cnt[u],sum-siz[u]);
	if (cnt[u]<cnt[o]||(cnt[u]==cnt[o]&&u>o)) o=u;
}
int getleaf(int u,int fa) 
{
	int _siz=adj[u].size();int res=u;
	for (int v,j=0;j<_siz;j++)
	if ((v=adj[u][j])!=fa)
		res=min(res,getleaf(v,u));
	return res;
}
void solve(int u)
{
	int _=u;cnt[o=0]=1<<30;dfs1(u,0);
	sum=siz[u];dfs2(u,0);u=o;
	leaf.clear();son.clear();vis[u]=true;
	int _siz=adj[u].size();
	for (int v,j=0;j<_siz;j++)
	if ((v=adj[u][j])!=par[u])
		son.pb(v),leaf.pb(getleaf(v,u));
	if (!son.size()) {par[++tot]=par[u];par[u]=par[now]=tot;return ;}
	int d=query(leaf[0],leaf[1],now);
	if (d==2) {
		if (u!=_) solve(_);
		else par[++tot]=par[u],par[u]=par[now]=tot;
	}
	else if (vis[son[d]]) par[++tot]=u,par[son[d]]=par[now]=tot;
	else solve(son[d]);
}
int main()
{
	scanf("%d",&n);tot=n;rt=1;
	for (now=2;now<=n;now++)
	{
		memset(vis,0,sizeof vis);
		for (int i=1;i<=tot;i++) adj[i].clear();
		for (int i=1;i<=tot;i++)
		if (int u=par[i]) adj[u].pb(i),adj[i].pb(u);
		while (par[rt]) rt=par[rt];
		solve(rt);
	}
	puts("-1");
	for (int i=1;i<=n*2-1;i++)
		printf("%d ",par[i]?par[i]:-1);
	return 0;
}