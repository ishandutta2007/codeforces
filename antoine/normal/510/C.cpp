#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

int n;
char names[100][102];
std::set<char> adj[26];
enum Color { white, grey, black };
Color clr[26];

bool dfs(char c, std::vector<char> &nodes) {
	if (clr[c - 'a'] != white)
		return clr[c - 'a'] == black;
	clr[c - 'a'] = grey;
	for (char d : adj[c - 'a'])
		if (!dfs(d, nodes))
			return false;
	clr[c - 'a'] = black;
	nodes.push_back(c);
	return true;
}

std::vector<char> dfs() {
	for (char i = 0; i < 26; ++i)
		clr[i] = white;
	std::vector<char> nodes;
	for (char c = 'a'; c <= 'z'; ++c)
		if (!dfs(c, nodes)) {
			nodes.clear();
			break;
		}
	return nodes;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> names[i];
	for (int i = 1; i < n; ++i) {
		int j = 0;
		while (names[i][j] && names[i][j] == names[i - 1][j])
			++j;
		if (!names[i - 1][j])
			continue;
		if (!names[i][j]) {
			std::cout << "Impossible";
			return 0;
		}
		adj[names[i - 1][j] - 'a'].insert(names[i][j]);
	}
	auto result = dfs();
	if (result.empty())
		std::cout << "Impossible";
	else
		for (auto it = result.rbegin(); it != result.rend(); ++it)
			std::cout << *it;
	return 0;
}