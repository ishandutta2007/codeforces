#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (2010)
#define SQ (45)
#define MOD ((ll)1e9+7)

int n,k;
ll dp[2][N][N];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>s;
	dp[0][n][0]=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=k;j++)
		{
			dp[0][i][j]+=(s[i]-'a')*(dp[0][i+1][j]+dp[1][i+1][j]);
			dp[0][i][j]+=dp[0][i+1][j];
			dp[0][i][j]%=MOD;
			for(int p=i;p<min(n,i+SQ);p++)
			{
				if((p-i+1)*(n-p)>j)continue;
				dp[1][i][j]+=('z'-s[p])*(dp[0][p+1][j-(p-i+1)*(n-p)]+dp[1][p+1][j-(p-i+1)*(n-p)]);
			}
			for(int p=n-1;p>=max(min(n,i+SQ),n-SQ);p--)
			{
				if((p-i+1)*(n-p)>j)continue;
				dp[1][i][j]+=('z'-s[p])*(dp[0][p+1][j-(p-i+1)*(n-p)]+dp[1][p+1][j-(p-i+1)*(n-p)]);
			}
			dp[1][i][j]%=MOD;
		}
	}
	cout<<(dp[0][0][k]+dp[1][0][k])%MOD;
	return 0;
}