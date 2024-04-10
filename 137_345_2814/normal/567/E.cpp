#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 121212
#define M 232323
#define mod 1019283781
struct edge{int f,t,next,v;}ed[M*2],ed2[M*2];
int head[N],cnt,vis[N],n,m,s,t,a,b,c,dpa[N],dpb[N],head2[N],cnt2;
long long dis[N],dist[N];
void adde(int f,int t,int v){ed[++cnt]=(edge){f,t,head[f],v};head[f]=cnt;ed2[++cnt2]=(edge){t,f,head2[t],v};head2[t]=cnt2;}
void dijkstra(int s)
{
	priority_queue<pair<long long,int> > s1;
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
void dijkstra2(int s)
{
	priority_queue<pair<long long,int> > s1;
	memset(dist,0x3f,sizeof(dist));memset(vis,0,sizeof(vis));
	s1.push(make_pair(0,s));dist[s]=0;
	while(!s1.empty())
	{
		int s=s1.top().second;s1.pop();
		if(vis[s])continue;vis[s]=1;
		for(int i=head2[s];i;i=ed2[i].next)
		if(dist[ed2[i].t]>dist[s]+ed2[i].v)
		dist[ed2[i].t]=dist[s]+ed2[i].v,s1.push(make_pair(-dist[ed2[i].t],ed2[i].t));
	}
}
int dfsa(int u)
{
	if(dpa[u]>=0)return dpa[u];
	int res=(u==t);
	for(int i=head[u];i;i=ed[i].next)
	if(dist[ed[i].t]+dis[u]+ed[i].v==dis[t])
	res=(res+dfsa(ed[i].t))%mod;
	return dpa[u]=res;
}
int dfsb(int u)
{
	if(dpb[u]>=0)return dpb[u];
	int res=(u==s);
	for(int i=head2[u];i;i=ed2[i].next)
	if(dis[ed2[i].t]+dist[u]+ed2[i].v==dis[t])
	res=(res+dfsb(ed2[i].t))%mod;
	return dpb[u]=res;
}
int main()
{
	memset(dpa,-1,sizeof(dpa));
	memset(dpb,-1,sizeof(dpb));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	dijkstra(s);dijkstra2(t);dfsa(s);dfsb(t);
	for(int i=1;i<=cnt;i++)
	{
		if(dis[ed[i].f]+ed[i].v+dist[ed[i].t]==dis[t])
		{
			if(1ll*dpb[ed[i].f]*dpa[ed[i].t]%mod==dpa[s])printf("YES\n");
			else if(ed[i].v==1)printf("NO\n");
			else printf("CAN 1\n");
		}
		else
		{
			long long tmp=dis[t]-dis[ed[i].f]-dist[ed[i].t];
			if(tmp<2)printf("NO\n");
			else printf("CAN %lld\n",ed[i].v-tmp+1);
		}
	}
}//