#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef unsigned int u32;
#define pb push_back
const int maxn = 400005;

int n,m,par[maxn][20],mx[maxn][20],dep[maxn],ot[maxn];
vector<int> adj[maxn];bool mst[maxn];
struct edge {
	int u,v,w,id;
}edg[maxn];
bool comp(edge a,edge b) {return a.w<b.w;}
bool compid(edge a,edge b) {return a.id<b.id;}
void add(int u,int v) {
	adj[u].pb(v);adj[v].pb(u);
}
int p[maxn];
int findp(int u) {
	return p[u]?p[u]=findp(p[u]):u;
}

void dfs1(int u)
{
	int v;
	for (u32 j=0;j<adj[u].size();j++)
	if ((v=adj[u][j])!=par[u][0])
		par[v][0]=u,dep[v]=dep[u]+1,dfs1(v);
}
void sparse_table()
{
	for (int j=1;j<20;j++)
	for (int i=1;i<=n;i++)
		par[i][j]=par[par[i][j-1]][j-1],
		mx[i][j]=max(mx[i][j-1],mx[par[i][j-1]][j-1]);
}
int lca(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	for (int d=dep[u]-dep[v],j=0;d;d>>=1,++j)
		if (d&1) u=par[u][j];
	if (u==v) return u;
	for (int j=19;j>=0;j--)
	if (par[u][j]!=par[v][j])
		u=par[u][j],v=par[v][j];
	return par[u][0];
}
int query(int u,int v)
{
	int res=0;
	for (int d=dep[u]-dep[v],j=0;d;d>>=1,++j)
		if (d&1) res=max(res,mx[u][j]),u=par[u][j];
	return res;
}
void merge(int u,int v) {
	u=findp(u);v=findp(v);
	if (dep[u]>dep[v]) swap(u,v);
	if (u!=v) p[v]=u;
}
void work(int u,int v,int w)
{
	for (int x=ot[u]?par[findp(u)][0]:u;dep[x]>dep[v];) {
		if (!ot[x]) ot[x]=w;merge(x,u);x=par[x][0];
		if (ot[x]) {merge(x,u);x=par[findp(x)][0];}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("weight.in","r",stdin);
		//freopen("weight.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int u,v,c,i=1;i<=m;i++)
		scanf("%d %d %d",&u,&v,&c),edg[i]=(edge){u,v,c,i};
	sort(edg+1,edg+m+1,comp);
	for (int i=1;i<=m;i++)
	{
		int u=edg[i].u,v=edg[i].v;
		if (findp(u)!=findp(v)) {
			p[findp(u)]=findp(v);
			mst[edg[i].id]=true;
			add(u,v);
		}
	}
	dfs1(1);memset(p,0,n+1<<2);
	for (int i=1;i<=m;i++)
	if (mst[edg[i].id]) {
		int u=edg[i].u,v=edg[i].v;
		if (dep[u]<dep[v]) swap(u,v);
		mx[u][0]=edg[i].w;
	}
	sparse_table();
	
	for (int i=1;i<=m;i++)
	if (!mst[edg[i].id]) {
		int u=edg[i].u,v=edg[i].v;
		int t=lca(u,v);
		work(u,t,edg[i].w);
		work(v,t,edg[i].w);
	}
	
	sort(edg+1,edg+m+1,compid);
	for (int i=1;i<=m;i++)
	if (mst[i]) {
		int u=edg[i].u,v=edg[i].v;
		if (dep[u]<dep[v]) swap(u,v);
		if (!ot[u]) printf("-1 ");
		else printf("%d ",ot[u]-1);
	}
	else {
		int u=edg[i].u,v=edg[i].v;
		int t=lca(u,v);
		int res=max(query(u,t),query(v,t));
		printf("%d ",res-1);
	}
	return 0;
}