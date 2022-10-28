#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];
string s;
int cache[N][2][3];

int dp(int i, int prev, int flipped)
{
	if(i==n)
		return 0;
	int &ans=cache[i][prev][flipped];
	if(ans!=-1)
		return ans;
	if(flipped==0)
	{
		if(a[i]^prev)
		{
			ans=max(1+dp(i+1, a[i], 0), 1+dp(i+1, a[i], 1));
			ans=max(ans, dp(i+1, prev, flipped));
			ans=max(ans, dp(i+1, prev, 1));
		}
		else
			ans=max(dp(i+1, prev, 0), dp(i+1, prev, 1));
	}
	else if(flipped==1)
	{
		if(a[i]==prev)
		{
			ans=max(1+dp(i+1, a[i]^1, 1), 1+dp(i+1, a[i]^1, 2));
			ans=max(ans, dp(i+1, prev, 1));
			ans=max(ans, dp(i+1, prev, 2));
		}
		else
			ans=max(dp(i+1, prev, 1), dp(i+1, prev, 2));

	}
	else
	{
		if(a[i]^prev)
			ans=max(1+dp(i+1, a[i], 2), dp(i+1, prev, 2));
		else
			ans=dp(i+1, prev, 2);
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>s;
	for(int i=0;i<n;i++)
		a[i]=s[i]-'0';
	int ans=max(dp(0, 0, 0), dp(0, 1, 0));
	int ans2=max(dp(0, 0, 1), dp(0, 1, 1));
	cout<<max(ans, ans2);
	return 0;
}