#include<cstdio>
#include<algorithm>
int main()
{
	long long a,b,m,n;
	scanf("%I64d%I64d%I64d%I64d",&m,&n,&a,&b);
	long long x=m%n,y=n-m%n;
	printf("%I64d\n",std::min(x*b,y*a));
}