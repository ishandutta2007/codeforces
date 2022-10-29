#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int md=1000000007;
int n,K,i,j,k,f[255][255],pw0[255],pw1[255],inv[255],jc[255],rjc[255];
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		printf("1");
		return 0;
	}
	pw0[0]=pw1[0]=jc[0]=rjc[0]=1;
	for(i=1;i<=n;++i)
	{
		pw0[i]=1ll*pw0[i-1]*K%md,pw1[i]=1ll*pw1[i-1]*(K-1)%md;
		if(i==1)
			inv[1]=1;
		else
			inv[i]=1ll*inv[md%i]*(md-md/i)%md;
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	}
	for(i=1;i<=n;++i)
		f[1][i]=1ll*C(n,i)*pw1[n-i]%md;
	for(i=1;i<n;++i)
		for(j=1;j<=n;++j)
		{
			f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*pw1[n-j]%md*(pw0[j]-pw1[j]+md)%md)%md;
			for(k=1;k<=n-j;++k)
				f[i+1][j+k]=(f[i+1][j+k]+1ll*f[i][j]*C(n-j,k)%md*pw1[n-j-k]%md*pw0[j]%md)%md;
		}
	printf("%d",f[n][n]);
	return 0;
}