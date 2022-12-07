#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
const LL MOD=998244353;
struct qq
{
	LL x,y,s,nxt;
}a[N];
LL n;
LL f[N];
LL sum[N];
int main()
{
	LL n;
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld%lld%lld",&a[u].x,&a[u].y,&a[u].s);
		LL l=1,r=u;
		while (l<=r)
		{
			LL mid=(l+r)>>1;
			if (a[mid].x>=a[u].y) {a[u].nxt=mid;r=mid-1;}
			else l=mid+1;	
		}
	}
	for (LL u=1;u<=n;u++)
	{
		LL k=a[u].nxt;
		f[u]=a[k].x-a[u].y;
		/*for (LL i=k;i<u;i++)
		f[u]=f[u]+f[i]+a[i+1].x-a[i].x;*/
		
		f[u]=f[u]+sum[u-1]-sum[k-1];
		f[u]%=MOD;
		sum[u]=sum[u-1]+f[u]+a[u+1].x-a[u].x;
		sum[u]%=MOD;
	}
	LL ans=0,now=0;
	for (LL u=1;u<=n;u++)
	{
		if (a[u].s==1)
		{
			ans=ans+f[u]+a[u].x-now;
			ans%=MOD;
			now=a[u].x;
		}
	}
	ans=ans+a[n].x+1-now;
	ans%=MOD;
	if (ans<0) ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}