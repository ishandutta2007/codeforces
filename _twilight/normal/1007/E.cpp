#include <bits/stdc++.h>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 205;
const ll llf = 1ll << 60;

int n, t, k;
ll sa[N], sb[N];
ll a[N], b[N], c[N];
ll f[N][N][2], g[N][N][2];

int main() {
	scanf("%d%d%d", &n, &t, &k);
	for (int i = 1; i <= n; i++) {
		scanf(Auto""Auto""Auto, a + i, b + i, c + i);
	}
	++n;
	a[n] = llf, b[n] = 0, c[n] = llf;
	for (int i = 1; i <= n; i++) {
		sa[i] = sa[i - 1] + a[i];
		sb[i] = sb[i - 1] + b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			for (int z = 0; z < 2; z++) {
				f[i][j][z] = g[i][j][z] = llf;
				if (f[i - 1][j][z] < llf && a[i] * z + b[i] * j <= c[i]) {
					f[i][j][z] = f[i - 1][j][z];
					ll value = (sa[i - 1] * z + sb[i - 1] * j + k - 1) / k;
					if (value * k <= sa[i] * z + sb[i] * j) {
						g[i][j][z] = value;
					}
				}
				for (int r = 0; r < j; r++) {
					if (g[i][r][z] < llf) {
						ll rest = sa[i] * z + sb[i] * r - g[i][r][z] * k;
						ll value = (max(rest + (j - r) * b[i] - c[i], 0ll) + k - 1) / k;
						rest -= value * k;
						if (f[i - 1][j - r][0] < llf && rest >= 0) {
							f[i][j][z] = min(f[i][j][z], g[i][r][z] + value + f[i - 1][j - r][0]);
							ll x = (sb[i - 1] * (j - r) + k - 1) / k;
							if (x * k <= rest + (j - r) * sb[i]) {
								g[i][j][z] = min(g[i][j][z], g[i][r][z] + value + x);
							}
						}
					}
				}
//				cerr << i << " " << j << " " << z << " " << f[i][j][z] << " " << g[i][j][z] << '\n';
			}
		}
	}
	cout << f[n][t][1] << '\n';
	return 0;
}