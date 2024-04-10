#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=200005;
LL n,k;
LL w[N];
LL sum=0;
LL JC[N],inv[N];
LL pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL C (LL x,LL y)
{
	if (x<y) return 0;
//	printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",x,y,JC[x],inv[y],inv[x-y],JC[x]*inv[y]%MOD*inv[x-y]%MOD);
	return JC[x]*inv[y]%MOD*inv[x-y]%MOD;
}
LL s (LL x,LL y)
{
	LL t=1,lalal=0;
	
	for (int k=0;k<=y;k++)
	{
		lalal=lalal+t*C(y,k)%MOD*pow(y-k,x)%MOD;
		lalal=lalal%MOD;
		t*=(-1);
	}
	lalal=(lalal+MOD)%MOD;
	lalal=lalal*inv[y]%MOD;
//	printf("%I64d %I64d %I64d\n",x,y,lalal);
	return lalal;
}
int main()
{
	//	freopen("a.in","r",stdin);
	scanf("%I64d%I64d",&n,&k);
	JC[0]=1;for (LL u=1;u<=200000;u++) JC[u]=JC[u-1]*u%MOD;
	inv[200000]=pow(JC[200000],MOD-2);
	for (LL u=200000-1;u>=1;u--)	inv[u]=inv[u+1]*(u+1)%MOD;inv[0]=1;	
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&w[u]);
		sum=sum+w[u];
		sum%=MOD;
	}
	if (k==1)
	{
		printf("%I64d\n",sum*n%MOD);
		return 0;
	}
	LL lalal=(s(n,k)+(n-1)*s(n-1,k)%MOD)%MOD;
	printf("%I64d\n",sum*lalal%MOD);
	return 0;
}