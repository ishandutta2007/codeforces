#include<bits/stdc++.h>
#define M 20010
#define N 60
using namespace std;
int dp[N][M],pmx[N][M],smx[N][M];
int sum[N][M];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&sum[i][j]);
			sum[i][j]+=sum[i][j-1];
		}
		for(int j=0;j<=m;j++){
			smx[i][j]=pmx[i][j]=-1e9;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=k;j<=m;j++){
			dp[i][j]=max(pmx[i-1][j-k],smx[i-1][j])+sum[i][j]-sum[i][j-k];
			pmx[i][j]=dp[i][j]-sum[i+1][j-k];
			smx[i][j-k]=dp[i][j]+sum[i+1][j];
		}
		for(int j=m;j>0;j--){
			pmx[i][j-1]=max(pmx[i][j-1],pmx[i][j]);
		}
		for(int j=0;j<m;j++){
			smx[i][j+1]=max(smx[i][j+1],smx[i][j]);
		}
		for(int j=1;j<=m;j++){
			pmx[i][j]+=sum[i+1][j];
			smx[i][j]-=sum[i+1][j];
		}
		for(int j=1;j<=m;j++){
			pmx[i][j]=max(pmx[i][j],pmx[i][j-1]);
		}
		for(int j=m;j>=1;j--){
			smx[i][j-1]=max(smx[i][j-1],smx[i][j]);
		}
	}	
	printf("%d\n",pmx[n][m]);
	return 0;
}