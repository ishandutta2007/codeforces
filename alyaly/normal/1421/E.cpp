#include<bits/stdc++.h>
#define int long long
#define N 2000000
#define inf 999999999999
using namespace std;
int n,dp[N+1][3][2][2];
int a[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=0;j<=2;j++)dp[i][j][0][0]=dp[i][j][0][1]=dp[i][j][1][0]=dp[i][j][1][1]=-inf;
	dp[1][1][0][0]=a[1],dp[1][2][1][0]=-a[1];
	for(int i=1;i<n;i++){
		for(int j=0;j<=2;j++){
			dp[i+1][(j+1)%3][0][0]=max(dp[i+1][(j+1)%3][0][0],dp[i][j][1][0]+a[i+1]);
			dp[i+1][(j+2)%3][1][0]=max(dp[i+1][(j+2)%3][1][0],dp[i][j][0][0]-a[i+1]);
			dp[i+1][(j+1)%3][0][1]=max(dp[i+1][(j+1)%3][0][1],max(dp[i][j][0][0],max(dp[i][j][0][1],dp[i][j][1][1]))+a[i+1]);
			dp[i+1][(j+2)%3][1][1]=max(dp[i+1][(j+2)%3][1][1],max(dp[i][j][1][0],max(dp[i][j][1][1],dp[i][j][0][1]))-a[i+1]);
		}
	}
	cout<<max(dp[n][1][0][1],dp[n][1][1][1])<<endl;
	return 0;
}