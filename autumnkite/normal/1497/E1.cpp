#include <bits/stdc++.h>

const int N = 10000000;

bool vis[N + 1];
int cnt, prime[N];
int minp[N + 1];

void init() {
	cnt = 0;
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) {
			prime[cnt++] = i;
			minp[i] = 1;
		}
		for (int j = 0; j < cnt && i * prime[j] <= N; ++j) {
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				minp[i * prime[j]] = prime[j] * prime[j];
				break;
			} else {
				minp[i * prime[j]] = minp[i];
			}
		}
	}
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		while (minp[a[i]] > 1) {
			a[i] /= minp[a[i]];
		}
	}

	std::map<int, int> lst;
	std::vector<int> p(m + 1);
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, n));
	f[0] = std::vector<int>(m + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (lst.count(a[i])) {
			int t = lst[a[i]];
			for (int j = m; j >= 0; --j) {
				if (p[j] <= t) {
					if (j < m) {
						p[j + 1] = p[j];
					}
					p[j] = t + 1;
				}
			}
		}
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= j; ++k) {
				f[i + 1][j] = std::min(f[i + 1][j], f[p[k]][j - k] + 1);
			}
		}
		lst[a[i]] = i;
	}
	std::cout << f[n][m] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}