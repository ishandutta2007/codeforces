# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
long long dp[xn];
map <int,long long> mp;

int main(){
	int n, mx, a;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		mp[a] += a;
		if (a > mx) mx = a;
	}
	dp[1] = mp[1];
	for (int i=2; i<=mx; i++){
		if (dp[i-1] > dp[i-2]+mp[i]) dp[i] = dp[i-1];
		else dp[i] = dp[i-2]+mp[i];
	}
	cout << dp[mx];
}