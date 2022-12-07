#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL a[N],n,k; 
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
		if (k&1)
		{
			LL mx=a[1];
			for (LL u=2;u<=n;u++) mx=max(mx,a[u]);
			for (LL u=1;u<=n;u++) printf("%lld ",mx-a[u]);
			printf("\n");
		}
		else
		{
			LL mn=a[1];
			for (LL u=2;u<=n;u++) mn=min(mn,a[u]);
			for (LL u=1;u<=n;u++) printf("%lld ",a[u]-mn);
			printf("\n");
		}
	}
	return 0;
}