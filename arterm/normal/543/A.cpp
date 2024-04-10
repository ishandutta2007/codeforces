#include <bits/stdc++.h>

using namespace std;

const int M = 507;

int n, m, mod, b, v;
int d[M][M], a[M];

void read() {
	cin >> n >> m >> b >> mod;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}

void add(int a) {
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= b; ++j)
			if (j >= a && i >= 1) {
				d[i][j] += d[i - 1][j - a];
				if (d[i][j] >= mod)
					d[i][j] -= mod;
			}
}

void kill() {
	d[0][0] = 1 % mod;
	for (int i = 0; i < n; ++i)
		add(a[i]);
	int ans = 0;
	for (int j = 0; j <= b; ++j)
		ans = (ans + d[m][j]) % mod;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	kill();
	return 0;
}