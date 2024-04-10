#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, p;
	std::cin >> n >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::priority_queue<std::pair<int, int>> Q;
	std::priority_queue<int> R;
	for (int i = 0; i < n; ++i) {
		Q.emplace(-a[i], -i);
	}
	std::vector<long long> ans(n, -1);
	long long now = -1;
	while (!Q.empty() || !R.empty()) {
		int lst;
		if (!R.empty()) {
			lst = -R.top();
			now += p;
			R.pop();
		} else {
			lst = -Q.top().second;
			now = -Q.top().first + p;
			Q.pop();
		}
		ans[lst] = now;
		while (!Q.empty() && -Q.top().first <= now) {
			int t = -Q.top().second;
			if (t > lst) {
				R.push(-t);
			} else {
				lst = t;
				now += p;
				ans[lst] = now;
			}
			Q.pop();
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}