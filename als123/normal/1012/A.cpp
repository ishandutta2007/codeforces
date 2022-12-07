#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL a[N];
int main()
{
	LL n;
	scanf("%lld",&n);n<<=1;
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	sort(a+1,a+1+n);
	LL ans=(a[n>>1]-a[1])*(a[n]-a[n/2+1]);
	LL nn=(n>>1);
	for (int u=2;u<=n/2;u++)	ans=min(ans,(a[n]-a[1])*(a[u+nn-1]-a[u]));
	printf("%lld\n",ans);
	return 0;
}