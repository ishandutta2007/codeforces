#include <bits/stdc++.h>

using namespace std;

template <class T> struct FenwickTree {
	std::vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.assign(n, 0);
	}

	void init(std::vector<T>& a) {
		n = (int)a.size();
		fwt.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) 
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	
	void add(int idx, T delta) {
		if (idx < 0 || idx >= n) {
			return;
		}
		for (; idx < n; idx = idx | (idx + 1)) 
			fwt[idx] += delta;
	}

	void range_update(int l, int r, T x) {
		add(l, x);
		add(r + 1, -x);
	}

	T point_query(int i) {
		return sum(i);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	FenwickTree<long long> fwt;
	fwt.init(n);
	vector<long long> lazy(n);
	set<array<int, 3>> colors;
	colors.insert({0, n - 1, 0});
	while (q--) {
		string s;
		cin >> s;
		if (s == "Color") {
			int l, r, c;
			cin >> l >> r >> c;
			--l, --r, --c;
			vector<array<int, 3>> add_back = {{l, r, c}};
			while (true) { // getting intervals that have left value that go after l or at
				auto it = colors.lower_bound({l, -1, -1});
				if (it == colors.end()) {
					break;
				}
				auto ival = *it;
				int nl = ival[0], nr = ival[1], nc = ival[2];
				if (l <= nl && nr <= r) {
					fwt.range_update(nl, nr, lazy[nc]);
				} else if (l <= nl && nl <= r) {
					fwt.range_update(nl, r, lazy[nc]);
					add_back.push_back({r + 1, nr, nc});
				} else {
					break;
				}
				colors.erase(ival);
			}
			while (true) { // getting intervals that have left value that go before l 
				auto it = colors.lower_bound({l, -1, -1});
				if (it == colors.begin()) {
					break;
				}
				auto ival = *prev(it);
				int nl = ival[0], nr = ival[1], nc = ival[2];
				if (nl < l && r <= nr) {
					fwt.range_update(l, r, lazy[nc]);
					add_back.push_back({nl, l - 1, nc});
					add_back.push_back({r + 1, nr, nc});
				} else if (nl < l && nr < r && l <= nr) {
					fwt.range_update(l, nr, lazy[nc]);
					add_back.push_back({nl, l - 1, nc});
				} else {
					break;
				}
				colors.erase(ival);
			}
			for (auto [x, y, z] : add_back) {
				if (x <= y) {
					colors.insert({x, y, z});
				}
			}
			fwt.range_update(l, r, -lazy[c]);
		} else if (s == "Add") {
			int c, x;
			cin >> c >> x;
			--c;
			lazy[c] += x;
		} else {
			int i;
			cin >> i;
			--i;
			long long ans = fwt.point_query(i);
			int color = (*prev(colors.upper_bound({i, n, n})))[2];
			ans += lazy[color];
			cout << ans << '\n';
		}
	}
	return 0;
}