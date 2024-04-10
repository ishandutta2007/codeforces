#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;
const int MOD=998244353;

int n,m,jc[N],ny[N];

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

int main()
{
	scanf("%d%d",&n,&m);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=m;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=m;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	printf("%d\n",(LL)jc[m]*ny[m-n+1]%MOD*ny[n-1]%MOD*ksm(2,n-3)%MOD*(n-2)%MOD);
	return 0;
}