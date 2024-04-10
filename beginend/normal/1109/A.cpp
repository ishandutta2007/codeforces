#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,a[N],s[2][(1<<20)+5];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	LL ans=0;
	for (int i=0;i<=n;i++)
	{
		ans+=s[i&1][a[i]];
		s[i&1][a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}