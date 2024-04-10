#include<cstdio>
#define Mx 10000000
#define LL long long
#define mod 1000000007
int n,p_t=0;LL ans=0;
int p[664582],pw[500002],f[10000002]={},g[10000002]={};
bool u[10000002]={};
inline void init()
{
	f[1]=1;
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i,f[i]=-1;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
			f[p[j]*i]=-f[i];
		}
	}
}
int main()
{
	init(),scanf("%d",&n),pw[0]=1;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++g[x],pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=p_t;++i)for(int j=Mx/p[i];j;--j)g[j]+=g[p[i]*j];
	for(int i=1;i<=Mx;++i)f[i]*=g[i],g[i]=pw[g[i]]-1;
	for(int i=1;i<=p_t;++i)for(int j=1;j<=Mx/p[i];++j)(f[p[i]*j]+=f[j])%=mod,(g[j]-=g[p[i]*j])%=mod;
	for(int i=2;i<=Mx;++i)ans=(ans+1LL*f[i]*g[i])%mod;
	return 0&printf("%lld",(ans+mod)%mod);
}