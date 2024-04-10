#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, charged=0;
int a[N], cache[N];

int dp(int idx)
{
	if(idx==0)
		return 0;
	int &ans=cache[idx];
	if(ans!=-1)
		return ans;
	ans=20+dp(idx-1);
	int prev=upper_bound(a, a+idx+1, a[idx]-90) - a - 1;
	ans=min(ans, 50+dp(prev));
	int prev2=upper_bound(a, a+idx+1, a[idx]-1440) - a - 1;
	ans=min(ans, 120+dp(prev2));	
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
		cout<<dp(i)-charged<<endl;
		charged+=(dp(i)-charged);
	}
	return 0;
}