#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> lst(n, -1);
	std::vector<int> pre(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	std::vector<int> pre_mx(n + 1);
	pre_mx[0] = -1;
	for (int i = 0; i < n; ++i) {
		pre_mx[i + 1] = std::max(pre_mx[i], pre[i]);
	}

	std::vector<int> l(n), r(n);
	std::vector<int> sta;
	sta.push_back(-1);
	for (int i = 0; i < n; ++i) {
		while ((int)sta.size() > 1 && a[sta.back()] <= a[i]) {
			sta.pop_back();
		}
		l[i] = sta.back();
		sta.push_back(i);
	}
	sta.clear();
	sta.push_back(n);
	for (int i = n - 1; i >= 0; --i) {
		while ((int)sta.size() > 1 && a[sta.back()] <= a[i]) {
			sta.pop_back();
		}
		r[i] = sta.back();
		sta.push_back(i);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int len = a[i] + 1;
		l[i] = std::max(l[i], i - len);
		r[i] = std::min(r[i], i + len);
		if (i - l[i] < r[i] - i) {
			for (int p = l[i] + 1; p <= i && p + len <= n; ++p) {
				if (p + len <= r[i] && pre_mx[p + len] < p) {
					++ans;
				}
			}
		} else {
			for (int p = i + 1; p <= r[i]; ++p) {
				if (p - len > l[i] && pre_mx[p] < p - len) {
					++ans;
				}
			}
		}
	}
	std::cout << ans << "\n";
}