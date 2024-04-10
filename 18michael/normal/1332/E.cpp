#include<cstdio>
#define LL long long
#define mod 998244353
#define mod1 1996488706
LL n,m,l,r,ans;
inline LL pow(LL a,LL b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod1;
	if(b&1)c=(c*a)%mod1;
	return c;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
	if((n*m)&1)ans=pow(r-l+1,n*m);
	else ans=(pow(r-l+1,n*m)/2)+((l&1)==(r&1));
	return 0&printf("%lld",ans%mod);
}