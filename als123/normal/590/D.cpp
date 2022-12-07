#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MAX=1e9;
const LL N=155;
LL n,k,s;
LL a[N];
LL f[2][N][N*N];
int main()
{
	scanf("%lld%lld%lld",&n,&k,&s);
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	LL op=0;
	memset(f,127,sizeof(f));
	for (LL u=0;u<=min(s,n*n);u++) f[0][0][u]=f[1][0][u]=0;
	for (LL u=1;u<=n;u++)
	{
		op^=1;
		for (LL i=1;i<=u;i++)
		for (LL j=0;j<=i*u;j++)
		{
			f[op][i][j]=f[op^1][i][j];
			if (j>=u-i)
			f[op][i][j]=min(f[op][i][j],f[op^1][i-1][j-(u-i)]+a[u]);
		}
	}
	LL ans=MAX;
	for (LL u=0;u<=min(s,n*n);u++) ans=min(ans,f[op][k][u]);
	printf("%lld\n",ans);
	return 0;
}