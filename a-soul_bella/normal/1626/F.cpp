#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
const int M=720720;
int dp[20][M];
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn=rtn*x%mod;
		x=x*x%mod,y>>=1;
	}
	return rtn;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,INV,k,a,x,y,qwqm;
	cin >> n >> a >> x >> y >> k >> qwqm;
	INV=ksm(n,mod-2);
	int p1=INV,p0=INV*(n-1)%mod;
	for(int i=k-1;i>=1;i--)
		for(int j=0;j<M;j++)
			dp[i][j]=(dp[i+1][j]*p0+(j%i*(k-i)*INV%mod+dp[i+1][j-j%i])*p1)%mod;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+a*k%mod*INV-dp[1][a%M])%mod;
		a=(a*x+y)%qwqm;
	}
	cout << (ans%mod+mod)%mod*ksm(n,k)%mod;
	return 0;
}