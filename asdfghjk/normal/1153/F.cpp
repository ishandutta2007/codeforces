#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=998244353,N=20005;
int n,K,l,i,j,k,f[N],g[N],h[N],ans,inv[N],jc[N],rjc[N];
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	scanf("%d%d%d",&n,&K,&l);
	inv[1]=1;
	for(i=2;i<=20000;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=20000;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	f[0]=1;
	for(i=1;i<=n;++i)
	{
		for(j=2*i;j>=0;--j)
		{
			if(j>=1)
				f[j]=(f[j]-f[j-1]*2ll%md+md)%md;
			if(j>=2)
				f[j]=(f[j]+f[j-2]*2ll%md)%md;
		}
	}
	for(i=0;;++i)
	{
		if(i>=K)
		{
			k=C(n,i);
			for(j=0;j<=2*n;++j)
				g[j]=(g[j]+1ll*k*f[j])%md;
		}
		if(i==n)
			break;
		for(j=1;j<=2*n;++j)
		{
			f[j]=(f[j]+f[j-1]*2ll)%md;
			if(j>=2)
				f[j]=(f[j]-f[j-2]*2ll%md+md)%md;
		}
		for(j=2*n;j>=0;--j)
		{
			f[j]=0;
			if(j>=1)
				f[j]=(f[j]+2ll*f[j-1])%md;
			if(j>=2)
				f[j]=(f[j]-2ll*f[j-2]%md+md)%md;
		}
	}
	for(j=0;j<=2*n;++j)
		ans=(ans+1ll*g[j]*inv[j+1])%md;
	ans=1ll*ans*l%md;
	printf("%d",ans);
	return 0;
}