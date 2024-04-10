#include<cstdio>
#include<algorithm>
using namespace std;
#define N 234567
struct edge{int t,next;}ed[N];
int head[N],cnt,vl[N][4],n,a,b,in[N],fr[N][4][4],as1[N],tp[N],ct;long long dp[N][4][4];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs(int u,int fa)
{
	tp[++ct]=u;
	for(int i=0;i<=3;i++)
	for(int j=0;j<=3;j++)dp[u][i][j]=1e17;
	if(fa&&in[u]==1)
	{
		for(int i=1;i<=3;i++)dp[u][i][0]=vl[u][i];
		return;
	}
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u);
		for(int l=1;l<=3;l++)
		for(int j=0;j<=3;j++)
		for(int k=1;k<=3;k++)
		if(k!=l&&k!=j&&l!=j)
		if(dp[u][k][l]>dp[ed[i].t][l][j]+vl[u][k])
		dp[u][k][l]=min(dp[u][k][l],dp[ed[i].t][l][j]+vl[u][k]),fr[u][k][l]=j;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	for(int j=1;j<=n;j++)scanf("%d",&vl[j][i]);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b),in[a]++,in[b]++;
	for(int i=1;i<=n;i++)if(in[i]>2){printf("-1\n");return 0;}
	for(int i=1;i<=n;i++)if(in[i]==1)
	{
		dfs(i,0);
		long long as=1e17,t1,t2;
		for(int j=1;j<=3;j++)
		for(int k=1;k<=3;k++)
		if(as>dp[i][j][k])
		as=min(as,dp[i][j][k]),t1=j,t2=k;
		as1[tp[1]]=t1,as1[tp[2]]=t2;
		for(int j=2;j<n;j++)
		{
			int sb=fr[tp[j-1]][t1][t2];
			as1[tp[j+1]]=sb;
			t1=t2;t2=sb;
		}
		printf("%lld\n",as);
		for(int i=1;i<=n;i++)printf("%d ",as1[i]);
		return 0;
	}
}