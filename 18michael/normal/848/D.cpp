#include<bits/stdc++.h>
#define Mx 50
#define LL long long
#define mod 1000000007
using namespace std;
int n,m;
LL res;
LL inv[52];
LL f[52][52],F[52][52],g[52][52],G[52][52];
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d%d",&n,&m),f[0][1]=1;
	for(int i=1;i<=Mx;++i)inv[i]=Pow(i,mod-2);
	for(int i=0;i<=Mx;++i)
	{
		if(i)for(int j=Mx;~j;--j)G[i-1][j]=(G[i-1][j+1]+g[i-1][j])%mod,F[i-1][j]=(F[i-1][j+1]+f[i-1][j])%mod;
		for(int j=Mx;~j;--j)
		{
			for(int k=0;k<i;++k)G[i][j]=(G[i][j]+F[k][j]*F[i-1-k][j])%mod;
			g[i][j]=(G[i][j]-G[i][j+1])%mod;
			if(i || j)for(int a=Mx;~a;--a)for(int b=Mx;~b;--b)for(int k=res=1;a+i*k<=Mx && b+j*k<=Mx;++k)f[a+i*k][b+j*k]=(f[a+i*k][b+j*k]+(res=(((res*(g[i][j]-1+k))%mod)*inv[k])%mod)*f[a][b])%mod;
		}
	}
	return 0&printf("%lld",(f[n][m]+mod)%mod);
}