#include<cstdio>
int main()
{
	long long k,n,w;
	scanf("%lld%lld%lld",&k,&n,&w);
	long long c=w*(w+1)*k/2;
	if(n>=c) puts("0");
	else printf("%lld",c-n);
	return 0;
}