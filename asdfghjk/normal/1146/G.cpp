#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000005;
int n,h,m,i,j,k,l,x,y,ans,head[N],adj[N],nxt[N],flow[N],cap[N],d[N],cur[N],q[N],bg,ed,cnt;
void addedge(int u,int v,int w)
{
	//printf("%d %d %d\n",u,v,w);
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	flow[l]=0;
	cap[l]=w;
	adj[++l]=u;
	nxt[l]=head[v];
	head[v]=l;
	flow[l]=0;
	cap[l]=0;
}
bool bfs()
{
	int i;
	for(i=1;i<=cnt;++i)
		d[i]=1<<30;
	d[cnt-1]=0;
	q[bg=ed=1]=cnt-1;
	while(bg<=ed)
	{
		for(i=head[q[bg]];i;i=nxt[i])
			if(flow[i]<cap[i]&&d[adj[i]]==(1<<30))
			{
				d[adj[i]]=d[q[bg]]+1;
				q[++ed]=adj[i];
			}
		++bg;
	}
	return d[cnt]<(1<<30);
}
int dfs(int x,int a)
{
	if(x==cnt||a<=0)
		return a;
	int g,h=0;
	for(;cur[x];cur[x]=nxt[cur[x]])
		if(d[adj[cur[x]]]==d[x]+1&&(g=dfs(adj[cur[x]],min(a,cap[cur[x]]-flow[cur[x]])))>0)
		{
			flow[cur[x]]+=g;
			flow[cur[x]&1?cur[x]+1:cur[x]-1]-=g;
			a-=g;
			h+=g;
			if(a<=0)
				break;
		}
	return h;
}
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	ans=n*h*h;
	cnt=h*n+m+2;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<h;++j)
			addedge((i-1)*h+j,(i-1)*h+j+1,h*h-j*j);
		addedge(cnt-1,(i-1)*h+1,h*h);
		addedge(i*h,cnt,0);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d%d",&j,&k,&x,&y);
		if(x+1>h)
			continue;
		for(;j<=k;++j)
			addedge((j-1)*h+x+1,n*h+i,1<<30);
		addedge(n*h+i,cnt,y);
	}
	while(bfs())
	{
		for(i=1;i<=cnt;++i)
			cur[i]=head[i];
		ans-=dfs(cnt-1,1<<30);
	}
	printf("%d",ans);
	return 0;
}