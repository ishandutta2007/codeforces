#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e7+5;

int n, x, y;
int dp[N];

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		if(i%2)
			dp[i]=min(dp[i-1]+x, dp[(i+1)/2]+x+y);
		else
			dp[i]=min(dp[i-1]+x, dp[i/2]+y);
	}
	cout<<dp[n];
	return 0;
}