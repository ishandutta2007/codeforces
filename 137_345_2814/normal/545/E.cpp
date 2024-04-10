#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,a,b,c,head[300001],cnt,ecnt,as[300001];
long long ans,dis[300001],vis[300001];
struct edge{
	int t,next,v;
}ed[600004];
void adde(int f,int t,int v)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[cnt].v=v;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
	ed[cnt].v=v;
}
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pair<pair<long long,pair<int,int> >,int> > lsj;
	lsj.push(make_pair(make_pair(0,make_pair(0,0)),s));
	while(!lsj.empty())
	{
		pair<pair<long long,pair<int,int> >,int> p=lsj.top();lsj.pop();
		int t=p.second;
		if(vis[t])continue;
		ans-=p.first.second.first;
		as[ecnt++]=p.first.second.second;
		vis[t]=1;
		for(int i=head[t];i;i=ed[i].next)
		if((!vis[ed[i].t])&&dis[ed[i].t]>=dis[t]+ed[i].v)
		{
			dis[ed[i].t]=dis[t]+ed[i].v;
			lsj.push(make_pair(make_pair(-dis[ed[i].t],make_pair(-ed[i].v,(i+1)/2)),ed[i].t));
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	scanf("%d",&a);
	dijkstra(a);
	printf("%lld\n",ans);
	for(int i=1;i<ecnt;i++)
	printf("%d ",as[i]);
}