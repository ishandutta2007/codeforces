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
		scanf("%lld",&n);
		for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
		bool tf=false;
		for (LL u=1;u<n;u++) if (a[u]!=a[u+1]) tf=true;
		if (tf) printf("1\n");
		else printf("%lld\n",n);
	}
	return 0;
}