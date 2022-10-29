#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,m,K,i,j,k,a[105],inv[10005],g[105][105],h[105][105],c[105][105];
void Mult(int a[105][105],int b[105][105])
{
	int i,j,k;
	for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
			c[i][j]=0;
	for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
			for(k=0;k<=m;++k)
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md;
	for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
			a[i][j]=c[i][j];
}
int main()
{
	scanf("%d%d",&n,&K);
	inv[1]=1;
	for(i=2;i<=n*n;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]==0)
			++m;
	}
	for(i=1,j=0;i<=m;++i)
		if(a[i])
			++j;
	h[0][j]=1;
	for(j=0;j<=m;++j)
	{
		if(j)
			g[j][j-1]=(g[j][j-1]+1ll*j*j%md*inv[n*(n-1)/2]%md)%md;
		if(j<m)
			g[j][j+1]=(g[j][j+1]+1ll*(m-j)*(n-m-j)%md*inv[n*(n-1)/2]%md)%md;
		g[j][j]=(g[j][j]+(1-(1ll*j*j+1ll*(m-j)*(n-m-j))%md*inv[n*(n-1)/2]%md+md)%md)%md;
	}
	while(K)
	{
		if(K&1)
			Mult(h,g);
		Mult(g,g);
		K>>=1;
	}
	printf("%d",h[0][0]);
	/*f[0][j]=1;
	for(i=0;i<K;++i)
		for(j=0;j<=m;++j)
		{
			if(j)
				f[i+1][j-1]=(f[i+1][j-1]+1ll*f[i][j]*j%md*j%md*inv[n*(n-1)/2]%md)%md;
			if(j<m)
				f[i+1][j+1]=(f[i+1][j+1]+1ll*f[i][j]*(m-j)%md*(n-m-j)%md*inv[n*(n-1)/2]%md)%md;
			f[i+1][j]=(f[i+1][j]+f[i][j]*(1-(1ll*j*j+1ll*(m-j)*(n-m-j))%md*inv[n*(n-1)/2]%md+md)%md)%md;
		}
	printf("%d",f[K][0]);*/
	return 0;
}