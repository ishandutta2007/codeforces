#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,edge_t=0,rt=1;LL ans=0;
int h[200002],la[200002]={},deg[200002],mx[200002],son[200002],son1[200002];
struct aaa
{
	int to,nx;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int f)
{
	mx[x]=h[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x),mx[x]=max(mx[x],mx[v]);
			if(mx[son[x]]<mx[v])son1[x]=son[x],son[x]=v;
			else if(mx[son1[x]]<mx[v])son1[x]=v;
		}
	if(x!=rt)son1[x]=0;
}
inline void dfs1(int x,int f,int z)
{
	if(son[x])dfs1(son[x],x,max(z,h[son[x]]));
	if(son1[x])dfs1(son1[x],x,max(z,h[son1[x]]));
	if(deg[x]==1)ans+=z/*,printf("  %d %lld\n",x,ans)*/;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x] && v!=son1[x])
			dfs1(v,x,h[v]);
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(h[i]);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	for(int i=2;i<=n;++i)if(h[i]>h[rt])rt=i;
	dfs(rt,0);
	//printf("rt=%d\n",rt);
	//for(int i=1;i<=n;++i)printf("%d:(%d,%d)\n",i,son[i],son1[i]);
	dfs1(rt,0,h[rt]);
	return 0&printf("%lld",ans);
}