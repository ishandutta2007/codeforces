#include<bits/stdc++.h>
#define LL long long
#define Mx 100000
#define mod 998244353
using namespace std;
int n,p_t=0;
LL ans=0;
int b[100002],mu[100002],p[100002];
LL cnt[100002],sum[100002],sum2[100002];
bool u[100002];
inline LL Pow(int a,LL b)
{
	if(!b)return 1;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	mu[1]=1;
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i,mu[i]=-1;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
			mu[p[j]*i]=-mu[i];
		}
	}
}
int main()
{
	scanf("%d",&n),init();
	for(int i=1,x;i<=n;++i)scanf("%d%d",&x,&b[i]),(sum[x]+=(LL)x*b[i])%=mod,(sum2[x]+=(((LL)x*x)%mod)*b[i])%=mod,cnt[x]+=b[i];
	for(int i=1;i<=p_t;++i)for(int j=Mx/p[i];j;--j)cnt[j]+=cnt[j*p[i]],(sum[j]+=sum[j*p[i]])%=mod,(sum2[j]+=sum2[j*p[i]])%=mod;
	for(int i=1;i<=Mx;++i)
	{
		sum[i]=(sum[i]*sum[i]-sum2[i])%mod;
		if(cnt[i]==2)(ans+=(sum[i]+sum2[i])*mu[i])%=mod;
		else if(cnt[i]>2)(ans+=(((Pow(2,cnt[i]-3)*(cnt[i]%mod))%mod)*sum[i]+((Pow(2,cnt[i]-2)*((cnt[i]-1)%mod))%mod)*sum2[i])*mu[i])%=mod;
	}
	return 0&printf("%lld",(ans+mod)%mod);
}