#include<cstdio>
#include<queue>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,p,S=0,T,edge_t=1;
LL ans=0;
int la[2002]={},dis[2002];
queue<int> q;
struct aaa
{
	int to,nx;
	LL f;
}edge[8002];
inline void add_edge(int x,int y,LL z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool bfs()
{
	for(int i=1;i<=T;++i)dis[i]=T+1;
	dis[S]=0,q.push(S);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)
				dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<=T;
}
inline LL dfs(int x,LL f)
{
	if(x==T)return f;
	LL used=0,tmp;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(edge[i].f,f-used)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=0;
	return used;
}
inline LL Dinic()
{
	LL maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	scanf("%d%d",&n,&m),T=n+m+1;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),add_edge(i,T,x);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(n+i,x,inf),add_edge(n+i,y,inf),add_edge(S,n+i,z),ans+=z;
	return 0&printf("%lld",ans-Dinic());
}