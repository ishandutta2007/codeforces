#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,m;
LL a[N],b[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),b[i]=-a[i]+a[i-1];
	LL ans=a[n]-a[1];
	std::sort(b+2,b+n+1);
	for (int i=2;i<=m;i++) ans+=b[i];
	printf("%lld\n",ans);
	return 0;
}