#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1e16 + 228;

pair<ll, ll> relax(const pair<ll, ll>& a, ll b) {
	if (b > a.first) {
		return { b, a.first };
	}
	if (b > a.second) {
		return { a.first, b };
	}
	return a;
}

bool may(const pair<ll, ll>& a, ll b) {
	return a.first != b && a.second != b;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	int pw = 1;
	while (pw <= n) {
		pw <<= 1;
	}
	vector<pair<ll, ll>> dp(pw, { -INF, -INF });
	for (int i = 1; i <= n; i++) {
		dp[a[i - 1]] = relax(dp[a[i - 1]], i);
	}
	for (int m = 0; m < pw; m++) {
		for (int i = 0; (1 << i) < pw; i++) {
			int um = m | (1 << i);
			if (um != m) {
				if (may(dp[um], dp[m].first)) {
					dp[um] = relax(dp[um], dp[m].first);
				}
				if (may(dp[um], dp[m].second)) {
					dp[um] = relax(dp[um], dp[m].second);
				}
			}
		}
	}
	ll ans = -INF;
	for (auto p : dp) {
		if (p.second != -INF) {
			ans = max(ans, p.first * p.second - k * (a[p.first - 1] | a[p.second - 1]));
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}