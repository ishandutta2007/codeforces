#include<bits/stdc++.h>
using std::min;
using std::max;
typedef long long ll;

int n,r,k,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
std::vector<int>v[1<<20];
std::map<ll,int>M;
const int mod = 998244353 ;
int fac[1<<20],inv[1<<20];
int qpow(int x,int k)
{
	int r=1;
	for(;k;k>>=1,x=x*1ll*x%mod)
		if(k&1)r=r*1ll*x%mod;
	return r;
}
int C(int n,int r)
{
	return fac[n]*1ll*inv[r]%mod*inv[n-r]%mod;
}
int calc(int x,int y,int i)
{
	return C(x,i)*1ll*C(y,i)%mod;
}
void exec()
{
	scanf("%d",&n);
	M.clear();
	ll S=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i),S+=a[i];
		if(i!=n)M[S]++;
	}
	int ans=1;
	for(auto [v,c]: M)
	{
		if(v * 2 == S)
		{
			for(int i=1;i<=c;i++)
				ans=ans*2%mod;
		}
		else if(v * 2 < S)
		{
			int d = M[S-v];
			int mis = 1;
			for(int i=1;i<=c&&i<=d;i++)
				mis = (mis + calc(c,d,i))%mod;
			//printf("%d\n",mis);
			ans = ans *1ll* mis % mod;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	for(int i=fac[0]=1;i<=1e6;i++)
		fac[i]=fac[i-1]*1ll*i%mod;
	inv[1000000]=qpow(fac[1000000],mod-2);
	for(int i=1e6;i;i--)
		inv[i-1]=inv[i]*1ll*i%mod;
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}