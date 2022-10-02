#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int inv[2000005],jc[2000005],jcinv[2000005];
const int inv2=(1000000007+1)/2;
inline int C(int x,int y)
{
	if(y<0||y>x) return 0;
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
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
	int T;
	cin >> T;
	jc[0]=jc[1]=jcinv[0]=jcinv[1]=inv[1]=1;
	for(int i=2;i<=2000000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	while(T--)
	{
		int N,M,k;
		cin >> N >> M >> k;
		int n,m;
		n=M,m=N-M;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=(ans+ksm(inv2,n+m-i)*C(n+m-i-1,m-1)%mod*i)%mod;
		}
//		cout << n << " " << m << "\n";
		if(!m) ans=n;
		cout << ans*k%mod << "\n";
	}
	return 0;
}