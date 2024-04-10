#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, m, k;
int a[N], pref[N];
int cache[N][N];

int dp(int idx, int taken)
{
	if(taken==k)
		return 0;
	if(idx==n+1)
		return -1e15;
	int &ans=cache[idx][taken];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, taken);
	if(idx+m-1<=n)
		ans=max(ans, pref[idx+m-1] - pref[idx-1] + dp(idx+m, taken+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}