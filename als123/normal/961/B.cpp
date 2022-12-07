#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
int a[N];
int o[N];
int g[N],h[N];
int sum[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++)	
	{
		scanf("%d",&a[u]);
		sum[u]=sum[u-1]+a[u];
	}
	for (int u=1;u<=n;u++) scanf("%d",&o[u]);
	for (int u=1;u<=n;u++) g[u]=g[u-1]+a[u]*o[u];
	for (int u=n;u>=1;u--) h[u]=h[u+1]+a[u]*o[u];
	int ans=0;
	for (int u=1;u<=n-k+1;u++)	ans=max(ans,g[u-1]+h[u+k]+sum[u+k-1]-sum[u-1]);
	printf("%d\n",ans);
	return 0;
}