#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0,p,to_t=0,cnt=0;
int la[1000002],deg[1000002],to[1000002];
bool vis[1000002],u[1000002];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[1000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			u[i]=vis[i]=1;
			for(int j=la[i],v;j;j=edge[j].nx)vis[v=edge[j].to]=1,deg[v]+=u[v];
		}
	for(int i=1;i<=n;++i)if(u[i] && !deg[i])q.push(i);
	while(!q.empty())
	{
		to[++to_t]=p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(u[v=edge[i].to] && !(--deg[v]))q.push(v);
	}
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=to_t;++i)if(!vis[to[i]])for(int j=la[to[i]],v;j;j=edge[j].nx)if(u[v=edge[j].to])vis[v]=1;
	for(int i=1;i<=n;++i)cnt+=(u[i] && !vis[i]);
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)if(u[i] && !vis[i])printf("%d ",i);
	return 0;
}