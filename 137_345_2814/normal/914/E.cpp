#include<cstdio>
#include<map>
#include<set>
using namespace std;
#define N 200050
int n,m,k,sz[N],vis[N],dis[N],mx[N],head[N],cnt,a,b,c,val,ans,tmp;
int s1[N*7],s2[N*7];
long long Ans[N];
char s[N];
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
void dfs2(int u,int fa)
{
	s1[dis[u]]++;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]^(1<<(s[ed[i].t]-'a')),dfs2(ed[i].t,u);
}
void dfs4(int u,int fa)
{
	s2[dis[u]]++;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]^(1<<(s[ed[i].t]-'a')),dfs4(ed[i].t,u);
}
void dfs5(int u,int fa)
{
	s2[dis[u]]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]^(1<<(s[ed[i].t]-'a')),dfs5(ed[i].t,u);
}
long long dfs6(int u,int fa)
{
	long long tmp=0;
	for(int i=0;i<=20;i++)
	tmp+=s1[dis[u]^(i?(1<<(i-1)):0)]-s2[dis[u]^(i?(1<<(i-1)):0)];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]^(1<<(s[ed[i].t]-'a')),tmp+=dfs6(ed[i].t,u);
	Ans[u]+=tmp;
	return tmp;
}
void dfs7(int u,int fa)
{
	s1[dis[u]]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]^(1<<(s[ed[i].t]-'a')),dfs7(ed[i].t,u);
}
void work(int u)
{
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		dis[ed[i].t]=(1<<(s[u]-'a'))^(1<<(s[ed[i].t]-'a'));
		dfs2(ed[i].t,u);
	}
	long long tmp2=0;
	for(int i=0;i<=20;i++)
	tmp2+=s1[i?(1<<(i-1)):0];
	s1[1<<(s[u]-'a')]+=1;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		dis[ed[i].t]=(1<<(s[u]-'a'))^(1<<(s[ed[i].t]-'a'));
		dfs4(ed[i].t,u);
		dis[ed[i].t]=(1<<(s[ed[i].t]-'a'));
		tmp2+=dfs6(ed[i].t,u);
		dis[ed[i].t]=(1<<(s[u]-'a'))^(1<<(s[ed[i].t]-'a'));
		dfs5(ed[i].t,u);
	}
	Ans[u]+=tmp2/2;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		dis[ed[i].t]=(1<<(s[u]-'a'))^(1<<(s[ed[i].t]-'a'));
		dfs7(ed[i].t,u);
	}
	s1[1<<(s[u]-'a')]=0; 
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
	scanf("%d",&n); 
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	scanf("%s",s+1);
	ans=19260817,val=n,dfs1(1,0),dfs3(tmp);
	for(int i=1;i<=n;i++)
	printf("%lld ",Ans[i]+1);
}