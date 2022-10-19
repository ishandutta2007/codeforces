#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,edge_t=1,S=0,T,p,idt=0,maxflow=0;
LL ans=0;
int a[40012],id[40012],la[40012],val[40012],cur[40012],dx[2]={0,-1},dy[2]={-1,0};
bitset<40012> vis;
struct aaa
{
	int to,nx,f;
}edge[400002];
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
inline int num(int x,int y)
{
	return (x-1)*n+y;
}
inline void add_edge(int x,int y,int z,int w)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],w},la[y]=edge_t;
}
inline bool dfs(int x)
{
	if(x==T)return 1;
	vis.set(x);
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].f && !vis.test(v=edge[i].to) && dfs(v))return --edge[i].f,++edge[i^1].f,1;
	return 0;
}
inline bool dfs2(int x,int y)
{
	if(x==S)return 1;
	vis.set(x);
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].f && !vis.test(v=edge[i].to) && (x!=T || v==y) && dfs2(v,y))return --edge[i].f,++edge[i^1].f,1;
	return 0;
}
int main()
{
	scanf("%d",&n),T=num(n,n)+1;
	for(int i=1,nx,ny;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[num(i,j)]);
			if(~a[num(i,j)])for(int o=0;o<2;++o)if((nx=i+dx[o]) && (ny=j+dy[o]) && ~a[num(nx,ny)])add_edge(num(i,j),num(nx,ny),1,1);
		}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i==1 || j==1 || i==n || j==n)add_edge(id[++idt]=num(i,j),T,inf,0);
	sort(id+1,id+idt+1,cmp);
	for(int i=1;i<idt;++i)
	{
		for(vis.reset();dfs2(T,id[i]);vis.reset())--maxflow;
		for(int j=la[id[i]];j;j=edge[j].nx)
			if(edge[j].to==T)
			{
				edge[j].f=edge[j^1].f=0;
				break;
			}
		add_edge(S,id[i],inf,0);
		for(vis.reset();dfs(S);vis.reset())++maxflow;
		ans+=(LL)maxflow*(a[id[i+1]]-a[id[i]]);
	}
	return 0&printf("%lld",ans);
}