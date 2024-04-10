#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=100005;
LL n;
LL p[75],tot;
LL f[31];
LL cnt=0;
void Ins (LL x)
{
	for (LL u=30;u>=0;u--)
		if (x>>u&1)
		{
			if (f[u]==0) {f[u]=x;return ;}
			x^=f[u];
		}
	cnt++;
}
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
	for (LL u=2;u<=70;u++)
	{
		bool tf=false;
		for (LL i=2;i<u;i++)
			if (u%i==0) tf=true;
		if (tf==false) p[++tot]=u;
	}
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)
	{
		LL x;
		scanf("%I64d",&x);
		LL xx=0;
		for (LL i=1;i<=tot;i++)
		{
			while (x%p[i]==0)
			{
				xx^=(1<<i-1);
				x/=p[i];
			}
		}
		Ins(xx);
	}
	printf("%I64d\n",(pow(2,cnt)-1+MOD)%MOD);
	return 0;
}