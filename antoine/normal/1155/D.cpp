#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, X;
	cin >> n >> X;

	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	vector<array<ll, 5>> dp(n + 1, { 0, 0, 0, 0 });

	for (int i = n - 1; i >= 0; --i) {
		ll v[] = { 0, a[i], a[i] * X, a[i] };
		for (int j = 3; j >= 0; --j) {
			dp[i][j] = max(dp[i][j + 1], v[j] + dp[i + 1][j]);
		}
	}
	cout << dp[0][0];
	return 0;
}