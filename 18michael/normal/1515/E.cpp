#include<cstdio>
#define LL long long
int n,mod;
LL f[402][402]={};
int main()
{
	scanf("%d%d",&n,&mod),f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(LL j=1;j<=n;++j)
		{
			f[i][j]=(j*f[i-1][j-1]+2*j*f[i-1][j])%mod;
			if(i>1)
			{
				f[i][j]=(f[i][j]+2*j*f[i-2][j]+2*j*f[i-2][j+1])%mod;
				if(i>2)f[i][j]=(f[i][j]+j*f[i-3][j+1])%mod;
			}
		}
	return 0&printf("%lld",f[n][1]);
}