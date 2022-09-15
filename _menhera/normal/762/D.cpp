#include<bits/stdc++.h>
using namespace std;
int N;
long long int x[101010][3];
long long int dp[101010][3];
int main()
{
	scanf("%d",&N);
	for(int q=0; q<3; q++)
		for(int i=0; i<N; i++)
			scanf("%lld",&x[i][q]);
	
	dp[0][0]=0;
	dp[0][1]=-1e18;
	dp[0][2]=-1e18;
	for(int i=1; i<=N; i++)
	{
		dp[i][0]=-1e18;
		dp[i][1]=-1e18;
		dp[i][2]=-1e18;
		dp[i][0]=max(dp[i][0], dp[i-1][0]+x[i-1][0]);
		//printf("-%lld\n",dp[i][0]);
		dp[i][1]=max(dp[i][1], dp[i-1][0]+x[i-1][0]+x[i-1][1]);
		dp[i][2]=max(dp[i][2], dp[i-1][0]+x[i-1][0]+x[i-1][1]+x[i-1][2]);
		if(i!=1) dp[i][0]=max(dp[i][0], dp[i-2][2]+x[i-1][0]+x[i-1][1]+x[i-1][2]+x[i-2][0]+x[i-2][1]+x[i-2][2]);
		dp[i][1]=max(dp[i][1], dp[i-1][1]+x[i-1][1]);
		dp[i][0]=max(dp[i][0], dp[i-1][1]+x[i-1][1]+x[i-1][0]);
		dp[i][2]=max(dp[i][2], dp[i-1][1]+x[i-1][1]+x[i-1][2]);
		dp[i][2]=max(dp[i][2], dp[i-1][2]+x[i-1][2]);
		dp[i][1]=max(dp[i][1], dp[i-1][2]+x[i-1][2]+x[i-1][1]);
		dp[i][0]=max(dp[i][0], dp[i-1][2]+x[i-1][2]+x[i-1][1]+x[i-1][0]);
		if(i!=1) dp[i][2]=max(dp[i][2], dp[i-2][0]+x[i-1][0]+x[i-1][1]+x[i-1][2]+x[i-2][0]+x[i-2][1]+x[i-2][2]);
//		printf("%d: %lld %lld %lld\n",i,dp[i][0], dp[i][1],dp[i][2]);
	}
	printf("%lld",dp[N][2]);
}