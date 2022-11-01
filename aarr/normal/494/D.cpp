#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 100 * 1000 + 5, LG = 19, mod = 1000 * 1000 * 1000 + 7;
int n, q;

int sz[N], h[N];
long long sumd[N], sumu[N], dpd[N], dpu[N];
pair <int, long long> par[N][LG];
vector <pair <int, int> > adj[N];

void dfs1(int v) {
	sz[v] = 1;
	for (auto p : adj[v]) {
		int u = p.first;
		long long w = p.second;
		if (u != par[v][0].first) {
			h[u] = h[v] + 1;
			par[u][0] = {v, w};
			dfs1(u);
			sz[v] += sz[u];
			sumd[v] += sumd[u] + 1ll * w * sz[u];
			sumd[v] %= mod;
			long long t = 1ll * w * w;
			t %= mod;
			t *= sz[u];
			t %= mod;
			dpd[v] += 2ll * sumd[u] * w;
			dpd[v] %= mod;
			dpd[v] += t;
			dpd[v] += dpd[u];
			dpd[v] %= mod;
		}
	}
}

void dfs2(int v) {
	for (auto p : adj[v]) {
		int u = p.first;
		long long w = p.second;
		if (u != par[v][0].first) {
			long long q = dpd[v] + dpu[v];
			long long t = 1ll * w * w;
			t %= mod;
			t *= sz[u];
			t %= mod;
			q -= t - mod;
			q -= (2ll * sumd[u] * w) % mod - mod;
			q -= dpd[u] - mod;
			q %= mod;
			dpu[u] = q;
		//	cout << "71 " << v << " " << u << " " << q << endl;
			long long t2 = 1ll * w * w;
			t2 %= mod;
			t2 *= (n - sz[u]);
			t2 %= mod;
			dpu[u] += t2;
			dpu[u] %= mod;
		//ghalat	dpu[u] += sumd[v] + sumu[v] - 1ll * sz[u] * w - sumd[u];
			dpu[u] += 1ll * (mod + 1) * mod;
			dpu[u] %= mod;
			long long kft = sumd[v] + sumu[v] - sumd[u] - 1ll * w * sz[u] + 1ll * mod * mod;
			kft %= mod;
			kft *= 2 * w;
			kft %= mod;
			dpu[u] += kft;
			dpu[u] %= mod;
			sumu[u] = sumd[v] + sumu[v] - 1ll * sz[u] * w - sumd[u] + 1ll * (n - sz[u]) * w;
			sumu[u] += 1ll * mod * mod;
			sumu[u] %= mod;
			dfs2(u);
		}
	}
}

pair <long long, int> lcad(int u, int v) {
	long long ans = 0;
	if (h[u] > h[v]) {
		swap(u, v);
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (h[u] + (1 << i) <= h[v]) {
			ans += par[v][i].second;
		//	cout << "71 " << v << " " << i << endl;
			v = par[v][i].first;
		//	cout << "74 " << v << " " << i << endl;
		}
	}
	if (u == v) {
		return {ans, u};
	}
//	cout << "75\n";
	for (int i = LG - 1; i >= 0; i--) {
		if (par[v][i].first != par[u][i].first) {
			ans += par[v][i].second;
			ans += par[u][i].second;
			v = par[v][i].first;
			u = par[u][i].first;
		}
	}
	ans += par[v][0].second + par[u][0].second;
	return {ans, par[v][0].first};
}

int32_t main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	par[1][0].first = 1;
	dfs1(1);
//	cout << 23124;
	dfs2(1);
//	for (int i = 1; i <= n; i++) {
//		cout << "73 " << i << " " << dpd[i] << " " << dpu[i] << endl;
//	}
	
	cin >> q;
	
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			int u = par[i][j - 1].first;
			par[i][j].first = par[u][j - 1].first;
			par[i][j].second = (par[i][j - 1].second + par[u][j - 1].second) % mod;
		}
	}
//	cout << "38 " << h[3] << " " << par[3][1].first << " " << par[3][1].second << endl;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		pair <long long, int> p = lcad(u, v);
		long long x = p.first;
		int r = p.second;
		x %= mod;
//		cout << "78 " << x << " " << r << endl;
		if (r == v) {
	//		cout << "34\n";
			long long ans = dpd[u] + dpu[u];
			long long e = 2ll * sumu[v];
			e %= mod;
			e *= x;
			e %= mod;
			ans -= 2ll * (e + dpu[v]) - 4ll * mod;
			ans %= mod;
			long long kft = 1ll * ((2ll * x * x) % mod) * (n - sz[v]);
			kft %= mod;
			ans -= kft - mod;
			ans += mod;
			ans %= mod;
			cout << ans << endl;
		}
		else {
			long long ans = 2ll * mod - dpd[u] - dpu[u];
			long long e = 2ll * sumd[v];
			e %= mod;
			e *= x;
			e %= mod;
			ans += 2ll * (e + dpd[v]);
			ans %= mod;
			ans += ((2ll * x * x) % mod) * sz[v];
			ans %= mod;
			cout << ans << endl;
		}
	}
	
	return 0;
}