#include<cstdio>
#include<cstring>
using namespace std;
#define mod 998244353
int n,m,s[6][2],dp[32][20][20][20][20][2][2];
int dfs(int d,int s1,int s2,int t1,int t2,int f1,int f2)
{
	if(d>30)return !f1&&!f2&&!s1&&!s2&&!t1&&!t2;
	if(dp[d][s1][s2][t1][t2][f1][f2]!=-1)return dp[d][s1][s2][t1][t2][f1][f2];
	int as=0;
	for(int i=0;i<1<<n;i++)
	{
		int p1=s1,p2=s2,q1=t1,q2=t2;
		for(int j=1;j<=n;j++)if(i&(1<<j-1))
		{
			if(s[j][0]>=0)p1+=s[j][0];else p2-=s[j][0];
			if(s[j][1]>=0)q1+=s[j][1];else q2-=s[j][1];
		}
		if(((p1^p2)&1)||((q1^q2)&1))continue;
		int v1=p1&1,v2=q1&1,nt1=f1,nt2=f2,tp=(m>>d)&1;
		if(v1>tp)nt1=1;if(v1<tp)nt1=0;
		if(v2>tp)nt2=1;if(v2<tp)nt2=0;
		as=(as+dfs(d+1,p1>>1,p2>>1,q1>>1,q2>>1,nt1,nt2))%mod;
	}
	return dp[d][s1][s2][t1][t2][f1][f2]=as;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i][0],&s[i][1]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",(dfs(0,0,0,0,0,0,0)+mod-1)%mod);
}