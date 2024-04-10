#include <bits/stdc++.h>

const int N = 55, INF = 0x3f3f3f3f;

int n, k;
char a[N];
int f[N][N];

void solve() {
	std::cin >> n >> k;
	std::cin >> (a + 1);
	std::sort(a + 1, a + 1 + n);
	int ans = INF;
	for (int i = 1; i <= n; ++i) {
		f[i][1] = a[i] - 'a' + 1;
		for (int j = 2; j <= k; ++j) {
			f[i][j] = INF;
			for (int p = 1; p < i; ++p) {
				if (a[p] < a[i] - 1) {
					f[i][j] = std::min(f[i][j], f[p][j - 1] + (a[i] - 'a' + 1));
				}
			}
		}
		ans = std::min(ans, f[i][k]);
	}
	std::cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T = 1;
//	std::cin >> T;
	while (T--) {
		solve();
	}
}