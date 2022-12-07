#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=55;
LL a[N];
LL b[N];
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL n;
		scanf("%lld",&n);
		LL sum=0;
		for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
		for (LL u=1;u<=n;u++) sum=sum+a[u];
		LL cnt=0;
		for (LL u=1;u<=n;u+=2) cnt=cnt+a[u]-1;
		if (cnt*2<=sum)
		{
			for (LL u=1;u<=n;u+=2) a[u]=1;
		}
		else
		{
			for (LL u=2;u<=n;u+=2) a[u]=1;
		}
		for (LL u=1;u<=n;u++) printf("%lld ",a[u]);
		printf("\n");
	}
	return 0;
}