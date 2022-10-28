#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=205;
const int MOD=1e9+7;

int n, k;
int a[N];
int cache[201][201][1001];

int dp(int idx, int open, int imbalance)
{
	if(imbalance>k)
		return 0;
	if(idx==n+1)
		return (open==0);
	int &ans=cache[idx][open][imbalance];
	if(ans!=-1)
		return ans;
	ans=0;
	int extra=open*(a[idx]-a[idx-1]);
	if(open>=1)
		ans+=(1LL*open*dp(idx+1, open-1, imbalance+extra))%MOD;
	ans+=dp(idx+1, open+1, imbalance+extra);
	ans%=MOD;
	ans+=(1LL*open*dp(idx+1, open, imbalance+extra))%MOD;
	ans%=MOD;
	ans+=dp(idx+1, open, imbalance+extra);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int ans=dp(1, 0, 0);
	cout<<ans;
	return 0;
}