#include <bits/stdc++.h>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int sx, sy, tx, ty;
	std::cin >> sx >> sy >> tx >> ty;
	--sx, --sy, --tx, --ty;

	auto bfs = [&]() {
		std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
		std::vector<std::pair<int, int>> Q;
		Q.emplace_back(sx, sy);
		vis[sx][sy] = true;
		for (int i = 0; i < (int)Q.size(); ++i) {
			int x = Q[i].first, y = Q[i].second;
			if (x == tx && y == ty) {
				return true;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k], ny = y + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '.' && !vis[nx][ny]) {
					Q.emplace_back(nx, ny);
					vis[nx][ny] = true;
				}
			}
		}
		return false;
	};

	if (a[tx][ty] == 'X' && (sx != tx || sy != ty)) {
		a[tx][ty] = '.';
		if (bfs()) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	} else {
		for (int k = 0; k < 4; ++k) {
			int nx = tx + dx[k], ny = ty + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == '.') {
				a[nx][ny] = 'X';
				if (bfs()) {
					std::cout << "YES\n";
					return 0;
				}
				a[nx][ny] = '.';
			}
		}
		std::cout << "NO\n";
	}
}