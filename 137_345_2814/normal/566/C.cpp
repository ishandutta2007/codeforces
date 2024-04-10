#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 205000
int n,dis[N],head[N],vis[N],sz[N],vl,tp,as,as1,v[N],a,b,c,cnt;
double su[N],su2[N],as2=1e25;
struct edge{int t,next,l;}ed[N*2];
void adde(int f,int t,int l){ed[++cnt]=(edge){t,head[f],l};head[f]=cnt;ed[++cnt]=(edge){f,head[t],l};head[t]=cnt;}
void dfs1(int u,int fa)
{
	sz[u]=1;
	int mx=0;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t]&&ed[i].t!=fa)dfs1(ed[i].t,u),mx=max(mx,sz[ed[i].t]),sz[u]+=sz[ed[i].t];
	mx=max(mx,vl-sz[u]);
	if(mx<tp)tp=mx,as=u;
}
void dfs2(int u,int fa)
{
	su[u]=pow(dis[u],1.5)*v[u];
	su2[u]=pow(dis[u],0.5)*v[u];
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dis[ed[i].t]=dis[u]+ed[i].l,dfs2(ed[i].t,u),su[u]+=su[ed[i].t],su2[u]+=su2[ed[i].t];
}
void solve(int x)
{
	dis[x]=0;dfs2(x,0);vis[x]=1;
	if(as2>su[x])as2=su[x],as1=x;
	for(int i=head[x];i;i=ed[i].next)
	if(su2[x]<2*su2[ed[i].t]&&!vis[ed[i].t])
	{
		dfs1(x,0);
		tp=1e7,vl=sz[ed[i].t];dfs1(ed[i].t,0);
		solve(as);
		break;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<n;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	solve(1);printf("%d %.15lf\n",as1,as2);
}