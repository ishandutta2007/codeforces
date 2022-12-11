#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define N 100
#define inf 999999999
using namespace std;
int n,a[N+1];
double B,b[N+1],dp[2][N+1][N*N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],b[i]/=2.0,B+=b[i];
	for(int i=0;i<=1;i++)for(int j=0;j<=i;j++)for(int k=0;k<=N*n;k++)dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=N*n;k++){
				if(dp[0][j][k]!=-inf){
					dp[1][j][k]=max(dp[1][j][k],dp[0][j][k]);
					dp[1][j+1][k+a[i+1]]=max(dp[1][j+1][k+a[i+1]],dp[0][j][k]+b[i+1]);
				}
			}
		}
		for(int j=0;j<=n;j++)for(int k=0;k<=N*n;k++)dp[0][j][k]=dp[1][j][k],dp[1][j][k]=-inf;
	}
	for(int i=1;i<=n;i++){
		double ans=0;
		for(int j=0;j<=N*n;j++)ans=max(ans,min(j*1.0,dp[0][i][j]+B));
		printf("%.9f ",ans);
	}
	printf("\n");
    return 0;
}
/*
4
10 7
5 4
11 9
7 5
*/