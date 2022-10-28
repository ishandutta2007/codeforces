#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int a[N];
int cache[N][N];

int dp(int idx, int curh)
{
	if(idx==n+1)
		return 0;
	int &ans=cache[idx][curh];
	if(ans!=-1)
		return ans;
	ans=(a[idx]>curh)+dp(idx+1, min(a[idx], curh));
	if(a[idx]<=n)
		ans=min(ans, max(0, a[idx]-curh) + dp(idx+1, a[idx]));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}