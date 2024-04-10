#include<bits/stdc++.h>
#define LL long long
#define Mx1 2000000
#define mod 1000000007
using namespace std;
int n,Mx;LL res,ans=0;
int a[16],one[16386];
LL f[16386],fac[2000002],inv[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx1;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx1]=Pow(fac[Mx1],mod-2);for(int i=Mx1;i;--i)inv[i-1]=(inv[i]*i)%mod,inv[i]=(inv[i]*fac[i-1])%mod;
}
int main()
{
	init(),read(n),Mx=(1<<n);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=1;i<Mx;++i)
	{
		one[i]=one[(i>>1)]+(i&1);
		for(int S=(i-1)&i;S;S=(S-1)&i)
		{
			res=1-f[S];
			for(int j=0;j<n;++j)
				if((S>>j)&1)
					for(int k=0;k<n;++k)
						if(((i>>k)&1) && !((S>>k)&1))
							res=(((res*a[j])%mod)*inv[a[j]+a[k]])%mod;
			f[i]=(f[i]+res)%mod;
		}
		res=((1LL-f[i])*one[i])%mod;
		for(int j=0;j<n;++j)
			if((i>>j)&1)
				for(int k=0;k<n;++k)
					if(!((i>>k)&1))
						res=(((res*a[j])%mod)*inv[a[j]+a[k]])%mod;
		ans=(ans+res)%mod;
	}
	return 0&printf("%lld",(ans+mod)%mod);
}