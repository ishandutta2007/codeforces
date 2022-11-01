# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
long long a[xn], b[xn];
pair <long long ,long long> dp[xn];

int main(){
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<k; i++) b[0] += a[i];
	for (int i=1; i<n-k+1; i++) b[i] = b[i-1]+a[i+k-1]-a[i-1];
	long long int mx = k;
	dp[k].first = 0;
	dp[n-k].second = n-k;
	for (int i=k+1; i<n-k+1; i++){
		if (b[dp[i-1].first] >= b[i-k]) dp[i].first = dp[i-1].first;
		else dp[i].first = i-k;
	}
	for (int i=n-k-1; i>=k; i--){
		if (b[dp[i+1].second] > b[i]) dp[i].second = dp[i+1].second;
		else dp[i].second = i;
	}
	mx = k;
	for (int i=k+1; i<n-k+1; i++){
		if (b[dp[i].first] + b[dp[i].second] > b[dp[mx].first] + b[dp[mx].second]) mx = i;
	}
	cout << dp[mx].first+1 << ' ' << dp[mx].second+1;
}