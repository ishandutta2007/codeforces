#include <bits/stdc++.h>

const int C = 62;
const int prime[C] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
	53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 
	109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 
	173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
	233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293
};

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

struct state {
	unsigned long long S;

	state(unsigned long long _S) : S(_S) {}
	state() : state(0ull) {}

	state operator+(const state &rhs) const {
		return S | rhs.S;
	}

	state operator*(int b) const {
		return S;
	}
};

struct modint {
	static const int P = 1000000007;

	int x;

	modint(int _x) : x(_x) {}
	modint() : modint(1) {}

	modint operator+(const modint &rhs) const {
		return 1ll * x * rhs.x % P;
	}

	modint operator*(int b) const {
		if (x == 1) {
			return x;
		}
		int s = 1;
		for (int a = x; b; b >>= 1) {
			if (b & 1) {
				s = 1ll * s * a % P;
			}
			a = 1ll * a * a % P;
		}
		return s;
	}
};

template<typename Value>
class segment_tree {
	int n;
	std::vector<Value> a, tag;

	void apply(int u, int l, int r, Value v) {
		a[u] = a[u] + v * (r - l);
		tag[u] = tag[u] + v;
	}

	void down(int u, int l, int mid, int r) {
		apply(u << 1, l, mid, tag[u]);
		apply(u << 1 | 1, mid, r, tag[u]);
		tag[u] = Value();
	}

	void modify(int u, int l, int r, int L, int R, Value v) {
		if (L <= l && r <= R) {
			apply(u, l, r, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u, l, mid, r);
		if (L < mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (mid < R) {
			modify(u << 1 | 1, mid, r, L, R, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	Value query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u, l, mid, r);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return query(u << 1, l, mid, L, R) + query(u << 1 | 1, mid, r, L, R);
		}
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1), tag(enlarge(n) << 1) {}

	void modify(int l, int r, Value v) {
		modify(1, 0, n, l, r, v);
	}

	Value query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;

	auto get_pf = [&](int x) {
		unsigned long long res = 0;
		for (int i = 0; i < C; ++i) {
			if (x % prime[i] == 0) {
				res |= 1ull << i;
			}
		}
		return res;
	};

	segment_tree<modint> S(n);
	segment_tree<state> T(n);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		S.modify(i, i + 1, v);
		T.modify(i, i + 1, get_pf(v));
	}
	while (q--) {
		std::string op;
		std::cin >> op;
		if (op == "MULTIPLY") {
			int l, r, v;
			std::cin >> l >> r >> v;
			--l;
			S.modify(l, r, v);
			T.modify(l, r, get_pf(v));
		} else {
			int l, r;
			std::cin >> l >> r;
			--l;
			modint mul = S.query(l, r);
			state mask = T.query(l, r);
			for (int i = 0; i < C; ++i) {
				if (mask.S >> i & 1) {
					mul = mul + modint(prime[i] - 1);
					mul = mul + modint(prime[i]) * (modint::P - 2);
				}
			}
			std::cout << mul.x << "\n";
		}
	}
}