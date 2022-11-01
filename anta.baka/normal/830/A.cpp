#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k, p;
int a[1000], b[2000];
int dp[1000][2000];

int f(int i, int j) { return llabs(a[i] - b[j]) + llabs(b[j] - p); }

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> p;
	for(int i = 0; i < n; i++) cin >> a[i]; sort(a, a + n);
	for(int i = 0; i < k; i++) cin >> b[i]; sort(b, b + k);

	for(int i = 0; i < k; i++) dp[0][i] = f(0, i);
	for(int i = 1; i < n; i++) {
		vector<int> x(k);
		x[i - 1] = dp[i - 1][i - 1];
		for(int j = i; j < k; j++) x[j] = min(x[j - 1], dp[i - 1][j]);
		for(int j = i; j < k; j++) dp[i][j] = max(x[j - 1], f(i, j));
	}

	int ans = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
	for(int i = n - 1; i < k; i++) ans = min(ans, dp[n - 1][i]); 
	cout << ans;
}