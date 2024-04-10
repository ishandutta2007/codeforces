#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,edge_t=0,res,ans=inf;
int la[1002]={},x[1002],y[1002],z[1002],a[1002],b[1002];
int dis[1002][1002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx,val;
}edge[2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dijkstra(int x)
{
	for(int i=1;i<=n;++i)dis[x][i]=inf;
	int u,v,w;pq.push(P(dis[x][x]=0,x));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(p.first>dis[x][u=p.second])continue;
		for(int i=la[u];i;i=edge[i].nx)
			if(dis[x][v=edge[i].to]>(w=dis[x][u]+edge[i].val))
				pq.push(P(dis[x][v]=w,v));
	}
}
int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i)read(x[i]),read(y[i]),read(z[i]),add_edge(x[i],y[i],z[i]);
	for(int i=1;i<=k;++i)read(a[i]),read(b[i]);
	for(int i=1;i<=n;++i)dijkstra(i);
	for(int i=1;i<=m;++i)
	{
		res=0;
		for(int j=1;j<=k;++j)res+=min(dis[a[j]][b[j]],min(dis[a[j]][x[i]]+dis[y[i]][b[j]],dis[a[j]][y[i]]+dis[x[i]][b[j]]));
		ans=min(ans,res);
	}
	return 0&printf("%d",ans);
}