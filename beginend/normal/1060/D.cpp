#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,a[N],b[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+n+1);
	LL ans=0;
	for (int i=1;i<=n;i++) ans+=(LL)std::max(a[i],b[i]);
	ans+=(LL)n;
	printf("%lld\n",ans);
	return 0;
}