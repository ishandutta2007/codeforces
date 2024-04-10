#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
long long A[2][300 * 1000 + 10];
long long ps[300 * 1000 + 10];
long long dp[2][300 * 1000 + 10];

long long f(long long x){
	if (x==n){
		return 0;
	}
	return max((long long)f(x+1)+A[x%2][x]*2*x+A[(x+1)%2][x]*(2*x+1),(long long) dp[x%2][x]+ps[x]*2*x);
}


int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (long long i=0; i<2; i++){
		for (long long j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	ps[n-1]=A[0][n-1]+A[1][n-1];
	for (long long i=n-2; i>=0; i--){
		ps[i]=ps[i+1]+A[0][i]+A[1][i];
	}
	
	dp[0][n-1]=A[1][n-1];
	dp[1][n-1]=A[0][n-1];
	
	for (long long i=n-2; i>=0; i--){
		dp[0][i]=dp[0][i+1]+ps[i+1]+((n-i)*2-1)*A[1][i];
		dp[1][i]=dp[1][i+1]+ps[i+1]+((n-i)*2-1)*A[0][i];
	}/*
	for (long long i=0; i<n; i++){
		cout<<ps[i]<<' ';
	}
	cout<<endl;*/
	cout<<f(0)<<endl;
	
	return 0;
}