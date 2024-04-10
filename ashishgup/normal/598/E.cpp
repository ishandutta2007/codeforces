#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int cache[31][31][51];

int dp(int x, int y, int k)
{
	if(x*y < k)
		return 1e9;
	if(k<0)
		return 1e9;
	if(k==0)
		return 0;
	if(x*y == k)
		return 0;
	int &ans=cache[x][y][k];
	if(ans!=-1)
		return ans;
	ans=1e9;
	for(int i=1;i<=x-1;i++)
	{
		for(int j=0;j<=k;j++)
		{
			ans=min(ans, y*y + dp(i, y, j) + dp(x-i, y, k-j));
		}
	}
	for(int i=1;i<=y-1;i++)
	{
		for(int j=0;j<=k;j++)
		{
			ans=min(ans, x*x + dp(x, i, j) + dp(x, y-i, k-j));
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	int q;
	cin>>q;
	while(q--)
	{
		int n, m, k;
		cin>>n>>m>>k;
		cout<<dp(n, m, k)<<endl;
	}
	return 0;
}