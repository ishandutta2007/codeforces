#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int mul(int a, int b) {
	return a * b % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod - 2);
}

const int maxn = 2e5 + 42;
vector<int> g[maxn];
int sz[maxn];

int F[maxn];
int fact(int n) {
	return n ? F[n] ? F[n] : F[n] = mul(n, fact(n - 1)) : 1;
}

int dfs(int v = 0, int p = 0) {
	int ans = 1;
	sz[v] = 1;
	for(auto u: g[v]) {
			if(u != p) {
			ans = mul(ans, dfs(u, v));
			sz[v] += sz[u];
		}
	}
	int res = mul(ans, fact(g[v].size()));
	//cout << v << ' ' << res << endl;
	return res;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << mul(n, dfs()) << endl;
	return 0;
}