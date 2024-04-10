#include<bits/stdc++.h>
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=100005;
const LL inf=(LL)1e15;

int n,m,k,q,cnt,last[N],fro[N],f[N],sz[N];
LL dis[N],val[N];
struct edge{int to,next;LL w;}e[N*6];
struct data{int x,y;LL w;}a[N*3];
std::priority_queue<std::pair<LL,int> > que;
bool vis[N];

void addedge(int u,int v,LL w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void dij()
{
	for (int i=1;i<=k;i++) dis[i]=0,fro[i]=i,que.push(mp(0,i));
	for (int i=k+1;i<=n;i++) dis[i]=inf;
	while (!que.empty())
	{
		int u=que.top().second;que.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=last[u];i;i=e[i].next)
			if (dis[u]+e[i].w<dis[e[i].to])
			{
				dis[e[i].to]=dis[u]+e[i].w;
				fro[e[i].to]=fro[u];
				que.push(mp(-dis[e[i].to],e[i].to));
			}
	}
}

bool cmp(data a,data b)
{
	return a.w<b.w;
}

int find(int x)
{
	return f[x]==x?x:find(f[x]);
}

LL query(int x,int y)
{
	LL ans=0;
	while (x!=y)
	{
		if (sz[x]>sz[y]) std::swap(x,y);
		ans=std::max(ans,val[x]);x=f[x];
	}
	return ans;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=m;i++)
	{
		int x,y;LL w;scanf("%d%d%lld",&x,&y,&w);
		addedge(x,y,w);
	}
	dij();
	for (int i=1;i<=cnt;i+=2)
	{
		int x=e[i].to,y=e[i+1].to;LL w=dis[x]+dis[y]+e[i].w;
		a[i/2+1]=(data){fro[x],fro[y],w};
	}
	std::sort(a+1,a+m+1,cmp);
	for (int i=1;i<=k;i++) f[i]=i,sz[i]=1;
	for (int i=1;i<=m;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		if (x==y) continue;
		if (sz[x]>sz[y]) std::swap(x,y);
		f[x]=y;sz[y]+=sz[x];val[x]=a[i].w;
	}
	while (q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("%lld\n",query(x,y));
	}
	return 0;
}