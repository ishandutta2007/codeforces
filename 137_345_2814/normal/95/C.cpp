#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define N 1040
#define M 1004000
struct edge{int t,next,v;}ed[M*2],ed2[M*2];
long long dis[N];int vis[N],n,m,a,b,c,cnt,cnt2,head[N],head2[N],s,t;
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void adde2(int f,int t,int v){ed2[++cnt2]=(edge){t,head2[f],v};head2[f]=cnt2;}
void dijkstra(int s)
{
	priority_queue<pair<long long,int> > s1;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	s1.push(make_pair(0,s));
	while(!s1.empty())
	{
		pair<int,int> s2=s1.top();s1.pop();int s=s2.second;
		if(vis[s])continue;vis[s]=1;
		for(int i=head[s];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[s]+ed[i].v)
		dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
void dijkstra2(int s)
{
	priority_queue<pair<long long,int> > s1;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	s1.push(make_pair(0,s));
	while(!s1.empty())
	{
		pair<int,int> s2=s1.top();s1.pop();int s=s2.second;
		if(vis[s])continue;vis[s]=1;
		for(int i=head2[s];i;i=ed2[i].next)
		if(dis[ed2[i].t]>dis[s]+ed2[i].v)
		dis[ed2[i].t]=dis[s]+ed2[i].v,s1.push(make_pair(-dis[ed2[i].t],ed2[i].t));
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		dijkstra(i);
		for(int j=1;j<=n;j++)if(dis[j]<=a)adde2(i,j,b);
	}
	dijkstra2(s);printf("%lld\n",dis[t]>1e17?-1:dis[t]);
}