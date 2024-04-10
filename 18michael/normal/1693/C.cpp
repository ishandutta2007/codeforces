#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,edge_t=0;
int deg[400002],la[400002],dis[400002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx;
}edge[800002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dijkstra()
{
	int u,v;
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[n]=0,pq.push(P(0,n));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(dis[u=p.second]!=(v=p.first))continue;
		for(int i=la[u],w;i;i=edge[i].nx)
		{
			w=edge[i].to;
			if(dis[w]>v+deg[w])dis[w]=v+deg[w],pq.push(P(dis[w],w));
			--deg[w];
		}
	}
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(y,x),++deg[x];
	dijkstra(),printf("%d",dis[1]);
	return 0;
}