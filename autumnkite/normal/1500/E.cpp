#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

struct State {
	int c;
	long long sum;
	long long sk;
	
	State() : c(0), sum(0), sk(0) {}
	State(long long v) : c(1), sum(v), sk(0) {}
};

State operator+(const State &A, const State &B) {
	State res;
	res.c = A.c + B.c;
	res.sum = A.sum + B.sum;
	res.sk = A.sk + B.sk + A.c * B.sum;
	return res;
}

class SegmentTree {
	int n;
	std::vector<State> a;
	
	void modify(int u, int l, int r, int x, long long v) {
		if (l + 1 == r) {
			a[u] = a[u].c ? State() : State(v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
	
	State query_pre(int u, int l, int r, int x) {
		if (l + 1 == r) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		if (x <= a[u << 1].c) {
			return query_pre(u << 1, l, mid, x);
		} else {
			return a[u << 1] + query_pre(u << 1 | 1, mid, r, x - a[u << 1].c);
		}
	}

	State query_suf(int u, int l, int r, int x) {
		if (l + 1 == r) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		if (x <= a[u << 1 | 1].c) {
			return query_suf(u << 1 | 1, mid, r, x);
		} else {
			return query_suf(u << 1, l, mid, x - a[u << 1 | 1].c) + a[u << 1 | 1];
		}
	}

public:
	SegmentTree(int _n) : n(_n), a(enlarge(n) << 1) {}
	
	void modify(int x, long long v) {
		return modify(1, 0, n, x, v);
	}
	
	State query_pre(int x) {
		if (x == 0) {
			return State();
		} else {
			return query_pre(1, 0, n, x);
		}
	}
	
	State query_suf(int x) {
		if (x == 0) {
			return State();
		} else {
			return query_suf(1, 0, n, x);
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<long long> val;
	std::vector<std::pair<long long, int>> Q;
	for (int i = 0; i < n; ++i) {
		long long v;
		std::cin >> v;
		val.push_back(v);
		Q.emplace_back(v, 1);
	}
	for (int i = 0; i < q; ++i) {
		int op;
		long long v;
		std::cin >> op >> v;
		val.push_back(v);
		Q.emplace_back(v, op == 1 ? 1 : -1);
	}
	std::sort(val.begin(), val.end());
	val.erase(std::unique(val.begin(), val.end()), val.end());

	SegmentTree T(val.size());
	int sz = 0;
	auto get_ans = [&]() {
		int l = 0, r = (sz - 1) / 2, len = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (T.query_pre(mid + 1).sum - T.query_suf(mid).sum > 0) {
				len = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		State L = T.query_pre(len + 1), R = T.query_suf(len);
		long long ans = (L.sum * (len + 1) - L.sk) - (R.sk + R.sum);
		ans *= 2;
		if (2 * len + 1 == sz) {
			ans -= L.sum - R.sum;
		}
		return T.query_pre(sz).sum - ans;
	};
	for (int i = 0; i < n + q; ++i) {
		int op = Q[i].second;
		int p = std::lower_bound(val.begin(), val.end(), Q[i].first) - val.begin();
		T.modify(p, val[p]);
		sz += op;
		if (i >= n - 1) {
			std::cout << get_ans() << "\n";
		}
	}
}