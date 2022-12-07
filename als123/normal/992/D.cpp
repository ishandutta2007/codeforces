#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,k;
LL a[N];
LL sum[N];
LL last;
LL lst[N];
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (LL u=1;u<=n;u++)	
	{
		scanf("%I64d",&a[u]);
		sum[u]=sum[u-1]+a[u];
	}
	last=0;
	for (LL u=1;u<=n;u++)
	{
		lst[u]=last;
		if (a[u]!=1)	last=u;
	}
	LL t=sum[n]*k;
	LL ans=0;
	for (LL u=1;u<=n;u++)
	{
		LL tot=a[u];
		LL now=u;
		while (tot<=t)
		{
			LL l=lst[now]+1,r=now;// 
			if (tot/(sum[u]-sum[l-1])<=k&&tot/(sum[u]-sum[r-1]))
			{
				LL L=l,R=r;
				while (L<=R)
				{
					LL mid=(L+R)>>1;
					LL xx=tot/(sum[u]-sum[mid-1]);
					LL xxx=tot%(sum[u]-sum[mid-1]);
					if (xx==k&&xxx==0) 	{ans++;break;}
					else if (xx<k) L=mid+1;
					else R=mid-1;
				}
			}
			now=lst[now];
			if (now<=0) break;
			if (t/a[now]<tot) break;
			tot=tot*a[now];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}