#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 350050
int vis[N],n,m,k,head[N],cnt,vis2[N],as[N],a,b,c;long long dis[N];
struct edge{int t,next,v,id;}ed[N*4];
void adde(int f,int t,int v,int id){ed[++cnt]=(edge){t,head[f],v,id};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v,id};head[t]=cnt;}
void dij()
{
	priority_queue<pair<long long,int> > s1;
	memset(dis,0x3f,sizeof(dis));
	s1.push(make_pair(0,1));dis[1]=0;
	while(!s1.empty())
	{
		pair<long long,int> s2=s1.top();s1.pop();int s=s2.second;
		if(vis[s])continue;vis[s]=1;
		for(int i=head[s];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[s]+ed[i].v)
		dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
void bfs(int k)
{
	int ct=1;queue<int> s1;memset(vis,0,sizeof(vis));
	printf("%d\n",k);vis[1]=1;s1.push(1);if(k==0)return;
	while(!s1.empty())
	{
		int t=s1.front();s1.pop();
		for(int i=head[t];i;i=ed[i].next)
		if(dis[ed[i].t]==dis[t]+ed[i].v&&!vis[ed[i].t])
		{vis[ed[i].t]=1;s1.push(ed[i].t);printf("%d ",ed[i].id);ct++;if(ct>k)return;}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c,i);
	dij();bfs(min(n-1,k));
}