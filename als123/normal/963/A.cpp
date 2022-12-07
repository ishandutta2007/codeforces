#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL N=100005;
const LL MOD=1e9+9;
LL n,a,b,k;
char ss[N];
LL pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
	LL ny=pow(a,MOD-2),now=pow(a,n),lalal=0;
	scanf("%s",ss);
	for (LL u=0;u<k;u++)
	{
		if (ss[u]=='+') lalal=lalal+now;
		else lalal=lalal-now;
		lalal=(lalal%MOD+MOD)%MOD;
		now=now*b%MOD*ny%MOD;
	}
	LL p=pow(b*ny%MOD,k),ans=0;
	if (p!=1) ans=(pow(p,(n+1)/k)-1)*pow(p-1,MOD-2)%MOD*lalal%MOD;
	else ans=lalal*((n+1)/k)%MOD;
	printf("%I64d",ans);
	return 0;
}