#include <bits/stdc++.h>

std::vector<std::pair<int, int>> init(std::vector<int> a) {
	int n = a.size();
	std::vector<int> c(n, 1000000000);
	std::vector<std::pair<int, int>> sta;
	sta.emplace_back(0, 0);
	for (int i = 0; i < n; ++i) {
		sta.back().second = std::max(sta.back().second, a[i]);
		while ((int)sta.size() > 1 && sta.back().first >= a[i]) {
			int v = sta.back().second;
			sta.pop_back();
			sta.back().second = std::max(sta.back().second, v);
		}
		if (sta.back().first) {
			c[i] = std::min(c[i], sta.back().second);
		}
		sta.emplace_back(a[i], 0);
	}
	sta.clear();
	sta.emplace_back(0, 0);
	for (int i = n - 1; i >= 0; --i) {
		sta.back().second = std::max(sta.back().second, a[i]);
		while ((int)sta.size() > 1 && sta.back().first > a[i]) {
			int v = sta.back().second;
			sta.pop_back();
			sta.back().second = std::max(sta.back().second, v);
		}
		if (sta.back().first) {
			c[i] = std::min(c[i], sta.back().second);
		}
		sta.emplace_back(a[i], 0);
	}
	std::vector<std::pair<int, int>> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = std::make_pair(c[i] - a[i], a[i]);
	}
	return res;
}

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

	int query(int l, int r) {
		l = std::max(l, 0);
		r = std::min(r, n);
		if (l >= r) {
			return 0;
		}
		return query(r) - query(l);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, x;
	std::cin >> n >> m >> x;
	int mx = x;
	std::vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
		mx = std::max(mx, b[i]);
	}
	auto c = init(a), d = init(b);
	std::sort(c.begin(), c.end());
	std::sort(d.begin(), d.end());
	std::reverse(c.begin(), c.end());
	std::reverse(d.begin(), d.end());
	BIT Ta(mx), Tb(mx);
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < m && d[j].first >= c[i].first) {
			Tb.add(d[j].second - 1, 1);
			++j;
		}
		ans += Tb.query(x - c[i].first - c[i].second, x - c[i].second);
	}
	for (int i = 0, j = 0; i < m; ++i) {
		while (j < n && c[j].first > d[i].first) {
			Ta.add(c[j].second - 1, 1);
			++j;
		}
		ans += Ta.query(x - d[i].first - d[i].second, x - d[i].second);
	}
	std::cout << ans << "\n";
}