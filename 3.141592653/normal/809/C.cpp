#include<cstdio>
int n;
typedef long long ll;
const ll mod=1e9+7;
struct cp
{ll sm,k;cp(ll _s=0,ll _k=0){sm=_s,k=_k;}};
inline cp g(ll x,ll y,ll k,ll r)
{
	if(!x)return cp();
	if(!y)return cp();
	if(k<0)return cp();
	//printf("%lld %lld %lld %lld\n",x,y,r);
	if(x<y)x^=y,y^=x,x^=y;
	ll p=1ll<<r;
	while(p>x)p>>=1,r--;
	if(x==p)
	{
		if(p<=k)return cp((y*(((p*(p+1))/2)%mod))%mod,(p*y)%mod);
		else return cp((y*(((k*(k+1))/2)%mod))%mod,(k*y)%mod);
	}while(p>=x)p>>=1,r--;
	if(p<y)
	{
		cp d1=g(p,p,k,r),d2=g(x-p,p,k-p,r),
		d3=g(p,y-p,k-p,r),d4=g(x-p,y-p,k,r);
		return cp((d1.sm+d2.sm+d3.sm+d4.sm+(d2.k+d3.k)*p)%mod
		,(d1.k+d2.k+d3.k+d4.k)%mod);
	}
	else
	{
		cp d1=g(p,y,k,r),d2=g(x-p,y,k-p,r);
		return cp((d1.sm+d2.sm+d2.k*p)%mod,(d1.k+d2.k)%mod);
	}
}
inline ll f(ll x,ll y,ll k,ll r=30)
{
	if(!x)return 0;
	if(!y)return 0;
	if(x<y)x^=y,y^=x,x^=y;
	ll p=1ll<<r;
	while(p>x)p>>=1,r--;
	return g(x,y,k,r).sm;
}
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
	{
		int x1,y1,x2,y2,k;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		//printf("%lld %lld %lld %lld\n",f(x2,y2,k),f(x1-1,y2,k)
		//,f(x2,y1-1,k),f(x1-1,y1-1,k));
		printf("%I64d\n",(f(x2,y2,k)-f(x1-1,y2,k)
		-f(x2,y1-1,k)+f(x1-1,y1-1,k)+mod*10)%mod);
	}
}