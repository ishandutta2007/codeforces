#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N], f[N];
int cache[N][3][3];

int dp(int idx, int x, int y)
{
	if(f[idx]-x-y<0)
		return -1e9;
	if(idx==m+1)
		return 0;
	int &ans=cache[idx][x][y];
	if(ans!=-1)
		return ans;
	int freq=f[idx]-x-y;
	ans=-1e9;
	for(int take=0;take<=min(2LL, freq);take++)
		ans=max(ans, dp(idx+1, y, take) + take + (freq-take)/3);	
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	int ans=dp(1, 0, 0);
	cout<<ans;
	return 0;
}