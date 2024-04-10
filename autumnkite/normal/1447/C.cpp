#include <bits/stdc++.h>

const int N = 200005;

int n;
std::pair<int, int> a[N];
long long W;

void solve() {
	std::cin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a + 1, a + 1 + n);
	std::vector<int> ans;
	long long now = 0;
	for (int i = n; i; --i) {
		if (now + a[i].first <= W) {
			now += a[i].first;
			ans.push_back(a[i].second);
			if (now >= (W + 1) / 2) {
				std::cout << ans.size() << "\n";
				for (int id : ans) {
					std::cout << id << " ";
				}
				std::cout << "\n";
				return;
			}
		}
	}
	std::cout << -1 << "\n";
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