#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=1e9+7;

int n, l, r;
int f[5], cache[N][3];

int dp(int idx, int rem)
{
	if(idx==n+1)
		return (rem==0);
	int &ans=cache[idx][rem];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int cur=0;cur<=2;cur++)
		ans+=(f[cur] * dp(idx+1, (rem+cur)%3));
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>l>>r;
	while((r-l+1)%3>0)
	{
		f[l%3]++;
		l++;
	}
	int len=(r-l+1)/3;
	f[0]+=len, f[1]+=len, f[2]+=len;
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}