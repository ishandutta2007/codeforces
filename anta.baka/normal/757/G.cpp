#define CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <functional>
#include <complex>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 200000;

int n, q;
int a[N];
vector<pii> g[N];
int in_perm[N];

bool ban[N];
int sizes[N];

void calc_sizes(int v, int p) {
	sizes[v] = 1;
	for (const pii& e : g[v]) {
		if (e.first != p && !ban[e.first]) {
			calc_sizes(e.first, v);
			sizes[v] += sizes[e.first];
		}
	}
}

int get_cent(int v, int p, int n) {
	for (const pii& e : g[v]) {
		if (e.first != p && !ban[e.first] && 2 * sizes[e.first] > n) {
			return get_cent(e.first, v, n);
		}
	}
	return v;
}

const int L = 18;

int pc[N];
int v_lvl[N];
ll dep[L][N];
vi cst[N];
vector<ll> ft[N];
int sec_p[L][N];

vi sec_cst[L][N];
vector<ll> sec_ft[L][N];

void dfs_cst(int v, int p, int where, int lvl, int sec_v) {
	if (v != where) {
		if (sec_v == -1) {
			sec_v = v;
		}
	}
	sec_p[lvl][v] = sec_v;
	cst[where].pb(v);
	if (sec_v != -1) {
		sec_cst[lvl][sec_v].pb(v);
	}
	for (const pii& e : g[v]) {
		if (e.first != p && !ban[e.first]) {
			dep[lvl][e.first] = dep[lvl][v] + e.second;
			dfs_cst(e.first, v, where, lvl, sec_v);
		}
	}
}

bool cmp(int u, int v) {
	return in_perm[u] < in_perm[v];
}

void cent_dec(int v, int p, int lvl) {
	calc_sizes(v, -1);
	v = get_cent(v, -1, sizes[v]);
	ban[v] = true;
	pc[v] = p;
	v_lvl[v] = lvl;
	dep[lvl][v] = 0;
	dfs_cst(v, -1, v, lvl, -1);
	sort(all(cst[v]), cmp);
	ft[v].resize(sz(cst[v]));
	for (int i = 0; i < sz(cst[v]); i++) {
		int u = cst[v][i];
		ft[v][i] = (i ? ft[v][i - 1] : 0) + dep[lvl][u];
	}
	for (const pii& e : g[v]) {
		if (!ban[e.first]) {
			sort(all(sec_cst[lvl][e.first]), cmp);
			sec_ft[lvl][e.first].resize(sz(sec_cst[lvl][e.first]));
			for (int i = 0; i < sz(sec_cst[lvl][e.first]); i++) {
				int u = sec_cst[lvl][e.first][i];
				sec_ft[lvl][e.first][i] = (i ? sec_ft[lvl][e.first][i - 1] : 0) + dep[lvl][u];
			}
			cent_dec(e.first, v, lvl + 1);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; --a[i]; in_perm[a[i]] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		g[u].pb({ v, w }); g[v].pb({ u, w });
	}
	cent_dec(0, -1, 0);
	ll ans = 0;
	const int mod = (1 << 30);
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			l = (ans % mod) ^ l;
			r = (ans % mod) ^ r;
			v = (ans % mod) ^ v;
			--l;
			--r;
			--v;
			ans = 0;
			int c = v;
			while (c != -1) {
				int lvl = v_lvl[c];
				ll dvc = dep[lvl][v];
				int lb = lower_bound(all(cst[c]), a[l], cmp) - cst[c].begin();
				if (lb < sz(cst[c]) && in_perm[cst[c][lb]] <= r) {
					int rb = upper_bound(all(cst[c]), a[r], cmp) - cst[c].begin() - 1;
					ans += (rb - lb + 1) * dvc + ft[c][rb] - (lb ? ft[c][lb - 1] : 0);
					if (c != v) {
						int sec_v = sec_p[lvl][v];
						int lb = lower_bound(all(sec_cst[lvl][sec_v]), a[l], cmp) - sec_cst[lvl][sec_v].begin();
						if (lb < sz(sec_cst[lvl][sec_v]) && in_perm[sec_cst[lvl][sec_v][lb]] <= r) {
							int rb = upper_bound(all(sec_cst[lvl][sec_v]), a[r], cmp) - sec_cst[lvl][sec_v].begin() - 1;
							ans -= (rb - lb + 1) * dvc + sec_ft[lvl][sec_v][rb] - (lb ? sec_ft[lvl][sec_v][lb - 1] : 0);
						}
					}
				}
				c = pc[c];
			}
			cout << ans << '\n';
		}
		else {
			int i;
			cin >> i;
			i = (ans % mod) ^ i;
			--i;
			int c;
			{
				int c1 = a[i], c2 = a[i + 1];
				while (c1 != c2) {
					if (v_lvl[c1] < v_lvl[c2]) {
						swap(c1, c2);
					}
					c1 = pc[c1];
				}
				c = c1;
			}
			while (c != -1) {
				int j = lower_bound(all(cst[c]), a[i], cmp) - cst[c].begin();
				int lvl = v_lvl[c];
				ft[c][j] += dep[lvl][a[i + 1]] - dep[lvl][a[i]];
				swap(cst[c][j], cst[c][j + 1]);
				if (sec_p[lvl][a[i]] == sec_p[lvl][a[i + 1]]) {
					int sec_v = sec_p[lvl][a[i]];
					int j = lower_bound(all(sec_cst[lvl][sec_v]), a[i], cmp) - sec_cst[lvl][sec_v].begin();
					sec_ft[lvl][sec_v][j] += dep[lvl][a[i + 1]] - dep[lvl][a[i]];
					swap(sec_cst[lvl][sec_v][j], sec_cst[lvl][sec_v][j + 1]);
				}
				c = pc[c];
			}
			swap(a[i], a[i + 1]);
			in_perm[a[i]] = i;
			in_perm[a[i + 1]] = i + 1;
		}
	}
}