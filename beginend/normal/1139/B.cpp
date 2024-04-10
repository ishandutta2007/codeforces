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
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	LL ans=a[n];
	for (int i=n-1;i>=1;i--) a[i]=std::min(a[i],a[i+1]-1),ans+=std::max(a[i],0);
	printf("%lld\n",ans);
	return 0;
}