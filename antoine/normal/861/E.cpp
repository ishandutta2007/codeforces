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

int n;
bool occupied[100001] = { false };
int e = 0;
std::vector<std::pair<std::string, int>> input;
std::vector<int> nums[2];
std::vector<int> spots[2];
std::vector<std::pair<std::string, int>> weird;
std::vector<std::string> ans;

bool isWeird(const std::string &name) {
	if (name[0] < '1' || name[0] > '9')
		return true;
	int num = name[0] - '0';
	for (int i = 1; i < name.size(); ++i) {
		if (name[i] < '0' || name[i] > '9')
			return true;
		num = num * 10 + name[i] - '0';
	}
	return num > n;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::memset(occupied, false, sizeof occupied);

	std::cin >> n;
	input.resize(n);
	ans.reserve(2 * n + 5);

	for (int i = 0; i < n; ++i) {
		std::cin >> input[i].first >> input[i].second;
		e += input[i].second;
	}

	for (int i = 0; i < n; ++i) {
		const std::string &name = input[i].first;
		const int &type = input[i].second;

		if (isWeird(name))
			weird.push_back({ name, type });
		else {
			int num = stoi(name);
			occupied[num] = true;
			if ((type == 0) != (num > e))
				nums[type].push_back(num);
		}
	}

	for (int i = 1; i <= n; ++i)
		if (!occupied[i])
			spots[i <= e].push_back(i);


	if (weird.empty() && !nums[0].empty()) {
		const std::string myName = "jg4k9d";
		ans.push_back(std::to_string(nums[0].back()) + " " + myName);
		weird.push_back({ myName, 0 });
		spots[1].push_back(nums[0].back());
		nums[0].pop_back();
	}

	while (!nums[0].empty() || !nums[1].empty()) {
		for (int type : {0, 1})
			if (!nums[type].empty() && !spots[type].empty()) {
				ans.push_back(std::to_string(nums[type].back()) + " " + std::to_string(spots[type].back()));
				spots[!type].push_back(nums[type].back());
				spots[type].pop_back();
				nums[type].pop_back();
			}
	}

	std::cout << (ans.size() + weird.size()) << '\n';
	for (auto &&x : ans)
		std::cout << "move " << x << '\n';
	for (auto &&x : weird) {
		const int &type = x.second;
		std::cout << "move " << x.first << " " << spots[type].back() << '\n';
		spots[type].pop_back();
	}
	return 0;
}