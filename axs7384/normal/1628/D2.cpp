#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
const int N=1000005;
int fac[N],inv[N],inv2[N];
inline void prework()
{
	fac[0]=1;
	int n=1000000;
	for (int i=1;i<=n;++i)
		fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for (int i=n;i;--i)
		inv[i-1]=(ll)inv[i]*i%mod;
	inv2[0]=1;
	inv2[1]=ksm(2,mod-2);
	for (int i=2;i<=n;++i)
		inv2[i]=(ll)inv2[i-1]*inv2[1]%mod;
}
inline int C(int x,int y)
{
	return (ll)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	prework();
	int t,n,m,k,ans;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if (n==m)
		{
			printf("%d\n",(ll)n*k%mod);
			continue;
		}
		ans=0;
		for (int i=1;i<=m;++i)//i+1,i__n,m
			(ans+=(ll)i*C(n-i-1,m-i)%mod*inv2[n-i]%mod)%=mod;
		printf("%d\n",(ll)ans*k%mod);
	}
	return 0;
}