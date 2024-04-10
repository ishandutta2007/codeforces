#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, r, cur;
int a[N], cache[N][2*N];

int dp(int idx, int gap)
{
	if(gap>r)
		return 1e9;
	if(idx==n)
	{
		if(gap>0 && a[idx]==1)
			return 1;
		if(gap>0 && !a[idx])
			return 1e9;
		return 0;
	}
	int &ans=cache[idx][gap+N];
	if(ans!=-1)
		return ans;
	if(a[idx]==1)
		ans=min(dp(idx+1, gap+1), 1+dp(idx+1, -r+2));
	else
		ans=dp(idx+1, gap+1);
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 1);
	if(ans>n)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}