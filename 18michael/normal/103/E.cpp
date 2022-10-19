#include<bits/stdc++.h>
#define LL long long
#define inf 300000001
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,edge_t=1,S=0,T,ans,p;
int la[602],dis[602];
queue<int> q;
struct aaa
{
	int to,nx;
	LL f;
}edge[182002];
inline void add_edge(int x,int y,LL z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool bfs()
{
	for(int i=1;i<=T;++i)dis[i]=inf;
	for(q.push(dis[0]=0);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<inf;
}
inline LL dfs(int x,LL f)
{
	if(x==T)return f;
	LL tmp,used=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(f-used,edge[i].f)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=inf;
	return used;
}
inline LL Dinic()
{
	LL maxflow=0;
	while(bfs())maxflow+=dfs(S,Inf);
	return maxflow;
}
int main()
{
	scanf("%d",&n),T=(n<<1)+1,ans=n*inf;
	for(int i=1,x,y;i<=n;++i)for(scanf("%d",&x);x--;add_edge(i,n+y,inf))scanf("%d",&y);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),ans-=x,add_edge(S,i,inf-x),add_edge(i+n,T,inf);
	return 0&printf("%d",Dinic()-ans);
}