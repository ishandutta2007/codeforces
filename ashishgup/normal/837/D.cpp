#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=205;

int n, k;
int twos[N], fives[N];
int dp[2][N][26*N];
/*
int cache[N][N][26*N];

int dp(int i, int taken, int five)
{
	if(five<0)
		return -1e6;
	if(i==0&&five==0)
		return 0;
	if(i==0)
		return -1e6;
	if(taken==k&&five==0)
		return 0;
	if(taken==k)
		return -1e6;
	int &ans=cache[i][taken][five];
	if(ans!=-1)
		return ans;
	ans=max(twos[i] + dp(i-1, taken+1, five-fives[i]), dp(i-1, taken, five));
	return ans;
}*/

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		while(k%2==0)
		{
			k/=2;
			twos[i]++;
		}
		while(k%5==0)
		{
			k/=5;
			fives[i]++;
		}
	}
	for(int taken=0;taken<N;taken++)
	{
		for(int five=0;five<26*N;five++)
		{
			if(taken==k)
			{
				if(!five)
					dp[0][taken][five]=0;
				else
					dp[0][taken][five]=-1e9;
			}
			else
				dp[0][taken][five]=-1e9;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int taken=0;taken<k;taken++)
		{
			for(int five=0;five<26*n;five++)
			{
				int &ans=dp[i&1][taken][five];
				ans=dp[!(i&1)][taken][five];
				if(five-fives[i]<0)
					continue;
				ans=max(twos[i] + dp[!(i&1)][taken+1][five-fives[i]], ans);
			}
		}
		dp[i&1][k][0]=0;
		for(int five=1;five<26*N;five++)
			dp[i&1][k][five]=-1e9;
	}
	int ans=0;
	for(int i=1;i<=26*n;i++)
		ans=max(ans, min(i, dp[n&1][0][i]));
	cout<<ans;
	return 0;
}