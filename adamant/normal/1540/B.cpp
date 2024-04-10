#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 202;

int n;
vector<int> g[maxn];
int pr[maxn][maxn];

int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}
int dv(int a, int b) {
	return mul(a, inv(b));
}
int ad(int a, int b) {
	return (a + b) % mod;
}

int R[maxn][maxn];

int get(int a, int b) {
	if(a == 0) {
		return 1;
	} else if(b == 0) {
		return 0;
	} else {
		return R[a][b] ? R[a][b] : R[a][b] = dv(ad(get(a - 1, b), get(a, b - 1)), 2);
	}
}

void solve() {
	int n;
	cin >> n;
	int g[n][n];
	memset(g, 0x3F, sizeof g);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u][v] = g[v][u] = 1;
	}
	for(int k = 0; k < n; k++) {
		g[k][k] = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = 0; k < n; k++) {
				int d = (g[i][j] + g[k][i] - g[k][j]) / 2;
				ans = ad(ans, get(g[i][j] - d, d));
			}
		}
	}
	cout << dv(ans, n) << "\n";
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
		solve();
	}
    return 0;
}