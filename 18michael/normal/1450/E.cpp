#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,p,edge_t=0,mx,res=-1;
int la[202],col[202],cnt[202],dis[202];
bool inq[202];
queue<int> q;
vector<int> vec;
typedef pair<int,int> P;P pr;
priority_queue<P,vector<P>,greater<P> > pq,ept;
struct aaa
{
	int to,nx,val;
}edge[4002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
}
inline bool dfs(int x,int c)
{
	col[x]=c;
	for(int i=la[x],v;i;i=edge[i].nx)if((col[v=edge[i].to] && col[v]!=-c) || (!col[v] && dfs(v,-c)))return 1;
	return 0;
}
inline bool SPFA()
{
	for(int i=2;i<=n;++i)dis[i]=inf;
	for(dis[1]=0,q.push(1);!q.empty();)
	{
		inq[p=q.front()]=0,q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(dis[v=edge[i].to]>dis[p]+edge[i].val)
			{
				dis[v]=dis[p]+edge[i].val;
				if((cnt[v]=cnt[p]+1)>n)return 1;
				if(!inq[v])q.push(v);
			}
	}
	return 0;
}
inline void solve(int x)
{
	for(int i=1;i<=n;++i)dis[i]=inf;
	for(pq=ept,pq.push(P(dis[x]=mx=0,x));!pq.empty();)
	{
		pr=pq.top(),pq.pop();
		if(pr.first>dis[pr.second])continue;
		if(pr.first<0)return ;
		for(int i=la[pr.second],v;i;i=edge[i].nx)if(dis[v=edge[i].to]>pr.first+edge[i].val)pq.push(P(dis[v]=pr.first+edge[i].val,v));
	}
	for(int i=1;i<=n;++i)mx=max(mx,dis[i]);
	if(mx>res)
	{
		res=mx,vec.clear();
		for(int i=1;i<=n;++i)vec.push_back(dis[i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,1),add_edge(y,x,z? -1:1);
	if(dfs(1,1) || SPFA())return 0&puts("NO");
	for(int i=1;i<=n;++i)solve(i);
	printf("YES\n%d\n",res);
	for(int i=0;i<vec.size();++i)printf("%d ",vec[i]);
	return 0;
}