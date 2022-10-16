#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,dp[105][2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+(a!=0&&a!=1)),dp[i][1]=max(dp[i-1][0]+(a!=0&&a!=2),dp[i-1][1]);
	}
	cout<<n-max(dp[n][0],dp[n][1]);
	return 0;
}