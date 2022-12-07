#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=105;
LL n;
int main()
{
	scanf("%lld",&n);
	if (n<10)	{printf("%lld\n",n);return 0;}
	LL ans=9,now=9;
	while (now*10+9<=n)	{ans=ans+9;now=now*10+9;}
	//printf("%d %d\n",now,ans);
	n=n-now;
	while (n>0)
	{
		ans=ans+n%10;
		n/=10;
	}
	printf("%lld\n",ans);
	return 0;
}