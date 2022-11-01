#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL n,k;

int main()
{
	scanf("%lld%lld",&n,&k);
	LL l=1,r=n;
	while (l<=r)
	{
		LL mid=(l+r)/2;
		if (mid*(mid+1)/2-(n-mid)>=k) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",n-(r+1));
	return 0;
}