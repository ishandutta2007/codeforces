#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],dp[100005][4];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		cin >> x;
		for(int i=1;i<=n;i++)
			a[i]-=x,dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=-1e18;
		for(int i=1;i<=n;i++)
		{
			if(i>=2&&a[i]+a[i-1]>=0)
				dp[i][3]=max(dp[i-1][1]+1,dp[i][3]);
			if(i>=3&&a[i]+a[i-1]+a[i-2]>=0&&a[i]+a[i-1]>=0)
				dp[i][3]=max(dp[i][3],dp[i-1][3]+1);
			dp[i][0]=max(dp[i][0],dp[i-1][0]);
			dp[i][0]=max(dp[i][0],dp[i-1][2]); 
			dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
			dp[i][1]=max(dp[i][1],dp[i-1][2]+1);
			dp[i][2]=max(dp[i][2],dp[i-1][1]);
			dp[i][2]=max(dp[i][2],dp[i-1][3]);
		}
		cout << max(dp[n][0],max(dp[n][1],max(dp[n][2],dp[n][3]))) << "\n";
	}
	return 0;
}