#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500005;
int n,i,j,k,l,g[305][305],m[305],pt[305],rpt[305],head[N],adj[N],nxt[N],flow[N],cap[N],cur[N],d[N],q[N],bg,ed,st,fn,tot,ans;
bool v[N];
void addedge(int u,int v,int w)
{
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
	for(i=1;i<=tot;++i)
		d[i]=1<<30;
	q[bg=ed=1]=st;
	d[st]=0;
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
	return d[fn]<(1<<30);
}
int dfs(int x,int a)
{
	if(x==fn||a<=0)
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
int Dinic()
{
	int rtn=0;
	while(bfs())
	{
		for(int i=1;i<=tot;++i)
			cur[i]=head[i];
		rtn+=dfs(st,1<<30);
	}
	return rtn;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",m+i);
		for(j=1;j<=m[i];++j)
		{
			scanf("%d",&g[i][j]);
			addedge(i,n+g[i][j],1);
		}
	}
	for(i=1;i<=n;++i)
	{
		addedge(2*n+1,i,1);
		addedge(n+i,2*n+2,1);
	}
	tot=2*n+2,st=2*n+1,fn=2*n+2;
	Dinic();
	for(i=1;i<=n;++i)
		for(j=head[i];j;j=nxt[j])
			if(adj[j]!=2*n+1&&flow[j])
			{
				pt[i]=adj[j]-n;
				rpt[pt[i]]=i;
				break;
			}
	l=0;
	for(i=1;i<=n+2;++i)
		head[i]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m[i];++j)
			addedge(i,rpt[g[i][j]],1<<30);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&j);
		j=-j;
		if(j>0)
		{
			ans+=j;
			addedge(n+1,i,j);
		}
		else
			addedge(i,n+2,-j);
	}
	tot=n+2,st=n+1,fn=n+2;
	ans-=Dinic();
	printf("%d",-ans);
	return 0;
}