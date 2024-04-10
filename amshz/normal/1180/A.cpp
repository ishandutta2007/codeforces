# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
long long dp[xn];

int main(){
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i=2; i<=n; i++) dp[i] = dp[i-1]+4*i-4;
	cout << dp[n];
}