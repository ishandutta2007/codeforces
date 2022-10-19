#include<bits/stdc++.h>
using namespace std;
int n,edge_t=0,d;
int la[200002],siz[200002],son[200002],dep[200002],top[200002],bot[200002],fa[200002];
struct aaa
{
	int to,nx;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1,fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dep[v]=dep[x]+1,dfs(v,x),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[x]=t;
	if(son[x])dfs1(son[x],x,t),bot[x]=bot[son[x]];
	else bot[x]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0),dfs1(1,0,1),puts("d 1"),fflush(stdout),scanf("%d",&d);
	for(int i=1,x,y,z;;i=y)
	{
		if(i==(y=bot[i]))return 0&printf("! %d",i);
		z=dep[y],printf("d %d\n",y),fflush(stdout),scanf("%d",&x);
		for(int j=(x-d+z)/2;j;--j)y=fa[y];
		if(!(x+d-z))return 0&printf("! %d",y);
		printf("s %d\n",y),fflush(stdout),scanf("%d",&y);
	}
}