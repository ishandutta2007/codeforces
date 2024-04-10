#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=300005;
struct qq
{
	LL val,id;
}a[N];
LL n;
int main()
{
	scanf("%lld",&n);
	LL sum=0;
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld%lld",&a[u].val,&a[u].id);
		sum=sum+a[u].val;
	}
	if (sum<0)
	{
		for (LL u=1;u<=n;u++) a[u].val=-a[u].val;
	}
	LL ans=0;
	for (LL u=61;u>=0;u--)
	{
		sum=0;
		for (LL i=1;i<=n;i++)
			if (a[i].id==(1LL<<u)) sum=sum+a[i].val;
		if (sum>0)
		{
			ans=ans|(1LL<<u);
		}
		for (LL i=1;i<=n;i++)
			if (a[i].id&(1LL<<u))
			{				
				a[i].id^=(1LL<<u);
				if (sum>0) a[i].val=-a[i].val;
			}
	}
	printf("%lld\n",ans);
	return 0;
}