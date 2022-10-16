#include <bits/stdc++.h>

using namespace std;

template <int SZ> struct Sieve {
	int spf[SZ];
	
	Sieve() {
		spf[1] = 1;
		for (int i = 2; i < SZ; i++) 
			spf[i] = i;
		for (int i = 4; i < SZ; i += 2) 
			spf[i] = 2;
		for (int i = 3; i * i < SZ; i++) 
			if (spf[i] == i) 
				for (int j = i * i; j < SZ; j += i) 
					if (spf[j] == j) 
						spf[j] = i;
	}

	vector<pair<int, int>> factor(int x) {
		vector<pair<int, int>> ret;
		while (x != 1) {
			if ((int)ret.size() == 0) 
				ret.emplace_back(spf[x], 1);
			else {
				if (ret.back().first == spf[x]) 
					ret.back().second++;
				else 
					ret.emplace_back(spf[x], 1);
			}
			x /= spf[x];
		}
		return ret;
	}
};

struct DSU {
	vector<int> e;

	void init(int n) {
		e = vector<int>(n, -1);
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
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

const int N = 1e6 + 5;
const int B = 600;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Sieve<N> sieve;
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> head(N, -1);
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < n; ++i) {
		auto f = sieve.factor(a[i]);
		for (auto [p, e] : f) {
			if (head[p] == -1) {
				head[p] = i;
			} else {
				dsu.unite(head[p], i);
			}
		}
	}
	vector<vector<int>> in(n);
	for (int i = 0; i < n; ++i) {
		auto f1 = sieve.factor(a[i] + 1);
		auto f2 = sieve.factor(a[i]);
		reverse(f1.begin(), f1.end());
		reverse(f2.begin(), f2.end());
		vector<int> f;
		while (!f1.empty() || !f2.empty()) {
			if (f1.empty()) {
				f.push_back(f2.back().first);
				f2.pop_back(); 
			} else if (f2.empty()) {
				f.push_back(f1.back().first);
				f1.pop_back();
			} else {
				if (f1.back().first == f2.back().first) {
					f1.pop_back();
				} else if (f1.back().first < f2.back().first) {
					f.push_back(f1.back().first);
					f1.pop_back();
				} else {
					f.push_back(f2.back().first);
					f2.pop_back();
				}
			}
		}
		vector<int> join;
		for (int p : f) {
			if (head[p] == -1) {
				continue;
			}
			join.push_back(dsu.get(head[p]));
		}
		sort(join.begin(), join.end());
		join.resize(unique(join.begin(), join.end()) - join.begin());
		for (int x : join) {
			in[x].push_back(i);
		}
	}
	vector<int> ans(q, 2);
	vector<bool> big(n);
	vector<int> big_sets;
	for (int i = 0; i < n; ++i) {
		if (in[i].size() >= B) {
			big[i] = true;
			big_sets.push_back(i);
		} else {
			big[i] = false;
		}
	}
	vector<vector<int>> table(n);
	for (int i : big_sets) {
		for (int j : in[i]) {
			table[j].push_back(i);
		}
	}
	set<array<int, 2>> good_pairs;
	for (vector<int> v : table) {
		for (int i : v) {
			for (int j : v) {
				if (i < j) {
					good_pairs.insert({i, j});
				}
			}
		}
	}
	auto overlap = [&](int u, int v) {
		if (u > v) {
			swap(u, v);
		}
		if (big[u] && big[v]) {
			if (good_pairs.count({u, v})) {
				return true;
			} else {
				return false;
			}
		}
		if (in[u].size() > in[v].size()) {
			swap(u, v);
		}
		for (int x : in[u]) {
			if (binary_search(in[v].begin(), in[v].end(), x)) {
				return true;
			}
		}
		return false;
	};
	for (int qq = 0; qq < q; ++qq) {
		int s, t;
		cin >> s >> t;
		--s, --t;
		if (dsu.same_set(s, t)) {
			ans[qq] = 0;
		} else {
			int u = dsu.get(s);	
			int v = dsu.get(t);
			if (overlap(u, v)) {
				ans[qq] = 1;
			} else {
				ans[qq] = 2;
			}
		}
	}
	for (int qq = 0; qq < q; ++qq) {
		cout << ans[qq] << '\n';
	}
	return 0;
}