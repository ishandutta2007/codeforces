#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
const LL MOD=1e9+7;
LL add (LL x,LL y)   {x=x+y;return x>=MOD?x-MOD:x;}
LL mul (LL x,LL y)   {return (LL)x*y%MOD;}
LL dec (LL x,LL y)   {x=x-y;return x<0?x+MOD:x;}
LL Pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
LL T;
LL JC[N],inv[N];
void Init (LL x)
{
	JC[0]=1;for (LL u=1;u<=x;u++) JC[u]=mul(JC[u-1],u);
	inv[x]=Pow(JC[x],MOD-2);
	for (LL u=x-1;u>=0;u--) inv[u]=mul(inv[u+1],u+1);
}
LL C (LL x,LL y)	{return x<y?0:mul(JC[x],mul(inv[y],inv[x-y]));}
LL P (LL x,LL y)	{return x<y?0:mul(JC[x],inv[x-y]);}
LL f[N];
int main()
{
	Init(200000);
	scanf("%lld",&T);
	while (T--)
	{
		LL n,k;
		scanf("%lld%lld",&n,&k);
		for (LL u=0;u<=n;u++) 
		{
			f[u]=P(n-(k-1)*(u-1),u);
		}
	//	printf("YES\n");
		LL ans=0;
		for (LL u=0;u<n;u++)
		{
			LL t=dec(mul(f[u],n-u),f[u+1]);
			t=mul(t,Pow(P(n,u+1),MOD-2));
			ans=add(ans,mul(t,u+1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}