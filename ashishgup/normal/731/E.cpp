#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], pref[N], storebest[N][2], dp[N][2];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	storebest[n+1][0]=storebest[n+1][1]=-1e18;
	for(int i=n;i>=2;i--)
	{
		for(int player=0;player<=1;player++)
		{
			int &ans=dp[i][player];
			ans=-1e18;
			storebest[i][player]=storebest[i+1][player];
			storebest[i][player]=max(storebest[i][player], pref[i] - dp[i+1][player^1]);
			ans=max(ans, storebest[i][player]);
		}
	}
	dp[1][0]=storebest[2][0];
	int ans=dp[1][0];
	cout<<ans;
	return 0;   
}