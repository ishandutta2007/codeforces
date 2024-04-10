#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;
const int MOD=1000000007;

int n,m,a,b,jc[N],ny[N];

int ksm(int x,int y)
{
	if (y==-1) return ksm(x,MOD-2);
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
	scanf("%d%d%d%d",&n,&m,&a,&b);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=std::max(n,m);i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=std::max(n,m);i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ans=0;
	for (int i=2;i<=n;i++)
		(ans+=(LL)C(m-1,i-2)*i%MOD*ksm(n,n-i-1)%MOD*C(n-2,i-2)%MOD*jc[i-2]%MOD*ksm(m,n-i)%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}