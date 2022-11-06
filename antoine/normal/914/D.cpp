#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

int gcd(int a, int b) {
	for (;;) {
		if (!b) return a;
		a %= b;
		if (!a) return b;
		b %= a;
	}
}

struct LazyST {
	struct Val {
		int g = 0;
		Val() {}
		Val(int v) : g(v) {}
		Val(const Val &v1, const Val &v2) {
			g = gcd(v1.g, v2.g);
		}
		operator int() {
			return g;
		}
	};

	int n;
	int stOffset;
	int stHi;
	vector<Val> st;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		stHi = st.size() - 1 - stOffset;
	}

	void build() { // O(n)
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			st[i + stOffset] = { x };
		}
		for (int si = stOffset - 1; si; --si)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}

	Val query(const int i, const int j, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return Val(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	bool query(const int l, const int r, const int x) {
		struct Node { int si, lo, hi; };
		vector<Node> nodes = { {1, 0, stHi} };
		Node node = { 0 };
		while (!nodes.empty()) {
			int si = nodes.back().si;
			int lo = nodes.back().lo;
			int hi = nodes.back().hi;
			nodes.pop_back();
			if (l <= lo && hi <= r) {
				if (st[si].g % x) {
					if (node.si)
						return false;
					node = { si, lo, hi };
				}
			}
			else {
				auto mid = (lo + hi) >> 1;
				if (r > mid)
					nodes.push_back({ si << 1 | 1, mid + 1, hi });
				if (l <= mid)
					nodes.push_back({ si << 1, lo, mid });
			}
		}
		if (!node.si)
			return true;
		int &si = node.si;
		int &lo = node.lo;
		int &hi = node.hi;
		while(lo != hi) {
			bool c1 = st[si << 1] % x;
			bool c2 = st[si << 1 | 1] % x;
			if (c1 && c2)
				return false;
			auto mid = (lo + hi) >> 1;
			si <<= 1;
			if (c1)
				hi = mid;
			else {
				si |= 1;
				lo = mid + 1;
			}
		}
		return true;
	}

	void update(const int i, const Val v) {
		int si = 1;
		int lo = 0;
		int hi = stHi;
		while (lo != hi) {
			int mid = (lo + hi) >> 1;
			si <<= 1;
			if (i <= mid)
				hi = mid;
			else {
				lo = mid + 1;
				si |= 1;
			}
		}
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n;
	LazyST st(n);
	st.build();
	cin >> q;
	while (q-- > 0) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			cout << (st.query(l - 1, r - 1, x) ? "YES" : "NO") << '\n';
		} else {
			int i, y;
			cin >> i >> y;
			st.update(i - 1, y);
		}
	}
	return 0;
}