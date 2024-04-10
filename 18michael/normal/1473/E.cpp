#include<cstdio>
#include<queue>
#include<vector>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,u,edge_t=0;
int la[200002]={};
LL dis[800002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx,val;
}edge[400002];
inline int num(int x,int y)
{
	return x*4+y;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dijkstra()
{
	for(int i=5;i<=num(n,3);++i)dis[i]=inf;
	pq.push(P(dis[4]=0,4));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop();
		if(dis[u=p.second]<p.first)continue;
		for(int i=la[u>>2],v;i;i=edge[i].nx)
		{
			v=((edge[i].to<<2)|(u&3));
			if(dis[v]>dis[u]+edge[i].val)pq.push(P(dis[v]=dis[u]+edge[i].val,v));
			if(!(v&1) && dis[v|1]>dis[u])pq.push(P(dis[v|1]=dis[u],(v|1)));
			if(!(v&2) && dis[v|2]>dis[u]+2*edge[i].val)pq.push(P(dis[v|2]=dis[u]+2*edge[i].val,(v|2)));
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	dijkstra();
	for(int i=2;i<=n;++i)printf("%lld%c",min(dis[num(i,0)],dis[num(i,3)]),i==n? '\n':' ');
	return 0;
}