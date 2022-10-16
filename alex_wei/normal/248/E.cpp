#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, K = 100 + 5;
int n, q, a[N], fc[K];
double ans, f[N][K];
int main() {
	cin >> n;
	for(int i = fc[0] = 1; i <= 5; i++) fc[i] = fc[i - 1] * i;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i][a[i]] = 1, ans += !a[i];
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int u, v, k;
		scanf("%d %d %d", &u, &v, &k);
		static double g[K];
		memset(g, 0, sizeof(g)), ans -= f[u][0];
		for(int j = 0; j <= 100; j++) if(f[u][j])
			for(int p = 0; p <= k; p++) {
				if(j < p || a[u] - j < k - p) continue;
				double coef = 1;
				for(int q = 0; q < p; q++) coef = coef * (j - q) / (a[u] - q);
				for(int q = 0; q < k - p; q++) coef = coef * (a[u] - j - q) / (a[u] - p - q);
				g[j - p] += f[u][j] * coef * fc[k] / fc[k - p] / fc[p];
			}
		memcpy(f[u], g, sizeof(g));
		ans += f[u][0], a[u] -= k, a[v] += k;
		printf("%.9lf\n", ans);
	}
    return 0;
}