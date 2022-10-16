#include<cstdio>
#include<cstring>
#include<algorithm>
#define reply fflush(stdout)
#define retrun return
#define cpnst const
#define inlien inline
typedef long long ll;
typedef double db;
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
inline ll max(ll x,ll y)
{return(x>y)?x:y;}
int n;
int a[1111111];
int x[111111],y[111111];
struct edg
{int p,t;}e[222222];
int tot,h[1111111],fa[1111111],siz[1111111];
inline void build(int x,int y)
{e[++tot]=(edg){h[x],y},h[x]=tot;}
#include<vector>
std::vector<int>vx[3333],vy[3333];
int dis[3333][3333],dir[3333][3333];
void dfs(int p=1,int f=0,int s=1,int d=0)
{
	dir[p][s]=f;
	if(s>p)
	{
		vx[d].push_back(p),vy[d].push_back(s);
	}
	if(s==1)siz[p]=1,fa[p]=f;
	for(register int i=h[p];i;i=e[i].p)
	{
		int to=e[i].t;
		if(to==f)continue;
		dfs(to,p,s,d+1),siz[p]+=siz[to];
	}
}
ll ans=0;
int px,py;
ll dp[3333][3333];
void exec()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<n;i++)scanf("%d%d",x+i,y+i),
	build(x[i],y[i]),build(y[i],x[i]);
	for(i=2;i<=n;i++)dfs(i,0,i,0);
	dfs();
	for(i=1;i<n;i++)
	{
		if(fa[x[i]]==y[i])
			dp[x[i]][y[i]]=dp[y[i]][x[i]]=
			siz[x[i]]*(n-siz[x[i]]);
		else dp[x[i]][y[i]]=dp[y[i]][x[i]]=
			siz[y[i]]*(n-siz[y[i]]);
	}
	ll s=0;
	register int ii;
	for(ii=2;ii<n;ii++)
	{
		for(i=0;i<vx[ii].size();i++)
		{
			int lp=vx[ii][i],rp=vy[ii][i];
			int lpp=dir[lp][rp],rpp=dir[rp][lp];
			int ls,rs;
			if(lpp==fa[lp])ls=siz[lp];
			else ls=n-siz[lpp];
			if(rpp==fa[rp])rs=siz[rp];
			else rs=n-siz[rpp];
			//int lpt=dir[lpp][rp],rpt=dir[rpp][lp];
			//if(lpt==fa[lpp])lss=siz[lpp];
			//else lss=n-siz[lpt];
			//if(rpt==fa[rpp])rss=siz[rpp];
			//else rss=n-siz[rpt];
			//printf("%d %d %d %d %d %d\n",lp,rp,lpp,rpp,ls,rs);
			dp[lp][rp]=dp[rp][lp]=max(
			dp[lpp][rp]+ls*rs,
			dp[lp][rpp]+rs*ls);
			
			//printf("%d %d %lld\n",lp,rp,dp[lp][rp]);
		}
	}
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)
			if(dp[i][ii]>s)
				s=dp[i][ii];
				
	printf("%lld\n",s);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/