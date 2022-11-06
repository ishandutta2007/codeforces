#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct IdGen {
	map<int, int> mp;
	vector<int> lazy;
	void insert(int x) {
		assert(mp.empty());
		lazy.push_back(x);
	}
	void process() {
		assert(mp.empty());
		sort(lazy.begin(), lazy.end());
		lazy.erase(unique(lazy.begin(), lazy.end()), lazy.end());
		for (int i = 0; i < (int) lazy.size(); ++i)
			mp[lazy[i]] = i;
		lazy.clear();
	}
	int getId(int x) const {
		assert(lazy.empty());
		return mp.at(x);
	}
	int size() const {
		assert(lazy.empty());
		return mp.size();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));

	vector<IdGen> rows(n);
	vector<IdGen> cols(m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
			rows[i].insert(grid[i][j]);
			cols[j].insert(grid[i][j]);
		}

	for (auto &&x : rows)
		x.process();
	for (auto &&x : cols)
		x.process();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			const int rank1 = rows[i].getId(grid[i][j]);
			const int rank2 = cols[j].getId(grid[i][j]);
			const int id = max(rank1, rank2) + 1;
			const int res = id + max(rows[i].size() - 1 - rank1, cols[j].size() - 1 - rank2);
			cout << res << ' ';
		}
		cout << '\n';
	}

	return 0;
}