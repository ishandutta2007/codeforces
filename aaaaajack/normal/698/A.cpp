#include<bits/stdc++.h>
using namespace std;
int dp[110][3];
int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x&1) dp[i][1]=min(dp[i-1][2],dp[i-1][0]);
		if(x&2) dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
		dp[i][0]=min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][0])+1;
	}
	printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
	return 0;
}