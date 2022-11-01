#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;
const int MOD=998244353;

int n,ny[N],jc[N];

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d",&n);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	int ans=jc[n];
	for (int i=2;i<=n;i++) (ans+=(LL)C(n,n-i+1)*(n-i)%MOD*jc[i-1]%MOD*(i-1)%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}