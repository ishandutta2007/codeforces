#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <set>

bool f(const std::string &s, long long k) {
	if (k > s.size()) return false;
	long long bits = 0;
	std::set<long long> strs;
	for (int i = 0; i < k; ++i) {
		bits = (bits << 1) | (s[i] - '0');
	}
	strs.insert(bits);
	for (int i = k; i < s.size(); ++i) {
		bits = (bits << 1) | (s[i] - '0');
		strs.insert(bits & ((1LL << k) - 1));
	}
	return strs.size() == (1LL << k);
}

int n, m;
std::string strs[205];
int ans[205] = { 0 };


void f(int i) {
	while (f(strs[i], ans[i] + 1))
		++ans[i];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n;
	std::vector<std::string> vs(n);
	for (int i = 1; i <= n; ++i) {
		std::cin >> strs[i];
		f(i);
		//std::cout << "comp" << ans[i] << '\n';
	}
	std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		std::cin >> a >> b;
		strs[n + i] = strs[a] + strs[b];
		ans[n + i] = std::max(ans[a], ans[b]);
		f(n + i);
		std::cout << ans[n + i] << '\n';
		if (strs[n + i].size() > 1e6)
			strs[n + i] = strs[n + i].substr(0, 1e5) + strs[n + i].substr(strs[n + i].size() - 1e5);
	}

	return 0;
}