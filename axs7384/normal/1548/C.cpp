#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long
const int N=3000100;
int a[N];
int fac[N];
int ans[N];
int inv[N];
int n;
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
inline int C(int x,int y)
{
	return (ll)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	scanf("%d",&n);
	// scanf("%d",&m);
	fac[0]=1;
	for (int i=1;i<=n*3+3;++i)
		fac[i]=(ll)fac[i-1]*i%mod;
	inv[n*3+3]=ksm(fac[n*3+3],mod-2);
	for (int i=n*3+3;i>=1;--i)
		inv[i-1]=(ll)inv[i]*i%mod;
	int p=n*3+3;
	for (int i=1;i<=p;++i)
		a[i]=C(p,i);
	a[1]=(a[1]-3+mod)%mod;
	a[2]=(a[2]-3+mod)%mod;
	a[3]=(a[3]-1+mod)%mod;
	for (int i=n*3;i>=0;--i)
	{
		ans[i]=a[i+3];
		a[i+2]=(a[i+2]+mod-(ll)3*ans[i]%mod)%mod;
		a[i+1]=(a[i+1]+mod-(ll)3*ans[i]%mod)%mod;
	}
	int q,x;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}