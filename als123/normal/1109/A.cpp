#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=5000005;
int n;
int a[N];
int sum[N];
int g[2][N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) sum[u]=sum[u-1]^a[u];
	g[0][0]=1;
	LL ans=0;
	for (int u=1;u<=n;u++)
	{
		ans=ans+g[u&1][sum[u]];
		g[u&1][sum[u]]++;
	}
	printf("%lld\n",ans);
	return 0;
}