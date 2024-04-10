#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,K,i,j,k,ans,a[5005],f[5005][5005],e[5005],w;
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	f[0][0]=1;
	for(i=1;i<=n;++i)
		for(j=0;j<=i;++j)
			f[i][j]=(1ll*f[i-1][j]*a[i]%md-(j>0?f[i-1][j-1]:0)+md)%md;
	for(i=0;i<=n&&i<=K;++i)
	{
		for(j=K-i+1,k=f[n][i];j<=K;++j)
			k=1ll*k*j%md;
		w=(w+1ll*k*pw(n,K-i))%md;
		//printf("%d\n",k);
	}
	w=1ll*w*pw(pw(n,K),md-2)%md;
	ans=1;
	for(i=1;i<=n;++i)
		ans=1ll*ans*a[i]%md;
	ans=(ans-w+md)%md;
	printf("%d",ans);
	return 0;
}