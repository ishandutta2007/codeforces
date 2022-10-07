#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}

	std::vector<bool> is_prime(mx + 1, true);
	std::vector<std::vector<int>> pf(mx + 1);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= mx; ++i) {
		if (is_prime[i]) {
			pf[i].push_back(i);
			for (int j = i + i; j <= mx; j += i) {
				pf[j].push_back(i);
				is_prime[j] = false;
			}
		}
	}

	int LG = 1;
	while ((1 << LG) < n) {
		++LG;
	}
	std::vector<int> lst(mx + 1, n);
	std::vector<std::vector<int>> go(LG, std::vector<int>(n + 1, n));
	for (int i = n - 1; i >= 0; --i) {
		go[0][i] = go[0][i + 1];
		for (int v : pf[a[i]]) {
			go[0][i] = std::min(go[0][i], lst[v]);
			lst[v] = i;
		}
	}
	for (int i = 1; i < LG; ++i) {
		for (int j = 0; j < n; ++j) {
			go[i][j] = go[i - 1][go[i - 1][j]];
		}
	}
	
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		--l;
		int ans = 0;
		for (int i = LG - 1; i >= 0; --i) {
			if (go[i][l] < r) {
				ans += 1 << i;
				l = go[i][l];
			}
		}
		std::cout << ans + 1 << "\n";
	}
}