#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,l,r,mid,p,edge_t=0,Test_num;
LL sum;
bool ok;
int a[1002],b[1002],la[1002],lae[1002],deg[1002];
bool vis[1002],u[1002];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[4002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,LL d)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!vis[v] && d>a[v])dfs(v,d+(u[v]? 0:b[v]));
	}
}
inline bool check()
{
	for(int i=1;i<=n;++i)u[i]=0;
	for(u[1]=ok=1,sum=mid;ok;)
	{
		ok=0;
		for(int i=1;i<=n;++i)vis[i]=lae[i]=0,deg[i]=-1;
		dfs(1,sum);
		for(int i=1;i<=edge_t;i+=2)if(vis[edge[i].to] && vis[edge[i+1].to])++deg[edge[i].to],++deg[edge[i+1].to];
		for(int i=1;i<=n;++i)if(!u[i] && !deg[i])q.push(i);
		for(;!q.empty();)
		{
			p=q.front(),q.pop();
			for(int i=la[p],v;i;i=edge[i].nx)if(!(--deg[v=edge[i].to]) && !u[v])q.push(v);
		}
		for(int i=1;i<=n;++i)if(deg[i]>0 && !u[i])u[i]=ok=1,sum+=b[i];
	}
	for(int i=1;i<=n;++i)if(!u[i])return 0;
	return 1;
}
inline void solve()
{
	scanf("%d%d",&n,&m),edge_t=0;
	for(int i=1;i<=n;++i)la[i]=0;
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(l=2,r=1000000001;l<=r;)
	{
		mid=((l+r)>>1);
		if(check())r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}