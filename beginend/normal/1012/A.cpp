#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n*2+1);
	LL ans=(LL)(a[n]-a[1])*(a[n*2]-a[n+1]);
	for (int i=2;i<=n;i++) ans=std::min(ans,(LL)(a[i+n-1]-a[i])*(a[n*2]-a[1]));
	printf("%lld\n",ans);
	return 0;
}