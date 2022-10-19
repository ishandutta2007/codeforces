#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=1,S=0,T,tot,p;
int la[1302],dis[1302],cur[1302];
int num[52][52];
bool inq[1302],vis[1302];
bool u[52][52];
typedef pair<int,int> P;
queue<int> q;
struct aaa
{
	int to,nx,f,val;
}edge[12502];
inline void add_edge(int x,int y,int z,int w)
{
	edge[++edge_t]=(aaa){y,la[x],z,w},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0,-w},la[y]=edge_t;
}
inline bool SPFA()
{
	for(int i=0;i<=tot;++i)dis[i]=inf,cur[i]=la[i];
	for(q.push(dis[S]=0);q.size();)
	{
		inq[p=q.front()]=0,q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].f && dis[v=edge[i].to]>dis[p]+edge[i].val)
			{
				dis[v]=dis[p]+edge[i].val;
				if(!inq[v])q.push(v),inq[v]=1;
			}
	}
	return dis[T]<inf;
}
inline P dfs(int x,int f)
{
	if(x==T)return P(f,0);
	P tmp,used=P(0,0);vis[x]=1;
	for(int &i=cur[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+edge[i].val && !vis[v])
		{
			tmp=dfs(v,min(f-used.first,edge[i].f)),edge[i].f-=tmp.first,edge[i^1].f+=tmp.first,used.second+=tmp.second+tmp.first*edge[i].val;
			if((used.first+=tmp.first)==f)break;
		}
	}
	if(!used.first)dis[x]=-1;
	return vis[x]=0,used;
}
inline int Dinic()
{
	int minval=0;
	while(SPFA())minval+=dfs(S,inf).second;
	return minval;
}
int main()
{
	scanf("%d%d",&n,&m),T=tot=n+1;
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),u[x][y]=1;
	for(int i=1;i<=n;++i)for(int j=0;j<n;++j)add_edge(i,T,1,j);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		{
			add_edge(S,num[i][j]=num[j][i]=(++tot),1,0);
			if(!u[j][i])add_edge(tot,i,1,0);
			if(!u[i][j])add_edge(tot,j,1,0);
		}
	Dinic();
	for(int i=1;i<=n;puts(""),++i)
		for(int j=1;j<=n;++j)
		{
			if(i==j)putchar('0');
			else if(u[i][j])putchar('1');
			else if(u[j][i])putchar('0');
			else for(int k=la[num[i][j]];k;k=edge[k].nx)if(edge[k].to==i)printf("%d",edge[k].f^1);
		}
	return 0;
}