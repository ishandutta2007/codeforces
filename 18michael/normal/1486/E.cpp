#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,edge_t=0;
LL w;
int la[100002]={};
LL dis[5100052];
LL dp[100002][52];
typedef pair<LL,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx,val;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int num(int x,int y)
{
	return x*51+y;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dijkstra()
{
	for(int i=1;i<=n;++i)
		for(int j=0;j<=50;++j)
			dis[num(i,j)]=inf;
	pq.push(P(dis[num(1,0)]=0,num(1,0)));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(dis[p.second]<p.first)continue;
		for(int i=la[p.second/51],v,u;i;i=edge[i].nx)
		{
			v=edge[i].to;
			if(p.second%51){if(dis[u=num(edge[i].to,0)]>(w=p.first+edge[i].val*(edge[i].val+2*(p.second%51))))pq.push(P(dis[u]=w,u));}
			else{if(dis[u=num(edge[i].to,edge[i].val)]>(w=p.first+edge[i].val*edge[i].val))pq.push(P(dis[u]=w,u));}
		}
	}
	for(int i=1;i<=n;++i)printf("%lld ",dis[num(i,0)]==inf? -1:dis[num(i,0)]);
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y,z;i<=m;++i)read(x),read(y),read(z),add_edge(x,y,z);
	dijkstra();return 0;
}