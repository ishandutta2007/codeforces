#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 405;
const LL mod = 1e9+7;

LL dp[maxn],sp[maxn];int n;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("house.in","r",stdin);
		//freopen("house.out","w",stdout);
	#endif
	scanf("%d",&n);dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		memset(sp,0,sizeof sp);
		for (int j=0;j<=n;j++)
		for (int k=0;k+j<=n;k++)
			(sp[j+k]+=dp[j]*dp[k])%=mod;
		memset(dp,0,sizeof dp);
		for (int j=0;j<=n;j++)
			dp[j]=(sp[j-1]+sp[j+1]*(j+1)*j+sp[j]*(2ll*j+1))%mod;
	}
	printf("%lld",dp[1]);
	return 0;
}