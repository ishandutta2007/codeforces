#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, K, S;
int dp[200][20000];
int Q[200];
int main()
{
	scanf("%d%d%d",&N,&K,&S);
	for(int i=0;i<N;i++)
		scanf("%d",Q+i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j>=1; j--)
		for(int k=i; k<15000;k++)
			dp[j][k]=min(dp[j][k],dp[j-1][k-i]+Q[i]);
	}
	int c = min(14000, (K-1)*K/2+S);
	int ans = 987654321;
	//for(int i=0;i<20;i++)
	//	printf("%d " ,dp[4][i]);
	for(int i=0;i<=c;i++)
		ans = min(dp[K][i],ans);
	printf("%d\n",ans);
}