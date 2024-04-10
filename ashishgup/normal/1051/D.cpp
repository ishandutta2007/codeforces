#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;
const int MOD=998244353;

int n, k;
int cache[N][2*N][2][2];

int dp(int idx, int comp, int c1, int c2)
{
	if(idx==n+1)
		return comp==k;
	int &ans=cache[idx][comp][c1][c2];
	if(ans!=-1)
		return ans;
	ans=0;
	if(c1==c2)
	{
		ans+=dp(idx+1, comp, c1, c2);
		ans+=dp(idx+1, comp+1, c1^1, c2^1);
		ans+=dp(idx+1, comp+1, c1^1, c2);
		ans+=dp(idx+1, comp+1, c1, c2^1);
	}
	else
	{
		ans+=dp(idx+1, comp, c1, c2);
		ans+=dp(idx+1, comp+2, c1^1, c2^1);
		ans+=dp(idx+1, comp, c1^1, c2);
		ans+=dp(idx+1, comp, c1, c2^1);
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k;
	int ans=0;
	ans+=dp(2, 1, 0, 0) + dp(2, 1, 1, 1);
	ans+=dp(2, 2, 0, 1) + dp(2, 2, 1, 0);
	ans%=MOD;
	cout<<ans;
	return 0;
}