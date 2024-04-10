#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int n, A, B;
int a[N], pref[N], cache[N][2][N*N];

int dp(int idx, int prev, int rema)
{
	if(idx==n+1)
		return 0;
	int remb=B - (pref[idx-1] - (A-rema));
	int &ans=cache[idx][prev][rema];
	if(ans!=-1)
		return ans;
	ans=1e18;
	if(rema>=a[idx])
	{
		int cost=0;
		if(prev==1)
			cost=min(a[idx-1], a[idx]);
		ans=min(ans, cost + dp(idx+1, 0, rema-a[idx]));
	}
	if(remb>=a[idx])
	{
		int cost=0;
		if(prev==0)
			cost=min(a[idx-1], a[idx]);
		ans=min(ans, cost + dp(idx+1, 1, rema));
	}
	return ans;
}

int32_t main()
{
	IOS;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(cache, -1, sizeof(cache));
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	int ans=1e18;
	if(A>=a[1])
		ans=min(ans, dp(2, 0, A-a[1]));
	if(B>=a[1])
		ans=min(ans, dp(2, 1, A));
	if(ans>1e15)
		ans=-1;
	cout<<ans;
	return 0;
}