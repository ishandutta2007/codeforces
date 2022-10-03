#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int ps[1002];
int n, m, k;
int mod=1000000007;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>k;
	for (int i=1; i<=1000; i++){
		dp[i][0]=1;
	}
	for (int j=1; j<=1000; j++){
		for (int i=1; i<=1001; i++){
			ps[i]=(ps[i-1]+dp[i-1][j-1])%mod;
		}
		for (int i=3; i<=1000; i++){
			dp[i][j]=(dp[i-1][j]+ps[i-1])%mod;
		}
	}/*
	for (int i=0; i<=7; i++){
		for (int j=0; j<=7; j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	cout<<((long long) dp[n][k]*dp[m][k])%mod<<endl;
	
	return 0;
}