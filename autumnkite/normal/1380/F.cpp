#include <bits/stdc++.h>

const int P = 998244353;

typedef std::array<std::array<int, 2>, 2> matrix;

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

matrix operator*(const matrix &A, const matrix &B) {
	return {
		(int)((1ll * A[0][0] * B[0][0] + 1ll * A[0][1] * B[1][0]) % P),
		(int)((1ll * A[0][0] * B[0][1] + 1ll * A[0][1] * B[1][1]) % P),
		(int)((1ll * A[1][0] * B[0][0] + 1ll * A[1][1] * B[1][0]) % P),
		(int)((1ll * A[1][0] * B[0][1] + 1ll * A[1][1] * B[1][1]) % P)
	};
}

class segment_tree {
	int n;
	std::vector<matrix> a;

	static matrix get(char c) {
		return {c - '0' + 1, c == '1', '9' - c, 0};
	}

	void build(int u, int l, int r, const std::string &s) {
		if (l + 1 == r) {
			a[u] = get(s[l]);
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid, s);
		build(u << 1 | 1, mid, r, s);
		a[u] = a[u << 1] * a[u << 1 | 1];
	}

	void modify(int u, int l, int r, int x, char c) {
		if (l + 1 == r) {
			a[u] = get(c);
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, c);
		} else {
			modify(u << 1 | 1, mid, r, x, c);
		}
		a[u] = a[u << 1] * a[u << 1 | 1];
	}

public:
	segment_tree(const std::string &s) : n(s.size()), a(enlarge(n) << 1) {
		build(1, 0, n, s);
	}

	void modify(int x, char c) {
		modify(1, 0, n, x, c);
	}

	int get_ans() {
		return a[1][0][0];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	
	segment_tree T(s);
	while (q--) {
		int x;
		char c;
		std::cin >> x >> c;
		T.modify(--x, c);
		std::cout << T.get_ans() << "\n";
	}
}