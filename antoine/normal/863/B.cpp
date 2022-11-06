#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>


int f(const std::vector<int> &w) {
	int ans = 0;
	for (int i = 0; i < w.size(); i += 2)
		ans += std::abs(w[i] - w[i + 1]);
	//std::cout << "F: " << ans << '\n';
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> w(2 * n);
	for (int i = 0; i < 2*n; ++i)
		std::cin >> w[i];
	std::sort(w.begin(), w.end());
	int ans = INT_MAX;
	for (int i = 0; i < w.size(); ++i) {
		int wi = w[i];
		w.erase(w.begin() + i);
		for (int j = i; j < w.size(); ++j) {
			int wj = w[j];
			w.erase(w.begin() + j);

			ans = std::min(ans, f(w));
			w.insert(w.begin() + j, wj);
		}
		w.insert(w.begin() + i, wi);
	}
	std::cout << ans << '\n';
	return 0;
}