#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int jc[1000005],inv[1000005],jcinv[1000005];
int C(int x,int y)
{
	if(x<y||y<0) return 0;
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod; 
}
int a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	jc[0]=jc[1]=jcinv[1]=jcinv[0]=inv[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int cnt0=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			cnt0+=!a[i];
		}
		int X=0;
		for(int i=1;i<=cnt0;i++)
			if(a[i]==1) ++X;
		int ans=0;
		while(X>0)
		{
			ans=(ans+n*(n-1)/2%mod*inv[X]%mod*inv[X])%mod;
			--X;
		}
		cout << ans << "\n";
	}
	return 0;
}