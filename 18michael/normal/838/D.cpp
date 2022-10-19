#include<cstdio>
#define LL long long
#define mod 1000000007
int n,m;
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d%d",&n,&m);
	return 0&printf("%lld",(((Pow(2,m)*(n-m+1))%mod)*Pow(n+1,m-1))%mod);
}