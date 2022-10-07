#include <bits/stdc++.h>

const int N = 100005, M = 300005;

int n, q;

struct Point {
	int x, y;

	bool operator < (const Point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}

	bool operator == (const Point &rhs) const {
		return x == rhs.x && y == rhs.y;
	}
};

int m;
Point vc[M], all[M];
int pos[N];
int a[M], lst[M], pre[M];

struct BIT {
	int c[M];

	void add(int x, int v) {
		for (; x <= m; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T;

std::vector<std::pair<int, int>> Q[M];
int ans[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int k;
		std::cin >> k;
		std::vector<Point> p(k);
		for (int j = 0; j < k; ++j) {
			std::cin >> p[j].x >> p[j].y;
		}
		for (int j = 0; j < k; ++j) {
			int x = p[(j + 1) % k].x - p[j].x, y = p[(j + 1) % k].y - p[j].y;
			int g = abs(std::__gcd(x, y));
			vc[++m] = (Point){x / g, y / g};
		}
		pos[i] = m;
	}
	for (int i = 1; i <= m; ++i) {
		all[i] = vc[i];
	}
	std::sort(all + 1, all + 1 + m);
	int mv = std::unique(all + 1, all + 1 + m) - all - 1;
	for (int i = 1; i <= m; ++i) {
		a[i] = std::lower_bound(all + 1, all + 1 + mv, vc[i]) - all;
	}

	for (int i = 1; i <= m; ++i) {
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}

	std::cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		std::cin >> l >> r;
		Q[pos[r]].push_back({pos[l - 1] + 1, i});
	}

	for (int r = 1; r <= m; ++r) {
		T.add(pre[r] + 1, 1);
		for (auto p : Q[r]) {
			int l = p.first, id = p.second;
			ans[id] = T.query(l) - l + 1;
		}
	}
	for (int i = 1; i <= q; ++i) {
		std::cout << ans[i] << "\n";
	}
}