#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;
const int MOD=1e9+7;

int n, h;
int a[N];
int cache[N][N];

int dp(int idx, int open)
{	
	if(idx==n+1)
		return (open==0);
	int &ans=cache[idx][open];
	if(ans!=-1)
		return ans;
	ans=0;
	if(a[idx]+open==h)
	{
		ans=dp(idx+1, open);
		if(open>=1)
			ans+=(open*dp(idx+1, open-1));
	}
	if(a[idx]+open+1==h)
		ans+=dp(idx+1, open+1)+(open*dp(idx+1, open))+dp(idx+1, open);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>h;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0);
	cout<<ans;
	return 0;
}