#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1073741824;
const LL N=2005;
LL gcd[N][N];
LL mu[N];
LL pri[N],tot=0;
bool ok[N];
void prepare ()
{
	memset(ok,true,sizeof(ok));
	mu[1]=1;
	for (LL u=2;u<=2000;u++)
	{
		if (ok[u])	{pri[++tot]=u;mu[u]=-1;}
		for (LL i=1;i<=tot;i++)
		{
			LL j=pri[i];
			if (u*j>2000) break;
			ok[u*j]=false;
			if (u%j==0)	{mu[u*j]=0;break;}
			else mu[u*j]=-mu[u];
		}
	}
	for (LL u=0;u<=2000;u++) gcd[u][0]=u,gcd[0][u]=u;
	for (LL u=1;u<=2000;u++)
		for (LL i=1;i<=u;i++)
			gcd[i][u]=gcd[u][i]=gcd[i][u%i];
}
LL a,b,c;
LL solve (LL x,LL y,LL z)
{
	LL lalal=0;
	for (LL u=1;u<=x;u++)
		if (gcd[z][u*y]==1)	lalal=lalal+x/u;
	return lalal;
}
int main()
{
	prepare();
	scanf("%lld%lld%lld",&a,&b,&c);
	LL ans=0;
	for (LL u=1;u<=a;u++)
	{
		LL lalal=0;
		for (LL i=1;i<=min(b,c);i++)
		{
			lalal=lalal+mu[i]*solve(b/i,i,u)%MOD*solve(c/i,i,u)%MOD;
			lalal%=MOD;
		}
		ans=ans+(a/u)*lalal%MOD;
		ans=ans%MOD;
	}
	ans=(ans+MOD)%MOD;
	printf("%lld\n",ans);
	return 0;
}