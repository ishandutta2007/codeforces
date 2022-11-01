#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,k;
LL a[N];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=n;i>=1;i--) a[i]+=a[i+1];
	LL ans=a[1];
	std::sort(a+2,a+n+1);
	for (int i=1;i<k;i++) ans+=a[n-i+1];
	printf("%lld\n",ans);
	return 0;
}