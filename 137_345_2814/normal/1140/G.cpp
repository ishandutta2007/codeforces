#include<cstdio>
#include<queue>
using namespace std;
#define N 600050
struct edge{int t,next;long long v;}ed[N*4];
int vis[N],sz[N],vl,mx1,as,n,m,head[N],cnt,id[N],vis2[N];
long long dis[N],ans[N],a,b,c,d;
void adde(int f,int t,long long v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
struct qu{int f,t,id;long long as;};
queue<qu> s[N>>1],s2[N>>1],s3[N>>1];
void dfs1(int u,int fa)
{
	sz[u]=1;
	int mx=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t]&&ed[i].t<=n)
	dfs1(ed[i].t,u),mx=max(mx,sz[ed[i].t]),sz[u]+=sz[ed[i].t];
	mx=max(mx,vl-sz[u]);
	if(mx<mx1)mx1=mx,as=u;
}
void dijkstra(int s)
{
    priority_queue<pair<long long,int> > s1;
    s1.push(make_pair(0,s));dis[s]=0;
    while(!s1.empty())
    {
        pair<long long,int> s2=s1.top();s1.pop();int s=s2.second;
        if(vis2[s])continue;vis2[s]=1;
        for(int i=head[s];i;i=ed[i].next)
        if(dis[ed[i].t]>dis[s]+ed[i].v)
        dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
    }
}
void dfs2(int u,int fa,int s)
{
	dis[u]=dis[u+n]=0x3f3f3f3f3f3f3f3fll;vis2[u]=vis2[u+n]=0;
	id[u]=id[u+n]=s;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t<=n)
	if(ed[i].t!=fa&&!vis[ed[i].t])dfs2(ed[i].t,u,s);
}
void dfs3(int u)
{
	vis[u]=1;id[u]=-1;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t]&&ed[i].t<=n)
	{
		vl=sz[ed[i].t],mx1=1e9;
		dfs1(ed[i].t,u);
		dfs2(ed[i].t,u,as);
	}
	dis[u+n]=0x3f3f3f3f3f3f3f3fll,dis[u]=0;vis2[u]=vis2[u+n]=0;
	dijkstra(u);
	while(!s[u].empty())
	{
		qu tp=s[u].front();s[u].pop();
		tp.as=min(tp.as,dis[tp.f]+dis[tp.t]);
		s2[u].push(tp);
	}
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t]&&ed[i].t<=n)
	{
		vl=sz[ed[i].t],mx1=1e9;
		dfs1(ed[i].t,u);
		dfs2(ed[i].t,u,as);
	}
	dis[u]=0x3f3f3f3f3f3f3f3fll,dis[u+n]=0;vis2[u]=vis2[u+n]=0;
	dijkstra(u+n);
	while(!s2[u].empty())
	{
		qu tp=s2[u].front();s2[u].pop();
		tp.as=min(tp.as,dis[tp.f]+dis[tp.t]);
		s3[u].push(tp);
	}
	while(!s3[u].empty())
	{
		qu tp=s3[u].front();s3[u].pop();
		if(id[tp.f]!=id[tp.t])ans[tp.id]=tp.as;
		else s[id[tp.f]].push(tp);
	}
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t]&&ed[i].t<=n)
	{
		vl=sz[ed[i].t],mx1=1e9;
		dfs1(ed[i].t,u);
		dfs3(as);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a),adde(i,i+n,a);
	for(int i=1;i<n;i++)scanf("%lld%lld%lld%lld",&a,&b,&c,&d),adde(a,b,c),adde(a+n,b+n,d);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	scanf("%lld%lld",&a,&b),s[1].push((qu){(a+1)/2+n-a%2*n,(b+1)/2+n-b%2*n,i,0x3f3f3f3f3f3f3f3fll});
	dfs3(1);
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}