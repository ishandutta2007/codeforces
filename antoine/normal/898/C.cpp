#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	std::map<string, std::set<string>> all;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		string name;
		std::cin >> name;
		int m;
		std::cin >> m;
		for (; m > 0; --m) {
			string num;
			cin >> num;
			all[name].insert(num);
		}
	}
	for (auto &&x : all) {
		std::set<string> suffixes;
		for (auto &&y : x.second) {
			for (int i = 1; i < y.size(); ++i)
				suffixes.insert(y.substr(i));
		}
		for (auto it = x.second.begin(); it != x.second.end();) {
			if (suffixes.count(*it)) {
				it = x.second.erase(it);
				it = x.second.begin();
			}
			else
				++it;
		}
	}
	for (auto it = all.begin(); it != all.end();)
		if (it->second.empty())
			it = all.erase(it);
		else
			++it;

	std::cout << all.size();
	for (auto &&x : all) {
		std::cout << "\n" << x.first << " " << x.second.size();
		for (auto &&y : x.second)
			std::cout << " " << y;
	}
	return 0;
}