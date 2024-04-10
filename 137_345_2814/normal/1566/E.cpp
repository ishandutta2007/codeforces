#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200500
int T,n,a,b,head[N],cnt,dp[N],su[N],as;
struct edge{int t,next;}ed[N*2];
void adde(int f,int t)
{
	ed[++cnt]=(edge){t,head[f]};head[f]=cnt;
	ed[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void dfs0(int u,int fa)
{
	dp[u]=0;su[u]=0;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs0(ed[i].t,u),dp[u]|=!dp[ed[i].t],su[u]+=su[ed[i].t];
	su[u]+=2*dp[u];
}
void dfs1(int u,int fa,int vl)
{
	if(as<vl)as=vl;
	vl+=su[u]-2*dp[u];
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs1(ed[i].t,u,vl+1-su[ed[i].t]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)head[i]=0;cnt=as=0;
		for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
		dfs0(1,0);dfs1(1,0,0);
		printf("%d\n",n-as);
	}
}