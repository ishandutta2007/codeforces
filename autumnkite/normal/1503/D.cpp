#include <bits/stdc++.h>

struct Node {
	int l, r;
	bool st;

	bool operator<(const Node &rhs) const {
		return r < rhs.r;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<Node> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].l >> a[i].r;
		if (a[i].l > a[i].r) {
			std::swap(a[i].l, a[i].r);
			a[i].st = true;
		} else {
			a[i].st = false;
		}
	}
	std::sort(a.begin(), a.end());

	std::vector<int> mn(n), mx(n);
	mn[0] = a[0].l;
	for (int i = 1; i < n; ++i) {
		mn[i] = std::min(mn[i - 1], a[i].l);
	}
	mx[n - 1] = a[n - 1].l;
	for (int i = n - 2; i >= 0; --i) {
		mx[i] = std::max(mx[i + 1], a[i].l);
	}

	if (mx[0] > a[0].r) {
		std::cout << -1 << "\n";
		return 0;
	}
	std::vector<int> p, q;
	for (int i = 0; i < n; ++i) {
		if (mn[i] == a[i].l) {
			p.push_back(i);
		} else if (mx[i] == a[i].l) {
			q.push_back(i);
		} else {
			std::cout << -1 << "\n";
			return 0;
		}
	}
	int i = 0, j = 0;
	int ans = 0;
	while (i < (int)p.size() || j < (int)q.size()) {
		int c[2] = {0, 0};
		if (i < (int)p.size()) {
			++c[a[p[i]].st];
			++i;
		} else {
			++c[a[q[j]].st ^ 1];
			++j;
		}
		while (i < (int)p.size() || j < (int)q.size()) {
			bool flag = false;
			if (i) {
				while (j < (int)q.size() && p[i - 1] < q[j] && a[p[i - 1]].r > a[q[j]].l && a[p[i - 1]].l < a[q[j]].l) {
					++c[a[q[j]].st ^ 1];
					++j;
					flag = true;
				}
			}
			if (j) {
				while (i < (int)p.size() && p[i] < q[j - 1] && a[p[i]].r > a[q[j - 1]].l && a[p[i]].l < a[q[j - 1]].l) {
					++c[a[p[i]].st];
					++i;
					flag = true;
				}
			}
			if (!flag) {
				break;
			}
		}
		ans += std::min(c[0], c[1]);
	}
	std::cout << ans << "\n";
}