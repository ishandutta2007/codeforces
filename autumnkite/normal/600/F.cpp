#include <bits/stdc++.h>

const int N = 1005, M = 100005;

int na, nb, m;
int x[M], y[M];
int ans, c[N << 1][N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> na >> nb >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> x[i] >> y[i];
		y[i] += na;
		int p = 1;
		while (c[x[i]][p]) {
			++p;
		}
		int q = 1;
		while (c[y[i]][q]) {
			++q;
		}
		ans = std::max(ans, std::max(p, q));
		c[x[i]][p] = y[i];
		c[y[i]][q] = x[i];
		if (p == q) {
			continue;
		}
		for (int w = q, u = y[i]; u; u = c[u][w], w ^= p ^ q) {
			std::swap(c[u][p], c[u][q]);
		}
	}

	std::cout << ans << "\n";
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= ans; ++j) {
			if (c[x[i]][j] == y[i]) {
				std::cout << j << " ";
				break;
			}
		}
	}
}