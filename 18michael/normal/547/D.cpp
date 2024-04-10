#include<cstdio>
#define Mx 200001
int n,edge_t=1,t;
int la[400005]={},deg[400005]={};
bool vis[400005]={};
struct aaa
{
	int to,nx,u;
}edge[1200005];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],-1},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y],-1},la[y]=edge_t,++deg[y];
}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=la[x];i;i=la[x])
	{
		la[x]=edge[i].nx;
		if(!(~edge[i].u))edge[i].u=edge[i^1].u=t,t^=1,dfs(edge[i].to);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),add_edge(x,y+Mx);
	for(int i=1;i<Mx;++i)
	{
		if(deg[i]&1)add_edge(i,(Mx<<1));
		if(deg[i+Mx]&1)add_edge(i+Mx,Mx);
	}
	if(deg[Mx]&1)add_edge(Mx,(Mx<<1));
	for(int i=1;i<=Mx;++i)if(deg[i] && !vis[i])t=0,dfs(i);
	for(int i=1;i<=n;++i)printf("%c",edge[i<<1].u? 'b':'r');
	return 0;
}