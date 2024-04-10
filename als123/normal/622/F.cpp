#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=1000005;
LL n,k;
LL pow (LL x,LL y)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL lalal[N],inv[N];
LL a[N];
LL q[N],p[N];
LL solve ()
{
	if (n<=k+2) return a[n];
	LL w=pow(lalal[k+2],MOD-2);
	LL ans=0;
	p[0]=q[k+3]=1;
	for (int u=1;u<=k+2;u++) p[u]=p[u-1]*(n-u)%MOD;
	for (int u=k+2;u>=1;u--) q[u]=q[u+1]*(n-u)%MOD;
	for (int u=1;u<=k+2;u++)
	{
	//	printf("%I64d %I64d %I64d %I64d\n",a[u],p[u-1],q[u+1],w);
		ans=ans+a[u]*w%MOD*p[u-1]%MOD*q[u+1]%MOD;
		w=w*(u-k-2)%MOD*inv[u]%MOD;
		ans=(ans%MOD+MOD)%MOD;
	}
	return ans;
}
int main()
{
	for (int u=1;u<=1000002;u++) inv[u]=pow(u,MOD-2);
	lalal[1]=1;for (int u=2;u<=1000002;u++) lalal[u]=lalal[u-1]*(1-u)%MOD;
	scanf("%I64d%I64d",&n,&k);
	for (int u=1;u<=k+2;u++) a[u]=(a[u-1]+pow(u,k))%MOD;
	printf("%I64d\n",solve());
	return 0;
}