#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> fa(n);
	for (int i = 1; i < n; ++i) {
		std::cin >> fa[i];
		--fa[i];
	}
	std::vector<int> dep(n);
	for (int i = 1; i < n; ++i) {
		dep[i] = dep[fa[i]] + 1;
	}
	std::vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[dep[i]] ^= 1;
	}
	std::cout << std::accumulate(ans.begin(), ans.end(), 0) << "\n";
}