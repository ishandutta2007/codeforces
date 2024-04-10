#include<cstdio>
#include<algorithm>
int dp[33333][222][3][2];
int n,k,a[33333];
using std::max;
int main()
{
	scanf("%d%d",&n,&k);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=0;i<=n;i++)
		for(ii=0;ii<=k;ii++)
			dp[i][ii][0][0]=dp[i][ii][1][0]=dp[i][ii][2][0]=
			dp[i][ii][0][1]=dp[i][ii][1][1]=dp[i][ii][2][1]=-1e9;
	for(i=0;i<=n;i++)dp[i][0][1][1]=dp[i][0][2][0]=0;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=k;ii++)
		{
			dp[i][ii][0][0]=max(
			max(dp[i-1][ii][0][0],dp[i-1][ii-1][0][0]),dp[i-1][ii-1][1][1]);
			dp[i][ii][0][1]=max(
			max(dp[i-1][ii][0][1],dp[i-1][ii-1][0][1]),dp[i-1][ii-1][2][0]);
			dp[i][ii][1][1]=max(dp[i-1][ii][1][1],
			max(dp[i-1][ii-1][2][0],dp[i-1][ii-1][0][1]));
			dp[i][ii][2][0]=max(dp[i-1][ii][2][0],
			max(dp[i-1][ii-1][1][1],dp[i-1][ii-1][0][0]));
			if(ii==1||ii==k)dp[i][ii][1][1]+=a[i],dp[i][ii][2][0]-=a[i],
			dp[i][ii][0][0]=dp[i][ii][0][1]=-1e9;
			else dp[i][ii][1][1]+=2*a[i],dp[i][ii][2][0]-=2*a[i];
		}
	int ans=-1e9;
	for(i=1;i<=n;i++)
		ans=std::max(ans,std::max(dp[i][k][1][1],dp[i][k][2][0]));
	printf("%d\n",ans);
}
/*
Please don't let me down.
*/