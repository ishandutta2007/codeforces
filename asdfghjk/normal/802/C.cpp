#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=10005;
int n,K,i,j,k,l,a[N],c[N],lst[N],head[N],adj[N],nxt[N],cap[N],flow[N],cost[N],q[N],bg,ed,dis[N],w[N],ans,p[N],pre[N];
bool v[N];
void addedge(int u,int v,int w,int c)
{
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	cap[l]=w;
	cost[l]=c;
	adj[++l]=u;
	nxt[l]=head[v];
	head[v]=l;
	cost[l]=-c;
}
bool spfa()
{
	int i;
	for(i=1;i<=n*2+2;++i)
		dis[i]=1<<30,v[i]=false;
	q[bg=ed=1]=n*2+1;
	w[n*2+1]=1<<30;
	dis[n*2+1]=0;
	v[n*2+1]=true;
	while(bg<=ed)
	{
		v[q[bg]]=false;
		for(i=head[q[bg]];i;i=nxt[i])
			if(flow[i]<cap[i]&&dis[q[bg]]+cost[i]<dis[adj[i]])
			{
				dis[adj[i]]=dis[q[bg]]+cost[i];
				w[adj[i]]=min(w[q[bg]],cap[i]-flow[i]);
				p[adj[i]]=q[bg];
				pre[adj[i]]=i;
				if(!v[adj[i]])
				{
					v[adj[i]]=true;
					q[++ed]=adj[i];
				}
			}
		++bg;
	}
	if(dis[n*2+2]==1<<30)
		return false;
	ans+=dis[n*2+2]*w[n*2+2];
	i=n*2+2;
	while(i!=n*2+1)
	{
		flow[pre[i]]+=w[n*2+2];
		flow[pre[i]&1?pre[i]+1:pre[i]-1]-=w[n*2+2];
		i=p[i];
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(i=1;i<=n;++i)
		scanf("%d",c+i);
	for(i=1;i<=n;++i)
	{
		addedge(2*n+1,i,1,c[a[i]]);
		addedge(n+i,2*n+2,1,0);
		addedge(i,n+i,1,0);
	}
	for(i=1;i<n;++i)
		addedge(i,i+1,K-1,0);
	for(i=1;i<=n;++i)
	{
		if(lst[a[i]])
			addedge(i-1,n+lst[a[i]],1,-c[a[i]]);
		lst[a[i]]=i;
	}
	while(spfa());
	printf("%d",ans);
	return 0;
}