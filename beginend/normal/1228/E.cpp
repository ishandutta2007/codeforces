#include<bits/stdc++.h>

typedef long long LL;

const int MOD=1000000007;
const int N=255;

int n,k,jc[N],ny[N];

int ksm(int x,int y)
{
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
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int calc(int m)
{
	if (!m) return 0;
	int ans=0;
	for (int i=0;i<=n;i++)
	{
		int w=(LL)C(n,i)*ksm(k-1,i*m)%MOD*ksm(k,(n-i)*m)%MOD;
		if (i&1) (ans+=MOD-w)%=MOD;
		else (ans+=w)%=MOD;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ans=0;
	for (int i=0;i<=n;i++)
		if (i&1) (ans+=MOD-(LL)C(n,i)*calc(n-i)%MOD*ksm(k-1,i*n)%MOD)%=MOD;
		else (ans+=(LL)C(n,i)*calc(n-i)%MOD*ksm(k-1,i*n)%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}