#include <bits/stdc++.h>

using namespace std;

int a[1000005], f[1000005][7][7], n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		a[u]++;
	}
	for (int i = 0; i < 1000005; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				f[i][j][k] = -1e9;
			}
		}
	}
	f[1][0][a[1] % 3] = a[1] / 3;
	if (a[1] >= 3 && a[1] % 3 != 2) {
		f[1][0][a[1] % 3 + 3] = a[1] / 3 - 1;
	}
	//cout << a[4] << endl;
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j <= 5; j++) {
			for (int k = 0; k <= min(5, a[i]); k++) {
				for (int l = j; l <= 5; l++) {
					for (int t = l - j; t <= 5; t++) {
						int x = t, y = l - j, z = a[i], res = f[i - 1][t][l];
						if (res < 0) {
							continue;
						}
						res += (z - k) / 3;
						z -= ((z - k) / 3) * 3;
						z -= k;
						if (z != y) {
							continue;
						}
						res += y;
						f[i][j][k] = max(f[i][j][k], res);
					}
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			maxi = max(maxi, f[m][i][j]);
		}
	}
	cout << maxi << endl;
	return 0;
}