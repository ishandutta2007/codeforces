#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 150 * 1000 + 5, mod = 998244353;
int n, q, t;

vector <int> adj[N];
long long seg[N * 4];
int bg[N];
int sz[N];
int st[N];
int ft[N];
int dp[N];
int par[N];
long long a[N];


int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
void dfs1(int v) {
	st[v] = t;
	t++;
	sz[v] = 1;
	for (auto u : adj[v]) {
		if (u != par[v]) {
		//	cout << "48 " << v << " " << u << endl;
			par[u] = v;
			dfs1(u);
			sz[v] += sz[u];
			if (sz[u] > sz[bg[v]]) {
				bg[v] = u;
			}
		}
	}
	ft[v] = t;
}
void dfs2(int v) {
	for (auto u : adj[v]) {
		if (u != par[v]) {
			if (u == bg[v]) {
				dp[u] = dp[v];
			}
			else {
				dp[u] = u;
			}
			dfs2(u);
		}
	}
}
void update(int l, int r, long long x, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		seg[id] += x;
		seg[id] %= mod;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, x, id * 2, s, md);
	update(l, r, x, id * 2 + 1, md, e);
}
long long get(int x, int id = 1, int s = 0, int e = n) {
	if (e <= x || x < s) {
		return 0;
	}
	if (e - s == 1) {
		return seg[id];
	}
	int md = (s + e) / 2;
	long long ans = seg[id];
	ans += get(x, id * 2, s, md);
	ans %= mod;
	ans += get(x, id * 2 + 1, md, e);
	ans %= mod;
	return ans;
}
int32_t main() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	dp[1] = 1;
	dfs2(1);
//	for (int i = 1; i <= n; i++) {
//		cout << "37 " << i << " " << st[i] << " " << ft[i] << " " << sz[i] << " " << dp[i] << endl;
//	}
	int np = po(n, mod - 2);
	for (int i = 0; i < q; i++) {
		int qt, v;
		cin >> qt >> v;
		if (qt == 1) {
			int d;
			cin >> d;
			if (bg[v]) {
				int u = bg[v];
				update(0, st[v], 1ll * sz[v] * d);
				update(ft[v], n, 1ll * sz[v] * d);
				update(st[u], ft[u], 1ll * (n - sz[u]) * d);
				update(st[v], st[v] + 1, 1ll * n * d);
			}
			else {
				update(0, n, d);
				update(st[v], st[v] + 1, 1ll * (n - 1) * d);
			}
			
			a[v] += d;
		}
		else {
			long long ans = get(st[v]);
		//	cout << "47 " << ans << " ";
			v = dp[v];
			while (v != 1) {
				ans += 1ll * a[par[v]] * (n - sz[v]);
				ans %= mod;
				v = dp[par[v]];
			}
			cout << (1ll * np * ans) % mod << endl;
		//	cout << ans << endl;
		}
	}
	return 0;
}