#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,k,m;
LL a[N];

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for (int i=2;i<=n;i++) a[i]+=a[i-1];
	double mx=0;
	for (int i=0;i<=std::min(m,n-1);i++)
	{
		LL ans=a[n]-a[i]+std::min((LL)(m-i),(LL)k*(n-i));
		mx=std::max(mx,(double)ans/(n-i));
	}
	printf("%.10lf\n",mx);
	return 0;
}