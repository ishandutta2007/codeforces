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
#include <array>

using namespace std;

struct ST {
	struct Val { // define
		char v[100];
		Val() {
			for (int i = 0; i < 100; ++i)
				v[i] = i;
		}
		Val(const Val &v1, const Val &v2) {
			for (int i = 0; i < 100; ++i)
				v[i] = v2.v[v1.v[i]];
		}
	};

	int n;
	int stOffset;
	int stHi;
	vector<Val> st;

	ST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		stHi = st.size() - 1 - stOffset;
	}

	Val query(const int i, const int j, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j)
			return st[si];
		int mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return Val(query(i, j, si << 1, lo, mid),
			query(i, j, si << 1 | 1, mid + 1, hi));
	}

	Val query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : Val();
	}

	void update(const int i, const int x, const int y) {
		int si = stOffset + i;
		st[si].v[x] = y;
		for (si >>= 1; si; si >>= 1)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	int q;
	cin >> q;


	vector<vector<array<int, 3>>> lazy(n + 1);

	for (int i = 0; i < q; ++i) {
		static int l, r, x, y;
		cin >> l >> r >> x >> y;
		if (l == r) continue;
		--l, --r, --x, --y;
		lazy[l].push_back({ i, x, y });
		lazy[r + 1].push_back({ i, x, x });
	}

	ST st(q);

	for (int i = 0; i < n; ++i) {
		for (auto &&x : lazy[i])
			st.update(x[0], x[1], x[2]);
		if (i) cout << ' ';
		cout << (st.st[1].v[a[i]] + 1);
	}
	return 0;
}