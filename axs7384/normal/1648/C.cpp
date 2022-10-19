#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=200005;
int f[N],fac[N],inv[N];
int n,m,a[N],b[N],c[N];
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
inline void prework()
{
	fac[0]=1;
	for (int i=1;i<=n;++i)
		fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	// cout<<inv[n]<<endl;
	for (int i=n;i;--i)
		inv[i-1]=(ll)inv[i]*i%mod;
}
inline void add(int x,int y)
{
	for (;x<=200000;x+=x&(-x))
		(f[x]+=y)%=mod;
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=x&(-x))
		(ans+=f[x])%=mod;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	prework();
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++c[a[i]];
	}
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	ll ans=0,sum=fac[n-1];
	for (int i=1;i<=200000;++i)
	{
		sum=(ll)sum*inv[c[i]]%mod;
		add(i,c[i]);
	}
	int gg=0;
	// cout<<sum<<endl;
	for (int i=1;i<=n&&i<=m;++i)
	{
		(ans+=(ll)ask(b[i]-1)*sum)%=mod;
		if (c[b[i]])
		{
			sum=(ll)sum*ksm(n-i,mod-2)%mod*c[b[i]]%mod;
			--c[b[i]];
			add(b[i],mod-1);
		}
		else
		{
			// cout<<"??"<<i<<endl;
			gg=1;
			break;
		}
	}
	// cout<<ans<<endl;
	if (!gg&&n<m)
		(ans+=1)%=mod;
	cout<<ans<<endl;
}