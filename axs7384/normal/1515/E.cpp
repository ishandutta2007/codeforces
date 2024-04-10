#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=505;
int frac[N],inv[N],f[N][N],g[N];
int n,mod,ans;
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
inline ll C(int x,int y)
{
	return (ll)frac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	cin>>n>>mod;
	frac[0]=1;
	for (int i=1;i<=n;++i)
		frac[i]=(ll)frac[i-1]*i%mod;
	for (int i=0;i<=n;++i)
		inv[i]=ksm(frac[i],mod-2);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			(g[i]+=C(i-1,j-1))%=mod;
	for (int i=1;i<=n;++i)
	{
		// cout<<i<<' '<<g[i]<<endl;
		g[i]=(ll)g[i]*inv[i]%mod;
	}
	for (int i=1;i<=n;++i)
		f[i][i]=g[i];
	for (int i=1;i<n;++i)
		for (int j=1;j<=i;++j)
			if (f[i][j])
			{
				for (int k=i+2;k<=n;++k)
					(f[k][j+k-i-1]+=(ll)f[i][j]*g[k-i-1]%mod)%=mod;
			}
	ans=0;
	for (int i=1;i<=n;++i)
		(ans+=(ll)f[n][i]*frac[i]%mod)%=mod;
	cout<<ans;
	return 0;
}