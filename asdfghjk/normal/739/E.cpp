#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=20005;
queue<int> q;
int n,A,B,i,l,head[N],adj[N],nxt[N],flow[N],cap[N],lst[N],a[N],pre[N];
double p[N],u[N],cost[N],dis[N],ans;
bool v[N];
void addedge(int u,int v,int w,double c)
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
	int i,j;
	for(i=1;i<=4+n;++i)
		dis[i]=-(1e50),v[i]=false;
	v[1]=true;
	dis[1]=0;
	q.push(1);
	a[1]=1<<30;
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		v[i]=false;
		for(j=head[i];j;j=nxt[j])
			if(flow[j]<cap[j]&&dis[i]+cost[j]>dis[adj[j]]+(1e-7))
			{
				dis[adj[j]]=dis[i]+cost[j];
				lst[adj[j]]=i;
				pre[adj[j]]=j;
				a[adj[j]]=min(a[i],cap[j]-flow[j]);
				if(!v[adj[j]])
				{
					v[adj[j]]=true;
					q.push(adj[j]);
				}
			}
	}
	if(dis[2]<=0)
		return false;
	ans+=a[2]*dis[2];
	i=2;
	while(i!=1)
	{
		flow[pre[i]]+=a[2];
		flow[pre[i]&1?pre[i]+1:pre[i]-1]-=a[2];
		i=lst[i];
	}
	return true;
}
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(i=1;i<=n;++i)
		scanf("%lf",p+i);
	for(i=1;i<=n;++i)
		scanf("%lf",u+i);
	addedge(1,3,A,0);
	addedge(1,4,B,0);
	for(i=1;i<=n;++i)
	{
		addedge(4+i,2,1,0);
		addedge(4+i,2,1,-p[i]*u[i]);
		addedge(3,4+i,1,p[i]);
		addedge(4,4+i,1,u[i]);
	}
	while(spfa());
	printf("%lf",ans);
	return 0;
}