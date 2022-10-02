#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int dp[2005][2005];
const int inv2=(1000000007+1)/2;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		for(int i=1;i<=n;i++) dp[i][0]=i;
		for(int i=1;i<=n;i++) dp[0][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=((dp[i][j-1]-dp[i-1][j]+mod)*inv2+dp[i-1][j])%mod;
			}
		}
		cout << dp[m][n-m]*k%mod << "\n";
	}
	return 0;
}