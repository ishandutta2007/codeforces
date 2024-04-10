#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=1,S=0,T,ans=0,p;
int la[80002],dis[80002];
char s[202][202];
queue<int> q;
struct aaa
{
	int to,nx,f;
}edge[480002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline int num(int x,int y,int o)
{
	return o*(n-1)*m+(x-1)*(m-o)+y;
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
inline int dfs(int x,int f)
{
	if(x==T)return f;
	int tmp,used=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(f-used,edge[i].f)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=inf;
	return used;
}
inline int Dinic()
{
	int maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	scanf("%d%d",&n,&m),T=num(n,m-1,1)+1;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)ans+=(s[i][j]=='#');
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='#' && s[i+1][j]=='#')
			{
				add_edge(S,num(i,j,0),1),--ans;
				if(j>1)add_edge(num(i,j,0),num(i,j-1,1),1),add_edge(num(i,j,0),num(i+1,j-1,1),1);
				if(j<m)add_edge(num(i,j,0),num(i,j,1),1),add_edge(num(i,j,0),num(i+1,j,1),1);
			}
	for(int i=1;i<=n;++i)for(int j=1;j<m;++j)if(s[i][j]=='#' && s[i][j+1]=='#')add_edge(num(i,j,1),T,1),--ans;
	return 0&printf("%d",ans+Dinic());
}