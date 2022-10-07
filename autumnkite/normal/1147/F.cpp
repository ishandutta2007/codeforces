#include <bits/stdc++.h>

const int N = 2005;

int n;
int a[N][N];
int p[N][N];
int boy[N], girl[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cin >> a[i][j];
		}
	}

	std::cout << "B" << std::endl;
	char op;
	std::cin >> op;
	int x;
	std::cin >> x;
	if ((op == 'D') ^ (x > n)) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = n * n - a[i][j] + 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		boy[i] = 0;
		for (int j = 1; j <= n; ++j) {
			p[i][j] = j;
		}
		std::sort(p[i] + 1, p[i] + 1 + n, [&](int x, int y) {
			return a[i][x] < a[i][y];
		});
	}
	std::fill(girl + 1, girl + 1 + n, 0);

	std::vector<int> Q;
	for (int i = 1; i <= n; ++i) {
		Q.push_back(i);
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		while (1) {
			int v = p[u][++boy[u]];
			if (!girl[v] || a[u][v] > a[girl[v]][v]) {
				if (girl[v]) {
					Q.push_back(girl[v]);
				}
				girl[v] = u;
				break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		boy[girl[i]] = i;
	}

	while (x != -1 && x != -2) {
		if (x <= n) {
			std::cout << boy[x] + n << std::endl;
		} else {
			std::cout << girl[x - n] << std::endl;
		}
		std::cin >> x;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}