#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>
#include <set>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using vi = vector<int>;

const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;

ll pw(ll a, ll b, int mod) {
	ll r = 1;
	while (b) {
		if (b & 1) {
			r = r * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return r;
}

const int N = (1 << 17) + (1 << 17); // twice!

int add(int x, int y, int mod) {
	if ((x += y) >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y, int mod) {
	if ((x -= y) < 0) {
		x += mod;
	}
	return x;
}

void fft(int* a, int mod, bool inverse = false) { // work only with powers of two

	for (int len = 1; len < N; len *= 2) {
		for (int start = 0; start < N; start += len + len) {
			for (int i = 0; i < len; ++i) {
				int x = a[start + i];
				int y = a[start + len + i];
				a[start + i] = add(x, y, mod);
				a[start + len + i] = sub(x, y, mod);
			}
		}
	}

	if (inverse) {
		int kek = pw(N, mod - 2, mod);
		for (int i = 0; i < N; i++) {
			a[i] = (ll)a[i] * kek % mod;
		}
	}
}

int n, m;
vector<vector<pii>> g;
vi dep, up;
set<pii> br;

void add228(int u, int v) {
	if (u > v) swap(u, v);
	br.insert({ u, v });
}

bool isbr(int u, int v) {
	if (u > v) swap(u, v);
	return br.count({ u, v });
}

void dfs(int v, int p) {
	up[v] = dep[v];
	for (auto e : g[v]) {
		if (e.first != p) {
			if (dep[e.first] == -1) {
				dep[e.first] = dep[v] + 1;
				dfs(e.first, v);
				up[v] = min(up[v], up[e.first]);
				if (up[e.first] == dep[e.first]) {
					add228(v, e.first);
				}
			}
			else {
				up[v] = min(up[v], dep[e.first]);
			}
		}
	}
}

#define ws hui

vector<bool> was;
vector<vi> ws;

void dfs1(int v) {
	was[v] = true;
	for (auto e : g[v]) {
		if (!isbr(v, e.first)) {
			if (v < e.first) {
				ws.back().pb(e.second);
			}
			if (!was[e.first]) {
				dfs1(e.first);
			}
		}
	}
}

int a[N], b[N], c[N], d[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	g.resize(n);
	int xor_all = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].pb({ v, w });
		g[v].pb({ u, w });
		xor_all ^= w;
	}
	dep.resize(n, -1);
	dep[0] = 0;
	up.resize(n);
	dfs(0, -1);
	was.resize(n, false);
	for (int u = 0; u < n; u++) {
		if (!was[u]) {
			ws.emplace_back();
			dfs1(u);
			if (ws.back().empty()) {
				ws.pop_back();
			}
		}
	}
	if (ws.empty()) {
		cout << xor_all << ' ' << 1;
		return 0;
	}
	bool fst = true;
	for (int i = 0; i < sz(ws); i++) {
		memset(c, 0, sizeof(c));
		for (auto w : ws[i]) {
			c[w]++;
		}
		if (fst) {
			memcpy(a, c, sizeof(c));
			memcpy(b, c, sizeof(c));
			fft(a, mod);
			fft(b, mod2);
			fst = false;
		}
		else {
			memcpy(d, c, sizeof(c));
			fft(c, mod);
			for (int i = 0; i < N; i++) {
				a[i] = (ll)a[i] * c[i] % mod;
			}
			memcpy(c, d, sizeof(d));
			fft(c, mod2);
			for (int i = 0; i < N; i++) {
				b[i] = (ll)b[i] * c[i] % mod2;
			}
		}
	}
	fft(a, mod, true);
	fft(b, mod2, true);
	pii ans = { N, -1 };
	for (int i = 0; i < N; i++) {
		if (a[i] || b[i]) {
			ans = min(ans, make_pair(i ^ xor_all, a[i]));
		}
	}
	cout << ans.first << ' ' << ans.second;
}