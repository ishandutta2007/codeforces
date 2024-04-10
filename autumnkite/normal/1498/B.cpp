#include <bits/stdc++.h>

void solve() {
	int n, W;
	std::cin >> n >> W;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::priority_queue<int> Q;
	for (int i = 0; i < n; ++i) {
		if (Q.empty() || Q.top() < a[i]) {
			Q.emplace(W);
		}
		int t = Q.top();
		Q.pop();
		t -= a[i];
		Q.emplace(t);
	}
	std::cout << Q.size() << "\n";
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