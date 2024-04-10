#include <bits/stdc++.h>

const int N = 200005;

int n, a[N];
long long sum[N];
int ans;

void extend(int L, int R) {
	if ((a[L] ^ a[R]) == sum[R - 1] - sum[L]) {
		++ans;
	}
	if (sum[R] - sum[L - 1] >= (1 << 30)) {
		return;
	}
	int l = 1, r = std::min(n - R, L - 1), ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (sum[R + mid] - sum[L - mid - 1] >= 2 * (sum[R] - sum[L - 1])) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (ans != -1) {
		extend(L - ans, R + ans);
	}
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	ans = 0;
	for (int i = 1; i <= n - 2; ++i) {
		extend(i, i + 2);
	}
	for (int i = 1; i <= n - 3; ++i) {
		extend(i, i + 3);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}