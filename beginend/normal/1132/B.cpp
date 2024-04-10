#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,a[N],m;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	scanf("%d",&m);
	LL ans=0;
	for (int i=1;i<=n;i++) ans+=a[i];
	while (m--)
	{
		int x;scanf("%d",&x);
		printf("%lld\n",ans-a[n-x+1]);
	}
	return 0;
}