#include<bits/stdc++.h>

typedef long long LL;

const int N=2005;
const int MOD=1000000007;

int n,m,jc[N],ny[N];

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d%d",&n,&m);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n+m;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n+m;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			(ans+=(LL)C(i+m-1-1,m-1)*C(n-j+m-1,m-1)%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}