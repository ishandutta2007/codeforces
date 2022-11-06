#include <bits/stdc++.h>
const int N = 25;
int T, n, m, a[N][N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n + 1; i++)
			std::fill(a[i], a[i] + m + 2, 0);
		int i = 1, j = 1; a[i][j] = 1;
		std::vector<std::pair<int, int>> vec;
		for (int i = 1; i < m; i++) vec.push_back({1, i});
		for (int i = 1; i < n; i++) vec.push_back({i, m});
		for (int i = m; i > 1; i--) vec.push_back({n, i});
		for (int i = n; i > 1; i--) vec.push_back({i, 1});
		for (auto tmp : vec) {
			int x = tmp.first, y = tmp.second, ok = 1;
			for (int dx = -1; dx <= 1; dx++)
				for (int dy = -1; dy <= 1; dy++)
					if (a[x + dx][y + dy]) { ok = 0; break; }
			if (ok) a[x][y] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				printf("%d", a[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}