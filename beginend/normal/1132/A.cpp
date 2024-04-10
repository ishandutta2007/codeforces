#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL a,b,c,d;

int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	LL x=a*2;
	if (!x&&c) {puts("0");return 0;}
	x-=d*2;
	if (x!=0) {puts("0");return 0;}
	puts("1");
	return 0;
}