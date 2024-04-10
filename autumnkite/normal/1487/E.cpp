#include <bits/stdc++.h>

const int N = 150005, INF = 0x3f3f3f3f;

int n[4];
int a[4][N];
int f[4][N];

std::vector<int> E[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for (int k = 0; k < 4; ++k) {
		std::cin >> n[k];
	}
	for (int k = 0; k < 4; ++k) {
		for (int i = 1; i <= n[k]; ++i) {
			std::cin >> a[k][i];
		}
	}
	for (int i = 1; i <= n[0]; ++i) {
		f[0][i] = a[0][i];
	}
	for (int k = 1; k < 4; ++k) {
		int m;
		std::cin >> m;
		for (int i = 1; i <= n[k]; ++i) {
			E[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int x, y;
			std::cin >> x >> y;
			E[y].push_back(x);
		}
		std::multiset<int> S;
		for (int i = 1; i <= n[k - 1]; ++i) {
			S.insert(f[k - 1][i]);
		}
		for (int i = 1; i <= n[k]; ++i) {
			for (int j : E[i]) {
				S.erase(S.find(f[k - 1][j]));
			}
			if (S.empty() || *S.begin() == INF) {
				f[k][i] = INF;
			} else {
				f[k][i] = *S.begin() + a[k][i];
			}
			for (int j : E[i]) {
				S.insert(f[k - 1][j]);
			}
		}
	}
	int ans = *std::min_element(f[3] + 1, f[3] + n[3] + 1);
	std::cout << (ans == INF ? -1 : ans) << "\n";
}