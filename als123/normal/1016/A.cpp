#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,m;
LL a[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<=n;u++) 	scanf("%lld",&a[u]);
	LL now=0;
	for (LL u=1;u<=n;u++)
	{
		now=now+a[u];
		printf("%lld ",now/m);
		now=now%m;
	}
	return 0;
}