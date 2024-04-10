#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=998244353;
typedef long long LL;
LL a,b,c;
LL tot1=0,tot2=0,tot3=0;
LL get (LL x,LL y)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=get(x,y/2);lalal=lalal*lalal%MOD;
	if (y%2!=0) lalal=lalal*x%MOD;
	return lalal;
}
LL shen (LL x,LL y)// 
{
	LL ooo=1;
	LL now=1;
	for (LL u=1;u<=min(x,y);u++)
	{
		now=now*(x-u+1)%MOD*(y-u+1)%MOD*get(u,MOD-2)%MOD;
		ooo=(ooo+now)%MOD;
	}
	return ooo;
}
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d\n",shen(a,b)*shen(b,c)%MOD*shen(a,c)%MOD);
	return 0;
}