#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,K,i,j,k,a[25],g[25][25];
long long f[300000][20],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	while(K--)
	{
		scanf("%d%d%d",&i,&j,&k);
		g[i][j]+=k;
	}
	for(i=1;i<(1<<n);++i)
		for(j=0;j<=n;++j)
			f[i][j]=-(1ll<<60);
	for(i=1;i<=n;++i)
		f[1<<(i-1)][i]=a[i];
	for(i=1;i<(1<<n);++i)
		for(j=1;j<=n;++j)
			if(f[i][j]!=-(1ll<<60))
			{
				for(k=1;k<=n;++k)
					if(!(i>>(k-1)&1))
						f[i|(1<<(k-1))][k]=max(f[i|(1<<(k-1))][k],f[i][j]+a[k]+g[j][k]);
			}
	for(i=1;i<(1<<n);++i)
	{
		for(j=k=0;j<n;++j)
			if(i>>j&1)
				++k;
		if(k==m)
		{
			for(j=1;j<=n;++j)
				ans=max(ans,f[i][j]);
		}
	}
	printf("%lld",ans);
	return 0;
}