#include<cstdio>
#define LL long long
LL a,b,c,d,ans=0;
inline LL min(LL a,LL b)
{
	return a<b? a:b;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline LL calc(LL x)
{
	if(x<a+b || x>b+c)return 0;
	if(a+c<b+b)
	{
		if(x<a+c)return c-b+1-((a+c)-x);
		else if(x>b+b)return c-b+1-(x-(b+b));
		else return c-b+1;
	}
	else
	{
		if(x<b+b)return b-a+1-((b+b)-x);
		else if(x>a+c)return b-a+1-(x-(a+c));
		else return b-a+1;
	}
}
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(LL i=max(a+b,c+1);i<=b+c;++i)ans=ans+calc(i)*min(i-c,d-c+1);
	printf("%lld",ans);
	return 0;
}