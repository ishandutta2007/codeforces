#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
#define mod1 998244353
#define mod2 998244853
#define mod3 1000000007
#define mod4 1000000009
using namespace std;
int n,w_t=0,h_t=0,ans=1;
LL gcdw=0,gcdh=0,g,t,totc=0;
LL cntw[200002],cnth[200002];
struct aaa
{
	LL w,h,c;
}matrix[200002];
inline bool cmpw(aaa a,aaa b)
{
	return a.w==b.w? (a.h<b.h):(a.w<b.w);
}
inline bool cmph(aaa a,aaa b)
{
	return a.h==b.h? (a.w<b.w):(a.h<b.h);
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
inline bool check(LL a,LL b,LL c,LL d)
{
	if(((a%mod1)*(d%mod1)-(b%mod1)*(c%mod1))%mod1)return 1;
	if(((a%mod2)*(d%mod2)-(b%mod2)*(c%mod2))%mod2)return 1;
	if(((a%mod3)*(d%mod3)-(b%mod3)*(c%mod3))%mod3)return 1;
	if(((a%mod4)*(d%mod4)-(b%mod4)*(c%mod4))%mod4)return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&matrix[i].w,&matrix[i].h,&matrix[i].c),totc+=matrix[i].c;
	sort(matrix+1,matrix+n+1,cmpw);
	for(int i=1,j;i<=n;i=j)
	{
		++w_t;
		for(j=i;matrix[j].w==matrix[i].w;++j)cntw[w_t]+=matrix[j].c;
		gcdw=gcd(gcdw,cntw[w_t]);
	}
	sort(matrix+1,matrix+n+1,cmph);
	for(int i=1,j;i<=n;i=j)
	{
		++h_t;
		for(j=i;matrix[j].h==matrix[i].h;++j)cnth[h_t]+=matrix[j].c;
		gcdh=gcd(gcdh,cnth[h_t]);
	}
	if(n!=w_t*h_t)return 0&puts("0");
	for(LL i=1;i<n/h_t;++i)
		for(LL j=1;j<h_t;++j)
			if(check(matrix[(j-1)*n/h_t+i].c,matrix[(j-1)*n/h_t+i+1].c,matrix[j*n/h_t+i].c,matrix[j*n/h_t+i+1].c))
				return 0&puts("0");
	t=gcd(gcdw,totc),gcdw/=t,totc/=t,t=gcd(gcdh,totc),gcdh/=t,totc/=t;
	if(totc>1)return 0&puts("0");g=gcdw*gcdh;
	for(int i=2,j;i<=sqrt(g);++i)
	{
		for(j=0;!(g%i);++j)g/=i;
		ans*=(j+1);
	}
	if(g>1)ans*=2;
	printf("%d",ans);
	return 0;
}