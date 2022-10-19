#include<cstdio>
#define LL long long
LL u,v,a,b,c;
int main()
{
	scanf("%lld%lld",&u,&v),a=u;
	if(!u && !v)puts("0");
	else if(((a^v)&1) || a>v)puts("-1");
	else if(a==v)printf("1\n%lld",a);
	else
	{
		b=c=(v-a)/2;
		if(!(a&b))printf("2\n%lld %lld",(a^b),c);
		else printf("3\n%lld %lld %lld",a,b,c);
	}
	return 0;
}