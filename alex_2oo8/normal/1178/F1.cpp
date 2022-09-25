#include <bits/stdc++.h>

using namespace std;

const int MX = 1000, md = 998244353;
const long long md2 = md * 1ll * md;

int L[MX], R[MX], a[MX], dp[MX][MX], g[MX][MX], mn[MX][MX], f[MX], k;

int calc_dp(int l, int r);

int calc_f(int v) {
	if (f[v] == -1) {
		int res = 1;
		for (int i = 0, p = -1; i < k; i++) {
			if (a[i] == v) {
				if (p != -1) {
					res = res * 1ll * calc_dp(p + 1, i - 1) % md;
				}
				
				p = i;
			}
		}
		
		f[v] = res;
	}
	
	return f[v];
}

int calc_g(int l, int r) {
	if (l > r) return 1;
	
	if (g[l][r] == -1) {
		long long res = 0;
		for (int c = l - 1; c <= r; c++) {
			res += calc_dp(l, c) * 1ll * calc_dp(c + 1, r);
			if (res >= md2) res -= md2;
		}
		
		g[l][r] = res % md;
	}
	
	return g[l][r];
}

int calc_dp(int l, int r) {
	if (l > r) return 1;
	
	if (dp[l][r] == -1) {
		int v = mn[l][r], res;
		
		if (L[v] < l || R[v] > r) res = 0;
		else {
			res = calc_f(v);
			res = res * 1ll * calc_g(l, L[v] - 1) % md;
			res = res * 1ll * calc_g(R[v] + 1, r) % md;
		}
		
		dp[l][r] = res;
	}
	
	return dp[l][r];
}

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	fill(L, L + n, -1);
	
	for (int i = 0, x; i < m; i++) {
		ignore = scanf("%d", &x);
		x--;
		if (k > 0 && a[k - 1] == x) continue;
		a[k] = x;
		if (L[x] == -1) L[x] = k;
		R[x] = k;
		k++;
	}
	
	fill(f, f + n, -1);
	for (int i = 0; i < k; i++) {
		fill(dp[i], dp[i] + k, -1);
		fill(g[i], g[i] + k, -1);
	}
	
	for (int i = 0; i < k; i++) {
		mn[i][i] = a[i];
		for (int j = i + 1; j < k; j++) {
			mn[i][j] = min(mn[i][j - 1], a[j]);
		}
	}
	
	printf("%d\n", calc_dp(0, k - 1));
	
	return 0;
}