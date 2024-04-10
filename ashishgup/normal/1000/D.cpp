#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;
const int MOD=998244353;

int n;
int a[N], cache[N][N];

int dp(int i, int prev)
{
	if(i==n+1)
		return prev==0;
	int &ans=cache[i][prev];
	if(ans!=-1)
		return ans;
	ans=dp(i+1, prev);
	if(prev>0)
		ans+=dp(i+1, prev-1);
	else
	{
		if(a[i]>=1 && a[i]<=n)
			ans+=dp(i+1, a[i]);
	}
	ans%=MOD;
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
	ans=(ans-1+MOD)%MOD;
	cout<<ans;
	return 0;
}