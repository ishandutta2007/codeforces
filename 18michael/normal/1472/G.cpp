#include<bits/stdc++.h>
using namespace std;
int Test_num,n,m,edge_t,e_t,st_t;
int dis[200002],la[200002],lae[200002],deg[200002],mn[200002],st[200002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx;
}edge[200002],e[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t,++deg[y];
}
inline void dijkstra()
{
	for(int i=2;i<=n;++i)dis[i]=n;
	int u,v,w;pq.push(P(dis[1]=0,1));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(p.first>dis[u=p.second])continue;
		for(int i=la[u];i;i=edge[i].nx)
			if(dis[v=edge[i].to]>(w=dis[u]+1))
				pq.push(P(dis[v]=w,v));
	}
}
inline void Topo()
{
	for(int i=1;i<=n;++i)if(!deg[i])st[++st_t]=i;
	int u,v;
	while(st_t)
	{
		u=st[st_t],--st_t;
		for(int i=lae[u];i;i=e[i].nx)
		{
			v=e[i].to,mn[v]=min(mn[v],mn[u]);
			if(!(--deg[v]))st[++st_t]=v;
		}
	}
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),edge_t=e_t=st_t=0;
		for(int i=1;i<=n;++i)la[i]=lae[i]=deg[i]=0;
		for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
		dijkstra();
		for(int i=1;i<=n;++i)
		{
			mn[i]=dis[i];
			for(int j=la[i],v;j;j=edge[j].nx)
			{
				mn[i]=min(mn[i],dis[v=edge[j].to]);
				if(dis[i]<dis[v])add_e(v,i);
			}
		}
		Topo();
		for(int i=1;i<=n;++i)printf("%d%c",mn[i],i==n? '\n':' ');
	}
	return 0;
}