#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,q,k;
LL a[N];
LL d[N];
LL sum[N];
int main()
{
	scanf("%lld%lld%lld",&n,&q,&k);
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	a[n+1]=k+1;
	for (LL u=1;u<=n;u++)
	{
		d[u]=(a[u]-a[u-1]-1)+(a[u+1]-a[u]-1);
		sum[u]=sum[u-1]+d[u];
	}
	while (q--)
	{
		LL l,r;
		scanf("%lld%lld",&l,&r);
		if (l==r) printf("%lld\n",k-1);
		else
		{
			LL ans=sum[r-1]-sum[l];
			ans=ans+a[l+1]-1-1;
			ans=ans+k-a[r-1]-1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}