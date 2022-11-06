#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

std::vector<std::pair<int, int>> getSubstrings(std::string num) {
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < num.size(); ++i) {
		int curr = 0;
		for (int j = i; j < num.size(); ++j) {
			curr = curr * 10 + num[j] - '0';
			res.push_back({ curr, j - i + 1});
		}
	}
	std::sort(res.begin(), res.end(), [](const std::pair<int, int> &l, const std::pair<int, int> &r) {
		return l.second < r.second;
	});
	return res;
}

int n;
std::string num[70000];
std::vector<std::pair<int, int>> substrs[70000];

std::unordered_map<int, int> occ[10];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i < 10; ++i)
		occ[i].reserve(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];
		substrs[i] = getSubstrings(num[i]);
		for (auto &&x : substrs[i])
			++occ[x.second][x.first];
	}

	for (int i = 0; i < n; ++i) {
		for (auto &&x : substrs[i])
			--occ[x.second][x.first];

		std::pair<int, int> ans;

		for (auto &&x : substrs[i])
			if (!occ[x.second][x.first]) {
				ans = x;
				break;
			}

		for (auto &&x : substrs[i])
			++occ[x.second][x.first];

		std::string s = std::to_string(ans.first);
		for (int i = ans.second - s.size(); i > 0; --i)
			std::cout << '0';
		std::cout << s << '\n';
	}
	return 0;
}