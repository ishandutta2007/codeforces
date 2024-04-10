#include <bits/stdc++.h>
using namespace std;

#define edge(x, y, xx, yy) __gcd(abs(x - xx), abs(y - yy))

int x[6006], y[6006];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i] /= 2;
		y[i] /= 2;
		x[i] %= 2;
		y[i] %= 2;
	}
	int cnt[2][2] = {{0, 0}, {0, 0}};
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int u = 0; u < 2; u++) {
				for (int v = 0; v < 2; v++) {
					int border = edge(x[i], y[i], x[j], y[j]);
					border += edge(x[j], y[j], u, v);
					border += edge(u, v, x[i], y[i]);
					if (border % 2 == 0) {
						res += cnt[u][v];
					}
				}
			}
		}
		cnt[x[i] % 2][y[i] % 2]++;
	}
	cout << res << '\n';

	return 0;
}