#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,k; 
LL nn;
LL a,b;
LL calc (LL l,LL r)	{if (l==r) return nn;return (r-l+nn)%nn;}
LL gcd (LL x,LL y)	{return x==0?y:gcd(y%x,x);}
LL calc1 (LL x,LL y)
{
	//printf("%lld %lld\n",x,y);
	LL t=gcd(x,y);
	return y/t;
}
int main()
{
	scanf("%lld%lld",&n,&k);nn=n*k;
	scanf("%lld%lld",&a,&b);
	LL x=a+1,y=k-a+1;
	LL ans1=nn,ans2=0;
	for (LL u=1;u<=n;u++)
	{
		LL t=(u-1)*k+b+1,t1=(u-1)*k+k-b+1;
		LL l=calc(x,t1);
		if (l!=0)
		{
			ans1=min(ans1,calc1(l,nn));
			ans2=max(ans2,calc1(l,nn));
		}
		l=calc(x,t);
		if (l!=0)
		{
			ans1=min(ans1,calc1(l,nn));
			ans2=max(ans2,calc1(l,nn));
		}
		l=calc(y,t);
		if (l!=0)
		{
			ans1=min(ans1,calc1(l,nn));
			ans2=max(ans2,calc1(l,nn));
		}
		l=calc(y,t1);
		if (l!=0)
		{
			ans1=min(ans1,calc1(l,nn));
			ans2=max(ans2,calc1(l,nn));
		}
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}