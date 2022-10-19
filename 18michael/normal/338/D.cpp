#include<cstdio>
#include<utility>
#define LL long long
using namespace std;
int k;
LL n,m,A=1,B,C,t,t1,t2,t3,t4;
LL a[10002];
typedef pair<LL,LL> P;
inline LL mul(LL a,LL b,LL mod)
{
	LL c=0;
	while(b)
	{
		if(b&1)c=(c+a)%mod;
		a=(a<<1)%mod,b>>=1;
	}
	return c;
}
inline LL Pow(LL a,LL b,LL mod)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1),mod);
	c=mul(c,c,mod);
	if(b&1)c=mul(c,a,mod);
	return c;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
inline P exgcd(LL a,LL b,LL c,LL mod)
{
	if(!b)return P(c/a,0);
	P p=exgcd(b,a%b,c,mod);
	return P(p.second,((p.first-mul(a/b,p.second,mod))%mod+mod)%mod);
}
int main()
{
	scanf("%lld%lld%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",&a[i]),A/=gcd(A,a[i]);
		if(A>n/a[i])return 0&puts("NO");
		A*=a[i];
	}
	B=0,C=a[1];
	for(int i=2;i<=k;++i)
	{
		t=(((1-i-B)%a[i])+a[i])%a[i],t1=gcd(gcd(C,t),a[i]),C/=t1,t/=t1,a[i]/=t1;
		if(gcd(C,a[i])>1)return 0&puts("NO");
		t2=exgcd(C,a[i],t,a[i]).first,t3=C*a[i]*t1,B=(mul(t2,C*t1,t3)+B)%t3,C=t3,a[i]*=t1;
	}
	if(!B)B=C;if(B+k-1>m)return 0&puts("NO");
	for(int i=1;i<=k;++i)
		if(gcd(A,B+i-1)!=a[i])
			return 0&puts("NO");
	return 0&puts("YES");
}