#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

char c[N][N];
int h[N][N];
int f[N * 2], g[N * 2];


int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == c[i - 1][j]) {
				h[i][j] = h[i - 1][j];
			}
			h[i][j]++;
			if (c[i][j] != c[i - 1][j + 1]) {
				f[i + j] = -(i - 1);
			}
			if (c[i][j] != c[i - 1][j - 1]) {
				g[i - j + N] = -(i - 1);
			}
			f[i + j] = min(f[i + j], (h[i][j] + 1) / 2 - i);
			g[i - j + N] = min(g[i - j + N], (h[i][j] + 1) / 2 - i);
			ans += min(f[i + j], g[i - j + N]) + i;
			//cout << "73 " << f[i + j] << " " << g[i - j + N] << " " << i << endl;
		}
	}
	cout << ans;
	return 0;
}