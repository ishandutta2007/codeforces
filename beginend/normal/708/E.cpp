#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1505;
const int MOD=1000000007;

int n,m,a,b,k,jc[100005],ny[100005],pre[N],f[N][N],s[N][N],p[N];

int ksm(int x,int y)
{
	if (y<0) return 0;
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int C(int n,int m)
{
	if (n<m) return 0;
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
	a=(LL)a*ksm(b,MOD-2)%MOD;
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=k;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=k;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	for (int i=1;i<=m;i++) p[i]=(LL)ksm(a,i-1)*ksm(1+MOD-a,k-i+1)%MOD*C(k,i-1)%MOD,pre[i]=(pre[i-1]+p[i])%MOD;
	f[0][m]=s[0][m]=1;
	for (int i=1;i<=n;i++)
	{
		int w=0;
		for (int j=1;j<=m;j++)
		{
			(w+=(LL)p[j]*(s[i-1][m]+MOD-s[i-1][j-1])%MOD)%=MOD;
			f[i][j]=(LL)(w+MOD-(LL)s[i-1][m-j]*pre[j]%MOD)*p[m-j+1]%MOD;
			s[i][j]=(s[i][j-1]+f[i][j])%MOD;
		}
	}
	printf("%d",s[n][m]);
	return 0;
}