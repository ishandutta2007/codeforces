#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,edge_t=0,G,tot,ans;
long double ans1=inf;
int a[200002],la[200002],siz[200002],mx[200002];
bool u[200002];
long double sum[200002],sum1[200002],sum2[200002];
struct aaa
{
	int to,nx,val;
}edge[400002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && !u[v])
			dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],tot-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && !u[v])
			dfs1(v,x);
}
inline void dfs2(int x,int f,LL d)
{
	sum[x]=pow(d,1.5)*a[x],sum1[x]=pow(d+1,1.5)*a[x],sum2[x]=pow(d-1,1.5)*a[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs2(v,x,d+edge[i].val),sum[x]+=sum[v],sum1[x]+=sum1[v],sum2[x]+=sum2[v];
}
inline void solve(int x)
{
	long double res=0;
	dfs(x,0),tot=siz[x],dfs1(G=x,0),u[G]=1,dfs2(G,0,0);
	if(sum[G]<ans1)ans1=sum[ans=G];
	for(int i=la[G],v;i;i=edge[i].nx)if(!u[v=edge[i].to])res+=sum1[v];
	for(int i=la[G],v;i;i=edge[i].nx)if(!u[v=edge[i].to] && res-sum1[v]+sum2[v]<sum[G])return solve(v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	solve(1),printf("%d %.10Lf",ans,ans1);
	return 0;
}