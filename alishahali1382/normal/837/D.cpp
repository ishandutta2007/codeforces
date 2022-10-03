#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int max5=5151,maxn=200;
int inf=1000000000;

int dp[2][maxn+1][max5+1];
int A[maxn][2];

int main(){
	int n,k;
	cin>>n>>k;
	long long temp;
	for (int i=0;i<n;i++){
		cin>>temp;
		while (temp%2==0){
			temp/=2;
			A[i][0]++;
		}
		while (temp%5==0){
			temp/=5;
			A[i][1]++;
		}
	}
	for (int j=0;j<=n;j++){
		for (int p=0;p<=max5;p++){
			dp[0][j][p]=-inf;
		}
	}
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k && j<=i;j++){
			for (int p=0;p<=max5;p++){
				if (p>=A[i-1][1]){
					dp[1][j][p]=max(dp[0][j-1][p-A[i-1][1]]+A[i-1][0],dp[0][j][p]);
				}
				else{
					dp[1][j][p]=dp[0][j][p];
				}
			}
		}
		for (int j=i+1;j<=k;j++){
			for (int p=0;p<=max5;p++){
				dp[1][j][p]=-inf;
			}
		}
		// memory things!
		for (int j=0;j<=200;j++){
			for (int p=0;p<=max5;p++){
				dp[0][j][p]=dp[1][j][p];
				dp[1][j][p]=0;
			}
		}
		for (int p=1;p<=max5;p++){
			dp[0][0][p]=-inf;
		}
	}
	int out=0;
	for (int i=1;i<=max5;i++){
		out=max(out,min(i,dp[0][k][i]));
	}
	
	cout<<out<<endl;
	
	
	return 0;
}