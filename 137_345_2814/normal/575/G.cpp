#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
#define N 132231
struct edge{int t,next,v;}ed[N*2];
int head[N],cnt,dis[N],vis[N],dist[N],fr[N],fi[N],a,b,c,fr2[N],n,m,ds[N];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
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
		if(dis[ed[i].t]>dis[s]+1)
		dis[ed[i].t]=dis[s]+1,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
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
		for(int i=head[s];i;i=ed[i].next)
		{
			int nt=dist[s]+1;
			if(dist[s]==0&&ed[i].v==0)nt=0;
			if(dist[ed[i].t]>nt)
			dist[ed[i].t]=nt,fr2[ed[i].t]=ed[i].v,s1.push(make_pair(-dist[ed[i].t],ed[i].t));
		}
	}
}
struct sth{int x,fr,fi,ds;};
void abfs()
{
	queue<int> s1;
	s1.push(n);
	memset(vis,0,sizeof(vis));vis[n]=1;
	while(!s1.empty())
	{
		int r=s1.front();s1.pop();
		for(int i=head[r];i;i=ed[i].next)
		if(ed[i].v==0&&!vis[ed[i].t])
		ds[ed[i].t]=ds[r]+1,fr[ed[i].t]=r,s1.push(ed[i].t),vis[ed[i].t]=1;
	}
}
void bfs()
{
	queue<int> s1;
	queue<sth> s2,s3;
	int as=1e9;
	for(int i=1;i<=n;i++)if(dist[i]==0)as=min(as,dis[i]);
	for(int i=1;i<=n;i++)if(dist[i]==0&&dis[i]==as)s1.push(i);
	while(!s1.empty())
	{
		if(fr[1])return;
		while(!s1.empty())
		{
			int s=s1.front();s1.pop();
			for(int i=head[s];i;i=ed[i].next)
			if(dis[ed[i].t]==dis[s]-1)
			s2.push((sth){ed[i].t,s,ed[i].v,ds[s]+1});
		}
		int as2=1e9;
		while(!s2.empty())
		{
			sth e=s2.front();
			as2=min(as2,e.fi);
			s2.pop();s3.push(e);
		}
		while(!s3.empty())
		{
			sth e=s3.front();s3.pop();
			if(e.fi==as2)s2.push(e);
		}
		while(!s2.empty())
		{
			sth e=s2.front();s2.pop();
			if(fi[e.x]>e.fi||(fi[e.x]==e.fi&&ds[e.x]>e.ds)||(fi[e.x]==e.fi&&ds[e.x]==e.ds&&fr[e.x]>e.fr))fr[e.x]=e.fr,fi[e.x]=e.fi,fr2[e.x]=e.fi,ds[e.x]=e.ds,s1.push(e.x);
		}
	}
}
stack<int> as;
queue<int> as2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&a,&b,&c),adde(a+1,b+1,c);
	memset(fi,0x3f,sizeof(fi));
	dijkstra(1);dijkstra2(n);abfs();bfs();
	int st=1,ct=1;as2.push(1);
	while(st!=n)
	{
		as.push(fr2[st]);
		as2.push(fr[st]);
		ct++;
		st=fr[st];
	}
	int fg=0;
	while(!as.empty())
	{
		if(as.top())fg=1;
		if(fg)printf("%d",as.top());
		as.pop();
	}
	if(!fg)printf("0");
	printf("\n%d\n",ct);
	while(!as2.empty())
	printf("%d ",as2.front()-1),as2.pop();
}