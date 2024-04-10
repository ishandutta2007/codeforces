#include<bits/stdc++.h>
using namespace std;
int in[20][1<<17];
int dp[20][1<<17][3];
//0: only lose
//1: only win
//2: both win and lose
int main(){
	int n,k,x;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d",&x);
		in[0][x-1]=1;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<(1<<n-1);i++){
		if(in[0][i<<1|1]&&in[0][i<<1]){
			dp[0][i][2]=1;
		}
		else if(in[0][i<<1|1]||in[0][i<<1]){
			dp[0][i][0]=1;
			dp[0][i][1]=1;
		}
	}
	for(int j=1;j<n;j++){
		for(int i=0;i<(1<<n-j-1);i++){
			for(int b=0;b<2;b++){
				if(dp[j-1][i<<1|b][0]>=0 && dp[j-1][i<<1|(b^1)][1]>=0){
					dp[j][i][2]=max(dp[j][i][2],dp[j-1][i<<1|b][0] + dp[j-1][i<<1|(b^1)][1]+3);
				}
				if(dp[j-1][i<<1|b][2]>=0){
					dp[j][i][2]=max(dp[j][i][2],dp[j-1][i<<1|b][2]+max(max(dp[j-1][i<<1|(b^1)][2],max(dp[j-1][i<<1|(b^1)][0],dp[j-1][i<<1|(b^1)][1])),0)+3);
				}
				if(dp[j-1][i<<1|b][1]>=0){
					dp[j][i][1]=max(dp[j][i][1],dp[j-1][i<<1|b][1]+max(dp[j-1][i<<1|(b^1)][1],0)+1);
				}
				if(dp[j-1][i<<1|b][0]>=0){
					dp[j][i][0]=max(dp[j][i][0],dp[j-1][i<<1|b][0]+max(max(dp[j-1][i<<1|(b^1)][0],dp[j-1][i<<1|(b^1)][1]),0)+2);
				}
			}
		}
	}
	printf("%d\n",max(dp[n-1][0][0],max(dp[n-1][0][1],dp[n-1][0][2]))+1);
	return 0;
}