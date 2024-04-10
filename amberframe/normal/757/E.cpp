#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
typedef long long LL;
const int maxn = 1000005;
const int mod = 1e9+7;

int dp[maxn][21],r,n,q;
int fr[maxn],is[maxn],tot,prm[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("functions.in","r",stdin);
		freopen("functions.out","w",stdout);
	#endif
	const int N = 1e6;
	for (int i=2;i<=N;i++)
	{
		if (!is[i]) {prm[++tot]=i;fr[i]=i;}
		for (int j=1;j<=tot;j++)
		{
			int num=prm[j]*i;
			if (num>N) break;
			is[num]=true;fr[num]=prm[j];
			if (i%prm[j]==0) break;
		}
	}
	
	dp[0][0]=1;
	for (int i=1;i<=20;i++) dp[0][i]=2;
	for (int i=1;i<=N;i++)
	{
		dp[i][0]=1;
		for (int j=1;j<=20;j++)
			dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
	}
	for (scanf("%d",&q);q--;) {
		scanf("%d %d",&r,&n);LL ans=1;
		while (n>1) {
			int t=fr[n],cnt=0;
			while (n%t==0) n/=t,++cnt;
			(ans*=dp[r][cnt])%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}