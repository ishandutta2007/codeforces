#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int jc[500005],jcinv[500005],inv[500005],a[500005];
inline int C(int x,int y)
{
	if(y<0||x<y) return 0;
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
signed main()
{
	jc[0]=jcinv[0]=jcinv[1]=inv[1]=jc[1]=1;
	for(int i=2;i<=500000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	++n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(!a[1])
	{
		cout << 0;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+C(a[i]-1+i-1,i-1))%mod;
		for(int j=a[i];j>a[i+1];j--)
			ans=(ans+C(j+i-2,i-1))%mod;
	}
	cout << (ans-1+mod)%mod;
	return 0;
}