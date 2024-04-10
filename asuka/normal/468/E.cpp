#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 55, M = 2e5 + 15, mod = 1e9 + 7;
void Inc(int &x, int y) { (x += y) >= mod && (x -= mod); }

int ans[N];

namespace sol0 {
	int n, m, k, f[N][1 << 17], g[N][1 << 17], c[N];
	vector<pii> to[N];

	void solve(vector<int> L, vector<int> R, vector<tuple<int, int, int>> ed) {
		sort(all(L)), n = SZ(L);
		sort(all(R)), m = SZ(R);
		k = SZ(ed);
		rep(j, 0, k) memset(f[j], 0, 4 << n); 
		f[0][0] = 1;
		rep(i, 1, m) to[i].clear();

		for (auto &[u, v, w] : ed) {
			int o = lower_bound(all(L), u) - L.begin();
			if (o == SZ(L) || L[o] != u) swap(u, v);
		}

		for (auto [u, v, w] : ed) {
			u = lower_bound(all(L), u) - L.begin();
			v = lower_bound(all(R), v) - R.begin() + 1;
			to[v].eb(u, w);
		}

		rep(i, 0, m - 1) {
			rep(j, 0, k) memset(g[j], 0, 4 << n);

			rep(j, 0, k)  rep(s, 0, (1 << n) - 1) {
				if (!f[j][s]) continue;
				Inc(g[j][s], f[j][s]);

				for (auto [u, w] : to[i + 1]) {
					if (~s >> u & 1) 
						Inc(g[j + 1][s | (1 << u)], (ll) f[j][s] * w % mod);
				}
			}
			swap(f, g);
		}

		rep(j, 1, k) {
			c[j] = 0;
			rep(s, 0, (1 << n) - 1) Inc(c[j], f[j][s]);
		}

		per(i, 1, 50) rep(j, 1, min(i, k)) Inc(ans[i], (ll) ans[i - j] * c[j] % mod);
	}
}

namespace sol1 {
	int n, m, k, c[N], d[N], f[N][N][2], h[N][2], siz[N];
	vector<pii> g[N];
	bool vi[N];

	void dfs(int u) {
		siz[u] = 1, vi[u] = 1;
		memset(f[u], 0, sizeof f[u]);
		f[u][0][0] = 1;

		for (auto [v, w] : g[u]) {
			if (vi[v]) continue;
			dfs(v);
			memset(h, 0, sizeof h);

			rep(i, 0, siz[u]) rep(j, 0, siz[v]) {
				Inc(h[i + j][0], (ll) f[u][i][0] * (f[v][j][0] + f[v][j][1]) % mod);
				Inc(h[i + j][1], ((ll) f[u][i][1] * (f[v][j][0] + f[v][j][1]) + (ll) w * f[u][i][0] % mod * (j ? f[v][j - 1][0] : 0)) % mod);
			}

			swap(f[u], h);
			siz[u] += siz[v];
		}
 	}

	void solve(vector<tuple<int, int, int>> ed, vector<tuple<int, int, int>> ed2, vector<int> nd) {
		n = SZ(nd), m = SZ(ed2), k = m + SZ(ed);
		sort(all(nd));
		c[0] = 1;
		rep(i, 1, k) c[i] = 0;
		rep(i, 1, n) g[i].clear();
		for (auto &[u, v, w] : ed) u = lower_bound(all(nd), u) - nd.begin() + 1, v = lower_bound(all(nd), v) - nd.begin() + 1, g[u].eb(v, w), g[v].eb(u, w);
		for (auto &[u, v, w] : ed2) u = lower_bound(all(nd), u) - nd.begin() + 1, v = lower_bound(all(nd), v) - nd.begin() + 1;

		rep(s, 0, (1 << m) - 1) {
			fill(vi + 1, vi + n + 1, 0);
			int mul = 1, bad = 0, cnt = 0;

			rep(i, 0, m - 1) {
				if (~s >> i & 1) continue;
				auto [u, v, w] = ed2[i];
				if (vi[u] | vi[v]) bad = 1;
				vi[u] = vi[v] = 1;
				mul = (ll) mul * w % mod;
				cnt++;
			}

			if (bad) continue;
			d[0] = 1;
			rep(i, 1, k) d[i] = 0;

			rep(x, 1, n) {
				if (vi[x]) continue;
				dfs(x);
				per(i, 1, k) rep(j, 1, i) Inc(d[i], (ll) d[i - j] * (f[x][j][0] + f[x][j][1]) % mod);
			}

			rep(i, 0, k - cnt) Inc(c[i + cnt], (ll) d[i] * mul % mod);	
		}

		per(i, 1, 50) rep(j, 1, min(i, k)) Inc(ans[i], (ll) ans[i - j] * c[j] % mod);
	}
}

int n, k, x[N], y[N], z[N], dep[M], fac[M];
vector<pii> e[M];
vector<tuple<int, int, int>> ed, ed2;
vector<int> nd[2];

void dfs(int u, int pa, int c) {
	dep[u] = dep[pa] + 1;
	nd[c].pb(u);

	for (auto [v, w] : e[u]) {
		if (!dep[v]) dfs(v, u, c ^ 1), ed.eb(u, v, w);
		else if (dep[v] > dep[u]) ed2.eb(u, v, w);
	}
}

int main() {

	scanf("%d%d", &n, &k);
	fac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
	ans[0] = 1;

	rep(i, 1, k) {
		scanf("%d%d%d", x + i, y + i, z + i);
		(z[i] += mod - 1) %= mod;
		e[x[i]].eb(y[i] + n, z[i]);
		e[y[i] + n].eb(x[i], z[i]);
	}

	rep(i, 1, n) {
		if (dep[i]) continue;
		ed.clear(), ed2.clear(), nd[0].clear(), nd[1].clear();
		dfs(i, 0, 1);
		if (ed.empty()) continue;

		if (SZ(nd[0]) > SZ(nd[1])) swap(nd[0], nd[1]);

		if (SZ(nd[0]) <= 17) {
			for (auto x : ed2) ed.pb(x);
			sol0::solve(nd[0], nd[1], ed);
		} else {
			for (int x : nd[1]) nd[0].pb(x);
			sol1::solve(ed, ed2, nd[0]);
		}		
	}

	int res = 0;
	rep(i, 0, min(n, k)) Inc(res, (ll) ans[i] * fac[n - i] % mod);
	printf("%d\n", res);
	return 0;
}