#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 10005;
LL f[maxn],n,M=1e4;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tennis.in","r",stdin);
		freopen("tennis.out","w",stdout);
	#endif
	f[0]=1ll;f[1]=2ll;scanf("%lld",&n);
	for (int i=2;i<=M;i++) f[i]=f[i-1]+f[i-2];
	int ans=0;while (f[ans+1]<=n) ++ans;
	printf("%d",ans);
	return 0;
}