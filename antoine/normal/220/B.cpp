#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	map<int, vector<int>> occ;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		occ[a[i]].push_back(i);
	}
	map<int, int> pos;
	pos[0] = 0;
	vector<int> elt = { 0 };

	for(auto &&x : occ)
		if (x.second.size() < x.first) {
			for (auto &&y : x.second)
				a[y] = 0;
		} else {
			pos[x.first] = elt.size();
			elt.push_back(x.first);
		}

	vector<vector<int>> cnt(n, vector<int>(pos.size(), 0));
	for (int i = 0; i < n; ++i) {
		if (i) cnt[i] = cnt[i - 1];
		++cnt[i][pos[a[i]]];
	}
	while (m-- > 0) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		int ans = 0;
		for (int i = 1; i < elt.size(); ++i)
			if (elt[i] == cnt[r][i] - (l ? cnt[l - 1][i] : 0))
				++ans;
		cout << ans << '\n';
	}
	return 0;
}