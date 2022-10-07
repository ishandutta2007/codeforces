#include <bits/stdc++.h>

const int N = 300005, LG = 19;

int n, d[N];

int Log[N];

struct Node {
	int l, r;
} a[N][LG];

struct ST {
	int st[N][LG];
	std::function<int(int, int)> val;

	template<typename func>
	ST(func _val) {
		val = _val;
	}

	void init() {
		for (int i = 1; i <= 3 * n; ++i) {
			st[i][0] = i;
		}
		for (int j = 1; j < LG; ++j) {
			for (int i = 1; i <= 3 * n - (1 << j) + 1; ++i) {
				st[i][j] = val(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int query(int l, int r) {
		int t = Log[r - l + 1];
		return val(st[l][t], st[r - (1 << t) + 1][t]);
	}
};

ST L(
	[](int x, int y) {
		return a[x][0].l < a[y][0].l ? x : y;
	}
), R(
	[](int x, int y) {
		return a[x][0].r > a[y][0].r ? x : y;
	}
);

Node trans(const Node &now, int k) {
	Node res;
	int pl = L.query(now.l, now.r);
	int pr = R.query(now.l, now.r);
	res.l = std::min(a[pl][k].l, a[pr][k].l);
	res.r = std::max(a[pl][k].r, a[pr][k].r);
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = n + 1; i <= 2 * n; ++i) {
		std::cin >> d[i];
		d[i - n] = d[i + n] = d[i];
	}

	if (n == 1) {
		std::cout << 0 << "\n";
		return 0;
	}

	Log[1] = 0;
	for (int i = 2; i <= 3 * n; ++i) {
		Log[i] = Log[i >> 1] + 1;
	}

	for (int i = 1; i <= 3 * n; ++i) {
		a[i][0].l = std::max(1, i - d[i]);
		a[i][0].r = std::min(3 * n, i + d[i]);
	}

	L.init(), R.init();

	for (int j = 1; j < LG; ++j) {
		for (int i = 1; i <= 3 * n; ++i) {
			a[i][j] = trans(a[i][j - 1], j - 1);
		}
	}

	for (int i = n + 1; i <= 2 * n; ++i) {
		Node now;
		now.l = now.r = i;
		int ans = 0;
		for (int j = LG - 1; ~j; --j) {
			Node tr = trans(now, j);
			if (tr.r - tr.l + 1 < n) {
				now = tr;
				ans += 1 << j;
			}
		}
		std::cout << ans + 1 << " ";
	}
	std::cout << "\n";
}