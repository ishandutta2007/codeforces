#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n;
LL a[N],b[N],sum[N];
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)	scanf("%lld",&a[u]);
	sort(a+1,a+1+n);
	LL nn=1;
	for (LL u=2;u<=n;u++) if (a[u]!=a[nn]) a[++nn]=a[u];
	n=nn;nn=n-1;
	LL ans=n;
	for (LL u=1;u<=nn;u++) b[u]=a[u+1]-a[u]-1;
	sort(b+1,b+nn+1);
	for (LL u=1;u<=nn;u++) sum[u]=sum[u-1]+b[u];
	/*for (LL u=1;u<=nn;u++) printf("%lld ",b[u]);
	printf("\n");
	for (LL u=1;u<=n;u++) printf("%lld ",a[u]);
	printf("\n");*/
	LL Q;
	scanf("%lld",&Q);
	for (LL u=1;u<=Q;u++)
	{
		LL l,r,lalal;
		scanf("%lld%lld",&l,&r);
		LL x=r-l;
		l=1;r=nn;lalal=0;
		while (l<=r)
		{
			LL mid=(l+r)>>1;
			if (b[mid]<=x)
			{
				l=mid+1;lalal=mid;
			}
			else r=mid-1;
		}
		//printf("%lld %lld %lld",lalal,x,b[lalal]);
		printf("%lld\n",ans+sum[lalal]+x*(nn-lalal+1));
	}
	return 0;
}