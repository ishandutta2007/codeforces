#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	const int N = 999, M = 666;

	int X, Y;
	std::cin >> X >> Y;
	--X, --Y;
	std::vector<int> x(M), y(M);
	std::vector<std::vector<bool>> vis(N, std::vector<bool>(N));
	for (int i = 0; i < M; ++i) {
		std::cin >> x[i] >> y[i];
		--x[i], --y[i];
		vis[x[i]][y[i]] = true;
	}

	auto check = [&](int dx, int dy) {
		int nx = X + dx, ny = Y + dy;
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) {
			return false;
		} else {
			return true;
		}
	};

	auto move = [&](int dx, int dy) {
		X += dx, Y += dy;
		std::cout << X + 1 << " " << Y + 1 << std::endl;
		int k;
		std::cin >> k;
		--k;
		if (k < 0) {
			return true;
		}
		vis[x[k]][y[k]] = false;
		std::cin >> x[k] >> y[k];
		--x[k], --y[k];
		vis[x[k]][y[k]] = true;
		return false;
	};

	int mid = (N - 1) / 2;
	auto sgn = [&](int d) {
		return d < 0 ? -1 : (d > 0 ? 1 : 0);
	};
	while (X != mid || Y != mid) {
		int dx = sgn(mid - X), dy = sgn(mid - Y);
		if (check(dx, dy)) {
			if (move(dx, dy)) {
				return 0;
			}
		} else {
			if (move(dx, 0)) {
				return 0;
			}
		}
	}

	int dx = 0, dy = 0, ans = M + 1;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int Dx = i == 0 ? -1 : 1, Dy = j == 0 ? -1 : 1;
			int c = 0;
			for (int x = mid; 0 <= x && x < N; x += Dx) {
				for (int y = mid; 0 <= y && y < N; y += Dy) {
					c += vis[x][y];
				}
			}
			if (c < ans) {
				dx = -Dx, dy = -Dy, ans = c;
			}
		}
	}

	while (1) {
		if (check(dx, dy)) {
			if (move(dx, dy)) {
				return 0;
			}
		} else {
			if (move(dx, 0)) {
				return 0;
			}
		}
	}
}