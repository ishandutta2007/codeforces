#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,a[N],b[N];
LL f[N][2];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
	{
		f[i][0]=std::max(f[i-1][0],f[i-1][1]+(LL)a[i]);
		f[i][1]=std::max(f[i-1][1],f[i-1][0]+(LL)b[i]);
	}
	printf("%lld\n",std::max(f[n][0],f[n][1]));
	return 0;
}