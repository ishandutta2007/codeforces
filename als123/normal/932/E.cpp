#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=5005;
LL n,k;
LL f[N][N];
LL pow (LL x,LL y)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	f[0][0]=1;
	for (LL u=1;u<=k;u++)// 
		for (LL i=1;i<=k;i++)// 
			f[u][i]=(f[u-1][i-1]*(n-i+1)%MOD+f[u-1][i]*i)%MOD;
	LL ans=0;
	for (LL u=1;u<=min(n,k);u++) ans=(ans+f[k][u]*pow(2,n-u)%MOD)%MOD;
	printf("%I64d\n",ans);
	return 0;
}