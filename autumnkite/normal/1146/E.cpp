#include <bits/stdc++.h>

class BIT {
	int n;
	std::vector<int> c;

public:
	BIT(int _n) : n(_n), c(n + 1) {}

	void add(int x) {
		for (++x; x; x ^= x & -x) {
			++c[x];
		}
	}

	int query(int x) {
		int s = 0;
		for (++x; x <= n; x += x & -x) {
			s += c[x];
		}
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	int m = 0;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		m = std::max(m, abs(a[i]));
	}
	std::vector<std::pair<int, int>> Q;
	for (int i = 0; i < q; ++i) {
		char c;
		std::cin >> c;
		int x;
		std::cin >> x;
		m = std::max(m, abs(x));
		Q.emplace_back(c == '>', x);
	}

	std::vector<int> pre1(m + 1, -1), pre2(m + 1, -1);
	for (int i = 0; i < q; ++i) {
		if (Q[i].second == 0) {
			pre1[0] = pre2[0] = i;
		} else if ((Q[i].second > 0) ^ Q[i].first) {
			pre1[abs(Q[i].second)] = i;
		} else {
			pre2[abs(Q[i].second)] = i;
		}
	}
	for (int i = 1; i <= m; ++i) {
		pre1[i] = std::max(pre1[i - 1], pre1[i]);
		pre2[i] = std::max(pre2[i - 1], pre2[i]);
	}

	std::vector<std::vector<int>> ev(q);
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			continue;
		}
		int t = std::max(pre1[abs(a[i])], pre2[abs(a[i]) - 1]);
		if (t != -1) {
			if (Q[t].first) {
				a[i] = -abs(a[i]);
			} else {
				a[i] = abs(a[i]);
			}
		}
		if (t + 1 < q) {
			ev[t + 1].push_back(i);
		}
	}

	BIT T0(m + 1), T1(m + 1);
	for (int i = q - 1; i >= 0; --i) {
		if (Q[i].first) {
			if (Q[i].second < 0) {
				T1.add(-Q[i].second);
			}
		} else {
			if (Q[i].second > 0) {
				T0.add(Q[i].second);
			}
		}
		for (int x : ev[i]) {
			int t = T0.query(abs(a[x]) + 1) + T1.query(abs(a[x]) + 1);
			if (t & 1) {
				a[x] = -a[x];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}