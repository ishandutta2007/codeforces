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

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)1e5;
const int inf = (int)1e9 + 100;

int n, L, R;
vector<pii> g[N];
int W[N];

int sizes[N];
bool ban[N];
int p[N];

void calc_sz(int v, int p) {
	sizes[v] = 1;
	for (pii& e : g[v]) {
		int to = e.first;
		if (to != p && !ban[to]) {
			calc_sz(to, v);
			sizes[v] += sizes[to];
		}
	}
}

int get_c(int v, int p, int n) {
	for (pii& e : g[v]) {
		int to = e.first;
		if (to != p && !ban[to] && 2 * sizes[to] > n) {
			return get_c(to, v, n);
		}
	}
	return v;
}

void cd(int v, int pp) {
	calc_sz(v, -1);
	v = get_c(v, -1, sizes[v]);
	p[v] = pp;
	ban[v] = true;
	for (pii& e : g[v]) {
		int to = e.first;
		if (!ban[to]) {
			cd(to, v);
		}
	}
}

int dep[N];
int dif[N];
int opt[N], mdf[N], tik_tak, vo[N], hd;
int po[N], mdf1[N], tik_tak1, vo1[N], phd;

void dfs(int v, int p, int x) {
	hd = max(hd, dep[v]);
	if (mdf[dep[v]] != tik_tak) {
		opt[dep[v]] = inf;
		mdf[dep[v]] = tik_tak;
	}
	if (dif[v] < opt[dep[v]]) {
		opt[dep[v]] = dif[v];
		vo[dep[v]] = v;
	}
	for (pii& e : g[v]) {
		int to = e.first;
		if (!ban[to] && to != p) {
			int w = e.second;
			dep[to] = dep[v] + 1;
			dif[to] = dif[v] + (w < x ? 1 : -1);
			dfs(to, v, x);
		}
	}
}

int U, V;

bool solve(int x) {
	for (int c = 0; c < n; c++) {
		{
			int v = c;
			while (v != -1) {
				ban[v] = true;
				v = p[v];
			}
		}
		dif[c] = dep[c] = 0;
		tik_tak1++;
		phd = 0;
		vo1[0] = c;
		po[0] = 0;
		mdf1[0] = tik_tak1;
		for (pii& e : g[c]) {
			int v = e.first;
			int w = e.second;
			if (!ban[v]) {
				dep[v] = 1;
				dif[v] = (w < x ? 1 : -1);
				tik_tak++;
				hd = 0;
				dfs(v, c, x);
				deque<int> q;
				int l = 0, r = -1;
				for (int i = hd; i >= 0; i--) {
					while (r < min(R - i, phd)) {
						r++;
						while (!q.empty() && po[q.back()] >= po[r]) {
							q.pop_back();
						}
						q.pb(r);
					}
					while (l <= r && l < L - i) {
						if (!q.empty() && q.front() == l) {
							q.pop_front();
						}
						l++;
					}
					if (!q.empty() && po[q.front()] <= -opt[i]) {
						U = vo1[q.front()];
						V = vo[i];
						return true;
					}
				}
				for (int i = 0; i <= hd; i++) {
					if (mdf1[i] != tik_tak1) {
						po[i] = inf;
						mdf1[i] = tik_tak1;
					}
					if (opt[i] < po[i]) {
						po[i] = opt[i];
						vo1[i] = vo[i];
					}
				}
				phd = max(phd, hd);
			}
		}
		{
			int v = c;
			while (v != -1) {
				ban[v] = false;
				v = p[v];
			}
		}
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> L >> R;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		g[u].pb({ v, w }); g[v].pb({ u, w }); W[i] = w;
	}
	sort(W, W + n - 1);
	cd(0, -1);
	memset(ban, false, sizeof(ban));
	int lf = 0, rg = n - 2;
	while (lf < rg) {
		int md = (lf + rg + 1) >> 1;
		if (solve(W[md])) {
			lf = md;
		}
		else {
			rg = md - 1;
		}
	}
	solve(W[lf]);
	cout << U + 1 << ' ' << V + 1;
}