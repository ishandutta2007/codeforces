#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
const int MOD=1e9+7;

int n,k,d;
int cache[N][2];

int dp(int rem,int taken)
{
	if(rem<0)
		return 0;
	if(rem==0)
		return taken;
	int &ans=cache[rem][taken];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=1;i<=k;i++)
	{
		if(i>=d)
			ans+=dp(rem-i,1);
		else 
			ans+=dp(rem-i,taken);
		ans%=MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k>>d;
	memset(cache,-1,sizeof(cache));
	cout<<dp(n,0);
 	return 0;
}