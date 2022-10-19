#include<cstdio>
#define LL long long
#define mod 1000000007
int k;
LL f[402][402];
inline LL mul(LL a,LL b)
{
	return (a*b)%mod;
}
int main()
{
	scanf("%d",&k);
	for(int i=0;i<=k;++i)f[i][0]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=k;++j)
		{
			for(int o=0;o<=j-1;++o)(f[i][j]+=mul(f[i-1][o],f[i-1][j-o-1]))%=mod;
			for(int o=0;o<=j;++o)(f[i][j]+=mul(mul(f[i-1][o],f[i-1][j-o]),2*j+1))%=mod;
			for(int o=0;o<=j+1;++o)(f[i][j]+=mul(mul(f[i-1][o],f[i-1][j-o+1]),mul(j,j+1)))%=mod;
		}
	return 0&printf("%lld",f[k][1]);
}