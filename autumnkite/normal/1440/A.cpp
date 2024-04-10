#include <bits/stdc++.h>

const int N = 1005, INF = 0x3f3f3f3f;

int n, cost[2], cnt[2], h;
char a[N];

void solve() {
	std::cin >> n >> cost[0] >> cost[1] >> h;
	std::cin >> a;
	cnt[0] = cnt[1] = 0;
	for (int i = 0; i < n; ++i) {
		++cnt[a[i] ^ '0'];
	}
	int ans = INF;
	for (int i = 0; i <= n; ++i) {
		ans = std::min(ans, abs(cnt[0] - i) * h + cost[0] * i + cost[1] * (n - i));
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}