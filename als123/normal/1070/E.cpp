#include <bits/stdc++.h>
#define LL long long

const int maxn=2e5+7;

using namespace std;

int T,n,m;
LL t;
LL a[maxn];
LL ans,maxx;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%lld",&n,&m,&t);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		maxx=-1,ans=0;
		LL l=1,r=t;
		while (l<=r)
		{
			LL mid=(l+r)/2;
			LL num=0,ft=0;
			LL sum=0,ct=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]<=mid)
				{
					num++;
					ct+=(LL)a[i];
					sum+=(LL)a[i];
					if (sum<=t) ft++; 
					if (num==m)
					{
						sum+=ct;
						ct=0;
						num=0;
					}
				}
			}
			if (ft>maxx)
			{
				maxx=ft;
				ans=mid;
			}
			if (sum>=t) r=mid-1;
			       else l=mid+1; 
		}
		printf("%lld %lld\n",maxx,ans);
 	}
}