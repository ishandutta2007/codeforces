#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	const long long INF = 1e18;
	int n;
	long long k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long ans = INF;
	vector<long long> pre(n);
	for (int i = 0; i < n; ++i) {
		pre[i] = a[i] + (i ? pre[i - 1] : 0);
	}
	vector<long long> suf(n);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = a[i] + (i != n - 1 ? suf[i + 1] : 0);
	}
	ans = min(ans, max(pre.back() - k, 0ll));
	auto fdiv = [](long long a, long long b) {
		return a   / b - ((a ^ b) < 0 && a % b);
	};
	for (int i = n - 1; i >= 1; --i) {
		long long moves = n - 1 - i + 1;
		long long cur = pre[i - 1] - a[0];
		long long times = a[0] - fdiv(k - cur, moves + 1);
		times = max(times, 0ll);
		moves += times;
		ans = min(ans, moves);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}