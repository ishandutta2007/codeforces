#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=998244353;

int n, ans;
int a[N], dp[N][201][2];

/*int dp(int idx, int prev, int taken)
{
	if(prev<1)
		return 0;
	if(idx==n+1)
		return prev;
	int &ans=cache[idx][prev][taken];
	if(ans!=-1)
		return ans;
	ans=0;
	int lower=1, higher=200;
	if(idx==2 || !taken)
		lower=prev;
	if(idx==n)
		higher=prev;
	if(a[idx]!=-1)
	{
		if(a[idx]>=lower && a[idx]<=higher)
			ans=dp(idx+1, a[idx], a[idx]<=prev) - dp(idx+1, a[idx]-1, a[idx]<=prev) + MOD;
	}
	else
	{
		if(prev<lower || prev>higher)
			ans+=dp(idx+1, higher, lower<=prev) -dp(idx+1, lower-1, lower<=prev) + MOD;
		else
		{
			ans+=dp(idx+1, prev, 1) - dp(idx+1, lower-1, 1) + MOD;
			ans+=dp(idx+1, higher, 0) - dp(idx+1, prev, 0) + MOD;
		}
	}
	ans+=dp(idx, prev-1, taken);
	ans%=MOD;
	return ans;
}*/

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int prev=1;prev<=200;prev++)
		for(int taken=0;taken<=1;taken++)
			dp[n+1][prev][taken]=prev;
	for(int idx=n;idx>=1;idx--)
	{
		for(int prev=1;prev<=200;prev++)
		{
			for(int taken=0;taken<=1;taken++)
			{
				int &ans=dp[idx][prev][taken];
				int lower=1, higher=200;
				if(idx==2 || !taken)
					lower=prev;
				if(idx==n)
					higher=prev;
				if(a[idx]!=-1)
				{
					if(a[idx]>=lower && a[idx]<=higher)
						ans=dp[idx+1][a[idx]][a[idx]<=prev] - dp[idx+1][a[idx]-1][a[idx]<=prev] + MOD;
				}
				else
				{
					if(prev<lower || prev>higher)
						ans+=dp[idx+1][higher][lower<=prev] -dp[idx+1][lower-1][lower<=prev] + MOD;
					else
					{
						ans+=dp[idx+1][prev][1] - dp[idx+1][lower-1][1] + MOD;
						ans+=dp[idx+1][higher][0] - dp[idx+1][prev][0] + MOD;
					}
				}
				ans+=dp[idx][prev-1][taken];
				ans%=MOD;
			}
		}
	}
	if(a[1]!=-1)
		ans=dp[2][a[1]][0]-dp[2][a[1]-1][0]+MOD;
	else
	{
		for(int i=1;i<=200;i++)
			ans+=dp[2][i][0]-dp[2][i-1][0]+MOD;
	}
	ans%=MOD;
	cout<<ans;
	return 0;
}