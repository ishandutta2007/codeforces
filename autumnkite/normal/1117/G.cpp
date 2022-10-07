#include <bits/stdc++.h>

class binary_indexed_tree {
	int n;
	std::vector<int> c;
	std::vector<long long> ci;

public:
	binary_indexed_tree(int _n) : n(_n), c(n + 1), ci(n + 1) {}

	void add(int x) {
		int t = x;
		for (++x; x <= n; x += x & -x) {
			++c[x];
			ci[x] += t;
		}
	}

	std::pair<int, long long> query(int x) {
		int s = 0;
		long long si = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
			si += ci[x];
		}
		return std::make_pair(s, si);
	}
};

struct event {
	int x, v, id;

	event() {}
	event(int _x, int _v, int _id) : x(_x), v(_v), id(_id) {}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	std::vector<int> L(q), R(q);
	for (int i = 0; i < q; ++i) {
		std::cin >> L[i];
		--L[i];
	}
	for (int i = 0; i < q; ++i) {
		std::cin >> R[i];
		--R[i];
	}

	std::vector<int> l(n), r(n);
	std::vector<int> sta;
	sta.push_back(-1);
	for (int i = 0; i < n; ++i) {
		while ((int)sta.size() > 1 && a[sta.back()] <= a[i]) {
			sta.pop_back();
		}
		l[i] = sta.back() + 1;
		sta.push_back(i);
	}
	sta.clear();
	sta.push_back(n);
	for (int i = n - 1; i >= 0; --i) {
		while ((int)sta.size() > 1 && a[sta.back()] <= a[i]) {
			sta.pop_back();
		}
		r[i] = sta.back() - 1;
		sta.push_back(i);
	}

	std::vector<long long> ans(q);
	std::vector<std::vector<event>> Q1(n), Q2(n);
	for (int i = 0; i < q; ++i) {
		Q1[R[i]].emplace_back(L[i], -1, i);
		Q2[R[i]].emplace_back(R[i], 1, i);
		if (L[i]) {
			Q1[L[i] - 1].emplace_back(L[i], 1, i);
			Q2[L[i] - 1].emplace_back(R[i], -1, i);
		}
		ans[i] = R[i] - L[i] + 1;
	}
	binary_indexed_tree T1(n), T2(n);
	for (int i = 0; i < n; ++i) {
		T1.add(l[i]), T2.add(r[i]);
		for (auto e : Q1[i]) {
			auto t1 = T1.query(e.x), t2 = T1.query(n);
			ans[e.id] += e.v * (1ll * e.x * t1.first + t2.second - t1.second);
		}
		for (auto e : Q2[i]) {
			auto t1 = T2.query(e.x), t2 = T2.query(n);
			ans[e.id] += e.v * (1ll * e.x * (t2.first - t1.first) + t1.second);
		}
	}
	for (int i = 0; i < q; ++i) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}