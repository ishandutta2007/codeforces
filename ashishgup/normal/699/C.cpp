#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
int a[N], cache[N][2][2];

int dp(int i, int sport, int contest)
{
	if(i>n)
		return 0;
	if(cache[i][sport][contest]!=-1)
		return cache[i][sport][contest];
	int ans;
	if(a[i]==0)
	{
		ans=1+dp(i+1, 0, 0);
	}
	else if(a[i]==1)
	{
		if(contest)
		{
			ans=1+dp(i+1, 0, 0);
		}
		else
		{
			ans=min(1+dp(i+1, 0, 0), dp(i+1, 0, 1));
		}
	}
	else if(a[i]==2)
	{
		if(sport)
		{
			ans=1+dp(i+1, 0, 0);
		}
		else
		{
			ans=min(1+dp(i+1, 0, 0), dp(i+1, 1, 0));
		}
	}
	else
	{
		if(sport)
		{
			ans=min(1+dp(i+1, 0, 0), dp(i+1, 0, 1));
		}
		else if(contest)
		{
			ans=min(1+dp(i+1, 0, 0), dp(i+1, 1, 0));
		}
		else
		{
			ans=min(dp(i+1, 1, 0), min(dp(i+1, 0, 1), 1+dp(i+1, 0, 0)));
		}
	}
	cache[i][sport][contest]=ans;
	return cache[i][sport][contest];
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=dp(1, 0, 0);
	cout<<ans<<endl;
}