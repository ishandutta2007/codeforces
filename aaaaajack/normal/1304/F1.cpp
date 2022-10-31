#include<bits/stdc++.h>
#define M 20010
#define N 60
using namespace std;
int dp[N][M],pmx[N][M],smx[N][M];
int sum[N][M];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&sum[i][j]);
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=0;i<n;i++){
		if(i){
			for(int j=k;j<=m;j++){
				for(int t=max(0,j-k);t<=j;t++){
					dp[i][j]=max(dp[i][j],pmx[i-1][t]+sum[i][j]-sum[i][t]);
				}
				for(int t=j;t<=min(m+1,j+k);t++){
					dp[i][j]=max(dp[i][j],smx[i-1][t]+sum[i][t-k]-sum[i][j-k]);
				}
				dp[i][j]+=sum[i+1][j]-sum[i+1][j-k];
			}
		}
		else{
			for(int j=k;j<=m;j++){
				dp[i][j]=sum[i][j]-sum[i][j-k]+sum[i+1][j]-sum[i+1][j-k];
			}
		}
		for(int j=k;j<=m;j++) pmx[i][j]=max(pmx[i][j-1],dp[i][j]);
		for(int j=m;j>=k;j--) smx[i][j]=max(smx[i][j+1],dp[i][j]);
	}	
	printf("%d\n",pmx[n-1][m]);
	return 0;
}