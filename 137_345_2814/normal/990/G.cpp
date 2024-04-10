#include<cstdio>
using namespace std;
#define N 200007
int n,v[N],div[N][163],a,b,sz[N],vis[N],dis[N],mx[N],val,ans,tmp,head[N],cnt;
int s1[N];
long long Ans[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs1(int u,int fa)
{
	sz[u]=1;mx[u]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	{
		dfs1(ed[i].t,u);
		sz[u]+=sz[ed[i].t];
		if(mx[u]<sz[ed[i].t])
		mx[u]=sz[ed[i].t];
	}
	if(mx[u]<val-sz[u])
	mx[u]=val-sz[u];
	if(mx[u]<ans)
	ans=mx[u],tmp=u;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void dfs2(int u,int fa)
{
	dis[u]=gcd(dis[fa],v[u]);
	for(int i=1;i<=div[dis[u]][0];i++)
	Ans[div[dis[u]][i]]+=s1[div[dis[u]][i]];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dfs2(ed[i].t,u);
}
void dfs4(int u,int fa)
{
	dis[u]=gcd(dis[fa],v[u]);
	for(int i=1;i<=div[dis[u]][0];i++)
	s1[div[dis[u]][i]]++;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dfs4(ed[i].t,u);
}
void dfs5(int u,int fa)
{
	dis[u]=gcd(dis[fa],v[u]);
	for(int i=1;i<=div[dis[u]][0];i++)
	s1[div[dis[u]][i]]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dfs4(ed[i].t,u);
}
void work(int u)
{
	dis[u]=v[u];
	for(int i=1;i<=div[dis[u]][0];i++)
	s1[div[dis[u]][i]]++,Ans[div[dis[u]][i]]++;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	dfs2(ed[i].t,u),dfs4(ed[i].t,u);
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	dfs5(ed[i].t,u);
	for(int i=1;i<=div[dis[u]][0];i++)
	s1[div[dis[u]][i]]=0;
}
void dfs3(int u)
{
	vis[u]=1;
	work(u);
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	ans=19260817,val=sz[ed[i].t],dfs1(ed[i].t,u),dfs3(tmp);
}
int main()
{
	for(int i=1;i<=200000;i++)
	for(int j=i;j<=200000;j+=i)
	div[j][++div[j][0]]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	ans=21386583,val=n,dfs1(1,0),dfs3(tmp);
	for(int i=2e5;i>=1;i--)
	for(int j=i*2;j<=2e5;j+=i)
	Ans[i]-=Ans[j];
	for(int i=1;i<=2e5;i++)
	if(Ans[i])
	printf("%d %lld\n",i,Ans[i]);
}