#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], cache[N][2], vis[N][2];

int dp(int idx, int parity)
{
	if(idx==n+1)
	{
		if(!parity)
			return -1e10;
		return 0;
	}
	int &ans=cache[idx][parity];
	if(vis[idx][parity])
		return ans;
	vis[idx][parity]=1;
	ans=max(dp(idx+1, parity), a[idx] + dp(idx+1, (parity+abs(a[idx]))%2));
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0);
	cout<<ans;	
	return 0;
}