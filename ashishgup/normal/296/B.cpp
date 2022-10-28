#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n;
string a, b;
int cache[N][2][2];

int dp(int idx, int c1, int c2)
{	
	if(idx==n)
		return (c1&c2);
	int &ans=cache[idx][c1][c2];
	if(ans!=-1)
		return ans;
	ans=0;
	if(a[idx]=='?' && b[idx]=='?')
	{
		ans+=45*dp(idx+1, c1, 1);
		ans+=45*dp(idx+1, 1, c2);
		ans+=10*dp(idx+1, c1, c2);
		ans%=MOD;
	}
	else if(a[idx]=='?')
	{
		int dig=b[idx]-'0';
		ans+=dig*dp(idx+1, c1, 1);
		ans+=(9-dig)*dp(idx+1, 1, c2);
		ans+=dp(idx+1, c1, c2);
		ans%=MOD;
	}
	else if(b[idx]=='?')
	{
		int dig=a[idx]-'0';
		ans+=(9-dig)*dp(idx+1, c1, 1);
		ans+=dig*dp(idx+1, 1, c2);
		ans+=dp(idx+1, c1, c2);
		ans%=MOD;
	}
	else
	{
		ans+=dp(idx+1, c1|(a[idx]>b[idx]), c2|(a[idx]<b[idx]));
		ans%=MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>a>>b;
	int ans=dp(0, 0, 0);
	cout<<ans;
	return 0;
}