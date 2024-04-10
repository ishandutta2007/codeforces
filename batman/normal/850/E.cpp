#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)2001*1000)
#define K ((int)21)
#define MOD ((ll)1e9+7)

int n,dp[2][N],ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			dp[1][i]=1;
	for(int i=0;i<n;i++)
		for(int mask=0;mask<(1<<n);mask++)
			dp[(i&1)][mask]=((ll)2*dp[!(i&1)][mask]+dp[!(i&1)][mask^(1<<i)])%MOD,dp[(i&1)][mask]%=MOD;
	for(int mask=0;mask<(1<<n);mask++)
		if(s[mask]=='1')
			ans+=dp[!(n&1)][mask],ans%=MOD;
	ans=((ll)3*ans)%MOD;
	cout<<ans<<"\n";
    return 0;
}