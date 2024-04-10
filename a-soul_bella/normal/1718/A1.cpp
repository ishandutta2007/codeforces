#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],b[1000005],dp[5005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			b[i]=b[i-1]^a[i];
		}
		for(int i=1;i<=n;i++) dp[i]=0;
		for(int i=0;i<=n;i++)
		{
			if(i) dp[i]=max(dp[i],dp[i-1]);
			for(int j=i+1;j<=n;j++)
				if(b[i]==b[j]) dp[j]=max(dp[j],dp[i]+1);
		}
		cout << n-dp[n] << "\n";
	}
	return 0;
}