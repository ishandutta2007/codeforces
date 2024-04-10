#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=500005;
const LL inf=(LL)1e18;

int n,r;
LL k,a[N],b[N];

bool check(LL mid)
{
	for (int i=1;i<=n+1;i++) b[i]=0;
	LL ret=k;
	for (int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
		if (a[i]+b[i]<mid)
		{
			if (mid-a[i]-b[i]>ret) return 0;
			LL ned=mid-a[i]-b[i];
			ret-=ned;
			b[i]+=ned;b[min(n+1,i+r+r+1)]-=ned;
		}
	}
	return 1;
}

int main()
{
	scanf("%d%d%I64d",&n,&r,&k);
	for (int i=1;i<=n;i++)
	{
		LL x;scanf("%I64d",&x);
		a[max(1,i-r)]+=x;a[min(n+1,i+r+1)]-=x;
	}
	LL mn=inf;
	for (int i=1;i<=n;i++) a[i]+=a[i-1],mn=min(mn,a[i]);
	LL l=mn,r=mn+k;
	while (l<=r)
	{
		LL mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%I64d",l-1);
	return 0;
}