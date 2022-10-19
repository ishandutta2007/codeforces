#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=1,t=0;
bool ok=0;
int la[100002],col[100002],dep[100002],fa[100002];
LL c[100002];
struct aaa
{
	int to,nx;
	LL val;
	bool u;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0,0},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0,0},la[y]=edge_t;
}
inline void dfs(int x,int c)
{
	col[x]=c;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(col[v=edge[i].to]==col[x])return (void)(t=x,ok=1);
		if(!col[v])
		{
			dfs(v,-c);
			if(t)
			{
				if(ok)edge[i].u=edge[i^1].u=1;
				return ;
			}
		}
	}
}
inline void dfs1(int x,int d)
{
	dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].u && !dep[v=edge[i].to])fa[v]=x,dfs1(v,d+1),c[x]-=(edge[i].val=edge[i^1].val=c[v]);
	for(int i=la[x],v;i;i=edge[i].nx)if(!edge[i].u && !dep[v=edge[i].to])fa[v]=x,dfs1(v,d+1),c[x]-=(edge[i].val=edge[i^1].val=c[v]);
}
inline void print()
{
	puts("YES");
	for(int i=1;i<=m;++i)printf("%lld\n",edge[i<<1].val);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&c[i]);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,1),dfs1(t? t:1,1);
	if(!c[t? t:1])return print(),0;
	if(!t)return 0&puts("NO");
	c[t]>>=1;
	for(int i=la[t],v;i;i=edge[i].nx)
		if(dep[v=edge[i].to]&1)
		{
			for(edge[i].val+=c[t],edge[i^1].val+=c[t];fa[v];v=fa[v])
				for(int j=la[v];j;j=edge[j].nx)
					if(edge[j].to==fa[v])
					{
						c[t]=-c[t],edge[j].val+=c[t],edge[j^1].val+=c[t];
						break;
					}
			break;
		}
	return print(),0;
}