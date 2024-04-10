#include<cstdio>
#include<cstring>
char str[222222];
int n;
typedef long long ll;
const ll mod=998244353;
ll dp[2222][2222][2][2];
ll sum[2222],pw2[2222];
int main()
{
	scanf("%s",str+1);
	register int i,ii;
	pw2[0]=1;
	for(i=1;str[i+1];i++)
		if(str[i]!=')'&&str[i+1]!='(')dp[i][i+1][0][1]=1;
	n=i;
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+(str[i]=='?'),pw2[i]=(pw2[i-1]*2)%mod;
	for(i=2;i<n;i++)
		for(ii=1;ii+i<=n;ii++)
		{
			int l=ii,r=ii+i;
			ll ls=dp[l+1][r-1][0][0]+dp[l+1][r-1][0][1]+dp[l+1][r-1][1][0]+
			dp[l+1][r-1][1][1];
			if(str[l]!=')'&&str[r]!='(')dp[l][r][0][1]+=ls+pw2[sum[r-1]-sum[l]];
			if(str[l]!='('&&str[r]!=')')dp[l][r][1][0]+=ls;
			if(str[l]!=')'&&str[r]!=')')dp[l][r][0][0]+=dp[l][r-1][0][1]+dp[l][r-1][0][0];
			if(str[l]!='('&&str[r]!='(')dp[l][r][1][1]+=dp[l+1][r][0][1]+dp[l+1][r][1][1];
			dp[l][r][0][0]%=mod;
			dp[l][r][0][1]%=mod;
			dp[l][r][1][0]%=mod;
			dp[l][r][1][1]%=mod;
		}
	printf("%I64d\n",(dp[1][n][0][0]+dp[1][n][0][1]+dp[1][n][1][0]+dp[1][n][1][1])%mod);
}
/*
Living is forgiving.
*/