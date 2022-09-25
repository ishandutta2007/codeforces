#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define N 1550
#define mod 998244353
#define ul unsigned int
int n,v[N][N],tp[N],st[N],s1[N][N],ls[N],fu[N][N],is[N*2],dp[N*2][N],ct,head[N*2],cnt,sz[N*2];
ul vl[N],su[N][N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
void dfs(int u)
{
	if(u>n)dp[u][0]=1;
	for(int i=head[u];i;i=ed[i].next)
	{
		dfs(ed[i].t);
		for(int j=0;j<=sz[u]+sz[ed[i].t];j++)tp[j]=0;
		for(int j=0;j<=sz[u];j++)
		for(int k=0;k<=sz[ed[i].t];k++)
		tp[j+k]=(tp[j+k]+1ll*dp[u][j]*dp[ed[i].t][k])%mod;
		sz[u]+=sz[ed[i].t];
		for(int j=0;j<=sz[u];j++)dp[u][j]=tp[j];
	}
	dp[u][1]=1;
}
bool cmp(int a,int b){return tp[a]<tp[b];}
map<ul,int> mp[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&v[i][j]);
	vl[0]=1;for(int i=1;i<=n;i++)vl[i]=19260817*vl[i-1]+998244353;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)st[j]=j,tp[j]=v[i][j];
		sort(st+1,st+n+1,cmp);sort(v[i]+1,v[i]+n+1);
		for(int j=1;j<=n;j++)s1[i][j]=st[j],su[i][j]=su[i][j-1]+vl[st[j]],mp[j][su[i][j]]++;
	}
	ct=n;for(int i=1;i<=n;i++)sz[i]=1,ls[i]=i;
	for(int i=2;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!fu[i][j]&&mp[i][su[j][i]]>=i)
	{
		int fg=1;
		for(int t=1;t<=i;t++)fu[i][s1[j][t]]=1;
		for(int t=1;t<=i;t++)if(su[s1[j][t]][i]!=su[j][i])fg=0;
		int mx=0;
		for(int t=1;t<=i;t++)if(mx<v[s1[j][t]][i])mx=v[s1[j][t]][i];
		if(i<n)for(int t=1;t<=i;t++)if(mx>v[s1[j][t]][i+1])fg=0;
		if(!fg)continue;
		++ct;
		for(int t=1;t<=i;t++)if(!is[ls[s1[j][t]]])is[ls[s1[j][t]]]=1,adde(ct,ls[s1[j][t]]);
		for(int t=1;t<=i;t++)ls[s1[j][t]]=ct;
	}
	dfs(ct);
	for(int i=1;i<=n;i++)printf("%d ",dp[ct][i]);
}