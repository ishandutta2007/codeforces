#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	int n;
	std::vector<int> val;
	std::vector<int> tag;

	void build(int u, int l, int r, const std::vector<int> &a) {
		if (l + 1 == r) {
			val[u] = a[l];
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid, a);
		build(u << 1 | 1, mid, r, a);
		val[u] = std::max(val[u << 1], val[u << 1 | 1]);
	}

	void add(int u, int v) {
		val[u] += v;
		tag[u] += v;
	}

	void down(int u) {
		if (tag[u]) {
			add(u << 1, tag[u]);
			add(u << 1 | 1, tag[u]);
			tag[u] = 0;
		}
	}

	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			add(u, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (L < mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid, r, L, R, v);
		}
		val[u] = std::max(val[u << 1], val[u << 1 | 1]);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return val[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::max(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	segment_tree(const std::vector<int> &a) : n(a.size()), val(enlarge(n) << 1), tag(enlarge(n) << 1) {
		build(1, 0, n, a);
	}

	void modify(int l, int r, int v) {
		modify(1, 0, n, l, r, v);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}

	std::vector<int> ls(n), rs(n);
	std::vector<int> sta;
	sta.push_back(-1);
	for (int i = 0; i < n; ++i) {
		while ((int)sta.size() > 1 && a[sta.back()] < a[i]) {
			sta.pop_back();
		}
		ls[i] = sta.back();
		sta.push_back(i);
	}
	sta.clear();
	sta.push_back(n);
	for (int i = n - 1; i >= 0; --i) {
		while ((int)sta.size() > 1 && a[sta.back()] <= a[i]) {
			sta.pop_back();
		}
		rs[i] = sta.back();
		sta.push_back(i);
	}

	std::vector<int> len(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		len[i] = len[rs[i]] + 1;
	}
	segment_tree T(len);
	std::vector<int> ans(n - m + 1);
	for (int i = n - 1; i >= m - 1; --i) {
		ans[i - m + 1] = T.query(i - m + 1, i + 1);
		T.modify(ls[i] + 1, i + 1, -1);
	}
	for (int v : ans) {
		std::cout << v << " ";
	}
	std::cout << "\n";
}