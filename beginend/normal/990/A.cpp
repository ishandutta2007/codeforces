#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL n,m;
int a,b;

int main()
{
	scanf("%I64d%I64d%d%d",&n,&m,&a,&b);
	if (n%m==0) {puts("0");return 0;}
	printf("%I64d",std::min((LL)a*(m-n%m),(LL)b*(n%m)));
	return 0;
}