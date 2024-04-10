#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 3333333
struct edge{int t,next,v;}ed[6666666];
int head[N],cnt,vis[N],ct,n,m,k,a,b,c,d,e;
long long dis[N];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;}
void dijkstra(int s)
{
	priority_queue<pair<long long,int> > s1;
	for(register int i=1;i<=cnt;i++)dis[i]=1e18,vis[i]=0;
	s1.push(make_pair(0,s));dis[s]=0;
	while(!s1.empty())
	{
		pair<long long,int> s2=s1.top();s1.pop();int s=s2.second;
		if(vis[s])continue;vis[s]=1;
		for(int i=head[s];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[s]+ed[i].v)
		dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
struct segt{int x,l,r;}e1[N],e2[N];
void build(int x,int l,int r)
{
	e1[x].l=e2[x].l=l;e1[x].r=e2[x].r=r;
	if(l==r){e1[x].x=e2[x].x=l;return;}
	e1[x].x=++ct;e2[x].x=++ct;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	adde(e2[x].x,e2[x<<1].x,0);adde(e2[x].x,e2[x<<1|1].x,0);
	adde(e1[x<<1].x,e1[x].x,0);adde(e1[x<<1|1].x,e1[x].x,0);
}
void query1(int x,int l,int r,int t,int s)
{
	if(e1[x].l==l&&e1[x].r==r){adde(e1[x].x,t,s);return;}
	int mid=(e1[x].l+e1[x].r)>>1;
	if(mid>=r)query1(x<<1,l,r,t,s);
	else if(mid<l)query1(x<<1|1,l,r,t,s);
	else query1(x<<1,l,mid,t,s),query1(x<<1|1,mid+1,r,t,s);
}
void query2(int x,int l,int r,int t,int s)
{
	if(e2[x].l==l&&e2[x].r==r){adde(t,e2[x].x,s);return;}
	int mid=(e2[x].l+e2[x].r)>>1;
	if(mid>=r)query2(x<<1,l,r,t,s);
	else if(mid<l)query2(x<<1|1,l,r,t,s);
	else query2(x<<1,l,mid,t,s),query2(x<<1|1,mid+1,r,t,s);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	ct=n;build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==1)adde(b,c,d);
		if(a==2)scanf("%d",&e),query2(1,c,d,b,e);
		if(a==3)scanf("%d",&e),query1(1,c,d,b,e);
	}
	dijkstra(k);
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]>1e17?-1:dis[i]);
}