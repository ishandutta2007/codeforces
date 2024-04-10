#include <bits/stdc++.h>

struct event {
	int v, t, x, id;

	event(int _v, int _t, int _x, int _id) : v(_v), t(_t), x(_x), id(_id) {}

	bool operator<(const event &rhs) const {
		return t < rhs.t || (t == rhs.t && id < rhs.id);
	}
};

class BIT {
	int n;
	std::vector<int> c;

public:
	BIT(int _n) : n(_n), c(n + 1) {}

	void add(int x, int v) {
		for (++x; x <= n; x += x & -x) {
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
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n), s(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	std::vector<int> c(m), d(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> c[i];
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> d[i];
	}

	std::vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		v1.push_back(b[i] + p[i]);
		v2.push_back(b[i] - p[i]);
	}
	std::sort(v1.begin(), v1.end());
	v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
	std::sort(v2.begin(), v2.end());
	v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

	std::vector<event> Q1, Q2;
	for (int i = 0; i < n; ++i) {
		int x1 = std::lower_bound(v1.begin(), v1.end(), b[i] + p[i]) - v1.begin();
		Q1.emplace_back(1, p[i], x1, -1);
		Q1.emplace_back(-1, s[i] + 1, x1, -1);
		int x2 = std::lower_bound(v2.begin(), v2.end(), b[i] - p[i]) - v2.begin();
		Q2.emplace_back(1, p[i], x2, -1);
		Q2.emplace_back(-1, s[i] + 1, x2, -1);
	}
	for (int i = 0; i < m; ++i) {
		int x1 = std::upper_bound(v1.begin(), v1.end(), d[i] + c[i]) - v1.begin();
		Q1.emplace_back(1, c[i], x1, i);
		int x2 = std::lower_bound(v2.begin(), v2.end(), d[i] - c[i]) - v2.begin();
		Q2.emplace_back(-1, c[i], x2, i);
	}
	std::sort(Q1.begin(), Q1.end());
	std::sort(Q2.begin(), Q2.end());

	std::vector<int> ans(m);
	BIT T1(v1.size());
	for (auto r : Q1) {
		if (r.id == -1) {
			T1.add(r.x, r.v);
		} else {
			ans[r.id] += T1.query(r.x) * r.v;
		}
	}
	BIT T2(v2.size());
	for (auto r : Q2) {
		if (r.id == -1) {
			T2.add(r.x, r.v);
		} else {
			ans[r.id] += T2.query(r.x) * r.v;
		}
	}
	for (int i = 0; i < m; ++i) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}