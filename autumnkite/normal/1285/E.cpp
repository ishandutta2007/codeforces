#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<std::pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i].first >> a[i].second;
		}
		std::sort(a.begin(), a.end());

		std::vector<int> s(n);
		std::vector<int> mx(n);
		mx[0] = a[0].first - 1;
		for (int i = 0; i < n - 1; ++i) {
			s[i + 1] = s[i] + (mx[i] < a[i].first);
			mx[i + 1] = std::max(mx[i], a[i].second);
		}

		std::vector<int> sta;
		for (int i = n - 1; i >= 0; --i) {
			s[i] += sta.rend() - std::upper_bound(sta.rbegin(), sta.rend(), mx[i]);
			while (!sta.empty() && sta.back() <= a[i].second) {
				sta.pop_back();
			}
			sta.push_back(a[i].first);
		}

		std::cout << *std::max_element(s.begin(), s.end()) << "\n";
	}
}