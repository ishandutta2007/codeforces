#include<bits/stdc++.h>
#define Mx 300000
#define LL long long
#define mod 1000000007
using namespace std;
int n,p_t=0,t;LL ans=0;
int p[300002],cnt[300002];
LL fac[300002],inv[300002],pre[300002];
bool u[300002];
vector<int> vec;
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),scanf("%d",&n),pre[0]=1;
	for(int i=1;i<n;++i)pre[i]=(pre[i-1]+C(n-1,i))%mod;
	for(int i=1;i<n;++i)(pre[i]+=pre[i-1])%=mod;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++cnt[x];
	for(int i=1;i<=p_t;++i)for(int j=Mx/p[i];j;--j)cnt[j]+=cnt[j*p[i]];
	for(int i=1;i<=p_t;++i)
	{
		vec.clear(),t=n;
		for(int j=p[i];;j*=p[i])
		{
			vec.push_back(cnt[j]);
			if(j>Mx/p[i])break;
		}
		for(int j=1;j<vec.size();++j)vec[j-1]-=vec[j];
		for(int j=vec.size()-1;~j;--j)(ans+=((pre[t-1]-pre[t-vec[j]-1]-(pre[n-1]-pre[n-2])*vec[j]+(t>1? pre[t-2]:0)-(t-vec[j]>1? pre[t-vec[j]-2]:0))%mod)*(j+1))%=mod,t-=vec[j];
	}
	return 0&printf("%lld",(ans+mod)%mod);
}