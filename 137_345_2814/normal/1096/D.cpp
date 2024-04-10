#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,dp[100050][5],v[100050];
char t[10]="%hard",s[100050];
int main()
{
	scanf("%lld%s",&n,s+1);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++)
	for(int j=0;j<4;j++)
	{
		if(s[i]==t[j+1])
		dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]),dp[i+1][j]=min(dp[i+1][j],dp[i][j]+v[i]);
		else
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
	}
	long long ans=0x3f3f3f3f3f3f3f3fll;
	for(int i=0;i<4;i++)
	ans=min(ans,dp[n+1][i]);
	printf("%lld\n",ans);
}