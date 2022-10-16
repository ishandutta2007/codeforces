#include <bits/stdc++.h>

using namespace std;

struct DSU {
	std::vector<int> e;

	void init(int n) {
		e = std::vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	DSU dsu;
	dsu.init(n);
	vector<array<int, 2>> v(n);
	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> v[i][j];
			--v[i][j];
		}
		dsu.unite(v[i][0], v[i][1]);
		vector<int> comps;
		for (int i = 0; i < n; ++i) {
			comps.push_back(dsu.get(i));
		}
		sort(comps.begin(), comps.end());
		comps.erase(unique(comps.begin(), comps.end()), comps.end());
		vector<int> sizes;
		for (int c : comps) {
			sizes.push_back(dsu.size(c));
		}
		sort(sizes.begin(), sizes.end());
		int moves = i + 1;
		int use = n - moves;
		while ((int)sizes.size() > use) {
			int x = sizes.back();
			sizes.pop_back();
			sizes.back() += x;
		}
		cout << sizes.back() - 1 << '\n';
	}
	return 0;
}