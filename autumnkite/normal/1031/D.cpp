#include <bits/stdc++.h>

const int N = 2005;

int n, k;
char a[N][N];
char ans[N * 2];

struct State {
	int x, y;
	int cnt;
};

int mn[N][N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<State> pos;
	if (a[0][0] == 'a' || k == 0) {
		pos.push_back({0, 0, 0});
		mn[0][0] = 0;
		ans[0] = a[0][0];
	} else {
		pos.push_back({0, 0, 1});
		mn[0][0] = 1;
		ans[0] = 'a';
	}
	for (int i = 1; i < 2 * n - 1; ++i) {
		for (int x = std::max(i - n + 1, 0); x <= i && x < n; ++x) {
			mn[x][i - x] = k + 1;
		}
		for (State v : pos) {
			// std::cerr << "(" << v.x << "," << v.y << "," << v.cnt << ") ";
			if (v.x + 1 < n) {
				mn[v.x + 1][v.y] = std::min(mn[v.x + 1][v.y], v.cnt);
			}
			if (v.y + 1 < n) {
				mn[v.x][v.y + 1] = std::min(mn[v.x][v.y + 1], v.cnt);
			}
		}
		// std::cerr << "\n";
		pos.clear();
		ans[i] = 'z';
		for (int x = std::max(i - n + 1, 0); x <= i && x < n; ++x) {
			if (mn[x][i - x] == k + 1) {
				continue;
			}
			if (mn[x][i - x] == k) {
				ans[i] = std::min(ans[i], a[x][i - x]);
			} else {
				ans[i] = 'a';
				break;
			}
		}
		for (int x = std::max(i - n + 1, 0); x <= i && x < n; ++x) {
			if (mn[x][i - x] == k + 1) {
				continue;
			}
			if (a[x][i - x] == 'a' || mn[x][i - x] == k) {
				if (a[x][i - x] == ans[i]) {
					pos.push_back({x, i - x, mn[x][i - x]});
				}
			} else {
				pos.push_back({x, i - x, mn[x][i - x] + 1});
			}
		}
	}
	for (int i = 0; i < 2 * n - 1; ++i) {
		std::cout << ans[i];
	}
	std::cout << "\n";
}