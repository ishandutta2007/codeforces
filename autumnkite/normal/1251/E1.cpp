#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		int p, m;
		std::cin >> m >> p;
		v[m].push_back(p);
	}
	std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
	long long ans = 0;
	int pre = n;
	for (int i = n - 1; i >= 0; --i) {
		for (int x : v[i]) {
			Q.push(x);
		}
		pre -= v[i].size();
		while (pre < i) {
			ans += Q.top();
			Q.pop();
			++pre;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}