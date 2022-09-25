#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 555
#define M 133333
struct edge{int f,t,next,v;}ed[M*2];
int head[N],cnt,vis[N],dis[N],n,m,a,b,c,val[N],as[N],f[N][N];
void adde(int f,int t,int v){ed[++cnt]=(edge){f,t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){t,f,head[t],v};head[t]=cnt;}
void dijkstra(int s)
{
	priority_queue<pair<int,int> > s1;
	memset(dis,0x3f,sizeof(dis));memset(vis,0,sizeof(vis));
	s1.push(make_pair(0,s));dis[s]=0;
	while(!s1.empty())
	{
		int s=s1.top().second;s1.pop();
		if(vis[s])continue;vis[s]=1;
		for(int i=head[s];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[s]+ed[i].v)
		dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
void dfs(int u,int x)
{
	vis[u]=1,as[u]+=x;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t]&&dis[ed[i].t]==dis[u]+ed[i].v)
	dfs(ed[i].t,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=(i!=j)*1e9;
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&a,&b,&c),adde(a,b,c),f[a][b]=f[b][a]=c;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)
	{
		memset(val,0,sizeof(val));memset(as,0,sizeof(as));
		dijkstra(i);
		for(int j=1;j<=cnt;j++)
		if(dis[ed[j].f]+ed[j].v==dis[ed[j].t])
		val[ed[j].t]++;
		for(int j=i+1;j<=n;j++)for(int k=1;k<=n;k++)if(f[i][k]+f[k][j]==f[i][j])as[j]+=val[k];
		for(int j=i+1;j<=n;j++)printf("%d ",as[j]);
	}
}