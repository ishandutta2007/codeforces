#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, k;
int a[N], b[N][N];
int cache[N][N][N];

int dp(int i, int col, int len)
{
	if(len<0)
		return 1e15;
	if(i==n+1)
	{
		if(len==0)
			return 0;
		return 1e15;
	}
	int &ans=cache[i][col][len];
	if(ans!=-1)
		return ans;
	ans=1e15;
	if(a[i]==0)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=col)
				ans=min(ans, b[i][j] + dp(i+1, j, len-1));
			else
				ans=min(ans, b[i][j] + dp(i+1, j, len));
		}
	}
	else if(a[i]!=col)
		ans=min(ans, dp(i+1, a[i], len-1));
	else
		ans=min(ans, dp(i+1, a[i], len));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}
	int ans=1e15;
	if(a[1]==0)
	{
		for(int j=1;j<=m;j++)
		{
			ans=min(ans, b[1][j] + dp(2, j, k-1));
		}
	}
	else
		ans=dp(1, a[1], k-1);
	if(ans>=1e14)
		ans=-1;
	cout<<ans;
	return 0;
}