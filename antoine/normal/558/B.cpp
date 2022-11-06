#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
#include <climits>
#include <functional>
#include <queue>


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::unordered_map<int, std::pair<int, std::pair<int, int>>> data;
	for (int i = 1; i <= n; ++i) {
		int a;
		std::cin >> a;
		auto it = data.find(a);
		if (it == data.end())
			data[a] = { 1, {i, i} };
		else {
			++it->second.first;
			it->second.second.second = i;
		}
	}
	int freq = 0;
	int l = 0;
	int r = 0;
	for (auto p : data) {
		if (p.second.first > freq || (p.second.first == freq && (p.second.second.second - p.second.second.first < r - l))) {
			freq = p.second.first;
			l = p.second.second.first;
			r = p.second.second.second;
		}
	}
	std::cout << l << " " << r;
	return 0;
}