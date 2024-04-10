#include <bits/stdc++.h>

const int N = 55, P = 1000000007;

int n, m, lim;
bool ex[N][N];
std::vector<int> a[N][N];

int f[2 * N][2][N];
std::vector<int> trans[2][2][N][N];

bool extend_front(std::deque<int> &Q, std::deque<int>::iterator it) {
	while (it != Q.begin() && (int)Q.size() <= lim) {
		auto nit = it - 1;
		if (!ex[*nit][*it] || (int)(Q.size() + a[*nit][*it].size()) > lim) {
			return false;
		}
		Q.insert(Q.begin(), a[*nit][*it].begin(), a[*nit][*it].end());
		it = nit;
	}
	return (int)Q.size() <= lim;
}

bool extend_back(std::deque<int> &Q, std::deque<int>::iterator it) {
	while (it + 1 != Q.end() && (int)Q.size() <= lim) {
		auto nit = it + 1;
		if (!ex[*it][*nit] || (int)(Q.size() + a[*it][*nit].size()) > lim) {
			return false;
		}
		Q.insert(Q.end(), a[*it][*nit].begin(), a[*it][*nit].end());
		it = nit;
	}
	return (int)Q.size() <= lim;
}

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ex[i][j] && !a[i][j].empty() && a[i][j].back() == i) {
				std::deque<int> Q(a[i][j].begin(), a[i][j].end());
				if (extend_front(Q, --Q.end())) {
					trans[0][0][Q.front()][j].push_back(Q.size());
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ex[i][j] && !a[i][j].empty() && a[i][j].front() == j) {
				std::deque<int> Q(a[i][j].begin(), a[i][j].end());
				if (extend_back(Q, Q.begin())) {
					trans[1][1][i][Q.back()].push_back(Q.size());
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ex[i][j] && !a[i][j].empty()) {
				std::deque<int> Q(a[i][j].begin(), a[i][j].end());
				auto p = std::find(Q.begin(), Q.end(), i);
				if (p != Q.end() && (p + 1) != Q.end() && *(p + 1) == j) {
					if (extend_front(Q, p) && extend_back(Q, p + 1)) {
						trans[0][1][Q.front()][Q.back()].push_back(Q.size() - 1);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ex[i][j] && a[i][j].empty()) {
				trans[1][0][i][j].push_back(1);
			}
		}
	}
}

void inc(int &a, int b) {
	a + b >= P ? a += b - P : a += b;
}

void DP() {
	for (int i = 1; i <= n; ++i) {
		f[0][0][i] = 1;
	}
	for (int len = 0; len < 2 * n; ++len) {
		for (int p = 0; p < 2; ++p) {
			for (int i = 1; i <= n; ++i) {
				if (f[len][p][i]) {
					for (int q = 0; q < 2; ++q) {
						for (int j = 1; j <= n; ++j) {
							for (int t : trans[p][q][i][j]) {
								if (len + t <= 2 * n) {
									inc(f[len + t][q][j], f[len][p][i]);
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	lim = 2 * n + 1;
	for (int i = 1; i <= m; ++i) {
		int u, v, k;
		std::cin >> u >> v >> k;
		ex[u][v] = true;
		a[u][v].resize(k);
		for (int &id : a[u][v]) {
			std::cin >> id;
		}
	}

	init();
	DP();

	for (int len = 1; len <= 2 * n; ++len) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			inc(ans, f[len][1][i]);
		}
		std::cout << ans << "\n";
	}
}