#include<cstdio>
using namespace std;
#define N 150050
#define ll long long
int T,n,m;
int s[N][2],is[N],rs[N],head[N],cnt,dp[N][2];
struct edge{int t,next;}ed[N];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
ll solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)is[i]=rs[i]=head[i]=dp[i][0]=dp[i][1]=0;cnt=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&s[i][0],&s[i][1]);
		if(s[i][1]==s[i][0]+1)is[s[i][0]]=1;
	}
	rs[n]=n;for(int i=n-1;i>=1;i--)rs[i]=is[i]?rs[i+1]:i;
	if(rs[1]==n)return 1ll*n*(n-1)/2;
	for(int i=1;i<=m;i++)if(s[i][1]>s[i][0]+1&&rs[s[i][0]+1]>=s[i][1]-1)adde(s[i][0],s[i][1]-1);
	int lb=0,rb=0;
	for(int i=n;i>=1;i--)if(!is[i])lb=i;
	for(int i=1;i<n;i++)if(!is[i])rb=i;
	int fg=0,ls=lb;
	for(int i=lb+1;i<=rb;i++)if(!is[i])
	{
		dp[ls][0]=1;dp[ls][1]=0;
		for(int t=ls;t<i;t++)for(int j=head[t];j;j=ed[j].next)for(int k=0;k<2;k++)dp[ed[j].t][k]|=dp[t][k^1];
		int sv=dp[i][0]+dp[i][1]*2;
		if(!sv)return 0;
		if(sv==3||fg==-1)fg=-1;else fg^=sv-1;
	}
	dp[lb][0]=1;dp[lb][1]=0;dp[rb][0]=1;dp[rb][1]=0;
	for(int i=lb-1;i>=1;i--)for(int j=head[i];j;j=ed[j].next)for(int k=0;k<2;k++)dp[i][k]|=dp[ed[j].t][k^1];
	for(int i=rb;i<n;i++)for(int j=head[i];j;j=ed[j].next)for(int k=0;k<2;k++)dp[ed[j].t][k]|=dp[i][k^1];
	ll c[4]={0,0,0,0},d[4]={0,0,0,0},as=0;
	for(int i=1;i<=lb;i++)c[dp[i][0]+dp[i][1]*2]++;
	for(int i=rb;i<n;i++)d[dp[i][0]+dp[i][1]*2]++;
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)if(i==3||j==3||fg==-1||((i-1)^(j-1)==fg))as+=c[i]*d[j];
	if(as)as++;if(lb==rb)as--;
	for(int i=1;i<=3;i++)
	{
		if(i==3||fg==-1||d[((i-1)^fg^1)+1]||d[3])as+=c[i];
		if(i==3||fg==-1||c[((i-1)^fg^1)+1]||c[3])as+=d[i];
	}
	return as;
}
int main()
{
	scanf("%d",&T);
	while(T--)printf("%lld\n",solve());
}