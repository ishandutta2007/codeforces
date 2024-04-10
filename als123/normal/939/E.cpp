#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=500005;
LL n;
LL a[N];
LL sum[N];
struct qq
{
	LL op,x;
}s[N];
int main()
{
	scanf("%I64d",&n);
	LL lalal=0;
	for (LL u=1;u<=n;u++)	
	{
		scanf("%I64d",&s[u].op);
		if (s[u].op==1) 
		{
			scanf("%I64d",&s[u].x);
			lalal++;
			sum[lalal]=sum[lalal-1]+s[u].x;
		}
	}
	LL mx=0;
	LL tot=0;//
	for (LL u=1;u<=n;u++)
	{
		if (s[u].op==1)
		{
			mx=max(mx,s[u].x);
			tot++;
		}
		else
		{
			LL l=1,r=tot-1;
			LL ans=1;
			while (l<=r)
			{
				LL mid=(l+r)>>1;
				if (sum[mid-1]+mx>=(sum[mid]-sum[mid-1])*mid)	
				{
					l=mid+1;
					ans=mid;
				}
				else r=mid-1;
			}
			double tt=1.0*(sum[ans]+mx)/(double)(ans+1);
			printf("%.8lf\n",mx-tt);
		}
	}
	return 0;
}