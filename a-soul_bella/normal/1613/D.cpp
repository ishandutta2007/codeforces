#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int cnt[500005],a[500005],dp[500005][2];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=0;i<=n+2;i++)
			cnt[i]=0,dp[i][0]=dp[i][1]=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			++cnt[a[i]];
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			dp[a[i]+1][0]=(dp[a[i]+1][0]+dp[a[i]+1][0])%mod;
			dp[a[i]+1][1]=(dp[a[i]+1][1]+dp[a[i]+1][1])%mod;
			dp[a[i]+1][0]=(dp[a[i]+1][0]+dp[a[i]][0])%mod;
			if(a[i])
			{
				dp[a[i]-1][1]=(dp[a[i]-1][1]+dp[a[i]-1][1])%mod;
				dp[a[i]-1][1]=(dp[a[i]-1][1]+dp[a[i]-1][0])%mod;
			}
		}
		int ans=0;
		for(int i=0;i<=n+2;i++)
			ans+=dp[i][0]+dp[i][1];
		cout << (ans+mod-1)%mod << "\n";
	}
	return 0;
}