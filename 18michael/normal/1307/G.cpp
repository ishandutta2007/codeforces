#include<bits/stdc++.h>
#define LD long double
#define inf 0x3f3f3f3f
using namespace std;
int n,m,Q,S=0,T,edge_t=1,len_t=0,sum;
LD ans;
int la[52],len[52],dis[52];
bool vis[52];
queue<int> q;
typedef pair<int,int> P;
struct aaa
{
	int to,nx,f,val;
}edge[5002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],1,z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0,-z},la[y]=edge_t;
}
inline bool SPFA()
{
	for(int i=1;i<=n;++i)dis[i]=inf,vis[i]=0;
	int p;
	for(dis[0]=0,q.push(0);!q.empty();)
	{
		vis[p=q.front()]=0,q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].f && dis[v=edge[i].to]>dis[p]+edge[i].val)
			{
				dis[v]=dis[p]+edge[i].val;
				if(!vis[v])q.push(v),vis[v]=1;
			}
	}
	return dis[T]<inf;
}
inline P dfs(int x)
{
	if(x==T)return P(1,0);
	P tmp;vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].f && dis[v=edge[i].to]==dis[x]+edge[i].val && !vis[v] && (tmp=dfs(v)).first)return --edge[i].f,++edge[i^1].f,tmp.second+=edge[i].val,tmp;
	dis[x]=inf,vis[x]=0;
	return P(0,0);
}
inline void Dinic()
{
	for(P p;SPFA() && (p=dfs(1)).first;len[++len_t]=p.second,edge[2].f=1,edge[3].f=0);
	len[len_t+1]=inf;
}
int main()
{
	scanf("%d%d",&n,&m),T=n,add_edge(S,1,0);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	Dinic(),scanf("%d",&Q);
	for(int x;Q--;)
	{
		scanf("%d",&x),ans=len[1],sum=0;
		for(int i=1;i<=len_t && len[i]*i-(sum+=len[i])<=x;++i)ans=max(ans,min(len[i]+(LD)(x-len[i]*i+sum)/i,(LD)len[i+1]));
		printf("%.10Lf\n",ans);
	}
	return 0;
}