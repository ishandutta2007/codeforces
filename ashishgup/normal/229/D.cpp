#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n;
int a[N], pref[N], cache[N][N];

int dp(int idx, int prev)
{
	if(idx==n+1)
		return 0;
	int &ans=cache[idx][prev];
	if(ans!=-1)
		return ans;
	ans=1 + dp(idx+1, prev+1);
	int prevsum=pref[idx-1] - pref[idx-prev-1];
	auto it=lower_bound(pref+idx, pref+n+2, pref[idx-1] + prevsum) - pref;
	if(it!=n+1)
		ans=min(ans, it-idx + dp(it+1, it-idx+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	pref[n+1]=1e18;
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}