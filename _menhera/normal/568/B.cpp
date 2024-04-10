#include<cstdio>
const int MAXN=4040;
const int MOD=1e9+7;
int dp[MAXN];
int comb[MAXN][MAXN];
int main()
{
	int N;
	scanf("%d",&N);
	comb[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
	}
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<N;i++)
	{
		dp[i]=0;
		for(int j=0;j<=i-1;j++)
			dp[i]=(dp[i]+1LL*comb[i-1][j]*dp[j])%MOD;
	}
	int ans=0;
	for(int i=1;i<=N;i++)
		ans=(ans+1LL*comb[N][i]*dp[N-i])%MOD;
	printf("%d",ans);
}