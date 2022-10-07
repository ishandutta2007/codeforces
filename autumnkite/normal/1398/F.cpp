#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x != y) {
			fa[x] = y;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<std::array<int, 2>> len(n + 1);
	for (int i = 0; i < n; ++i) {
		if (s[i] != '1') {
			len[i + 1][0] = len[i][0] + 1;
		}
		if (s[i] != '0') {
			len[i + 1][1] = len[i][1] + 1;
		}
	}
	std::vector<std::vector<int>> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		p[std::max(len[i][0], len[i][1])].push_back(i);
	}
	DSU D(n + 1);
	for (int x = 1; x <= n; ++x) {
		int ans = 0;
		for (int i = D.find(0) + 1; i <= n; i = i <= n ? D.find(i) + 1 : n + 1) {
			++ans;
			i += x - 1;
		}
		std::cout << ans << " \n"[x == n];
		for (int i : p[x]) {
			D.merge(i - 1, i);
		}
	}
}