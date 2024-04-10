#include<cstdio>
#include<algorithm>
using namespace std;
#define N 4050
#define ll long long
int n,m,v[N],st[N],head[N],cnt,sz[N],ct;
ll dp[N][N],v2[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t)
{
	ed[++cnt]=(edge){t,head[f]};head[f]=cnt;
	ed[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void dfs(int u,int fa)
{
	sz[u]=0;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u);
		for(int j=0;j<=sz[u]+sz[ed[i].t];j++)v2[j]=-1e18;
		for(int j=0;j<=sz[u];j++)for(int k=0;k<=sz[ed[i].t];k++)
		v2[j+k]=max(v2[j+k],dp[u][j]+dp[ed[i].t][k]-2ll*v[u]*j*k);
		sz[u]+=sz[ed[i].t];
		for(int j=0;j<=sz[u];j++)dp[u][j]=v2[j];
	}
	dp[u][sz[u]+1]=-1e18;
	for(int j=sz[u]+1;j>=1;j--)dp[u][j]=max(dp[u][j],dp[u][j-1]+1ll*v[u]*(m-2*j+1));
	sz[u]++;
}
int build(int l,int r)
{
	int fr=l;
	for(int i=l;i<=r;i++)if(v[i]<v[fr])fr=i;
	if(l<fr)adde(fr,build(l,fr-1));
	if(fr<r)adde(fr,build(fr+1,r));
	return fr;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	int tp=build(1,n);
	dfs(tp,0);printf("%lld\n",dp[tp][m]);
}