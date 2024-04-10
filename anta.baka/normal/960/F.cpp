#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5;

struct segTree {
	int n; vector<int> t;
	segTree(int n) : n(n), t(2 * n, 0) {}
	void upd(int v, int x) {
		t[v += n] = x;
		for(v >>= 1; v; v >>= 1) t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
	int get(int l,  int r) {
		int ret = 0;
		for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if(l & 1 ) ret = max(ret, t[l]);
			if(!(r & 1)) ret = max(ret, t[r]);
		}
		return ret;
	}
};

int n, m, ans, uu[maxn], vv[maxn], ww[maxn];
vector<pair<int, int>> e[maxn];
vector<segTree> t;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		e[v].push_back({w, u});
		uu[i] = u; vv[i] = v; ww[i] = w;
	}
	for(int i = 0; i < n; i++) sort(all(e[i]));
	for(int i = 0; i < n; i++) t.emplace_back(segTree(sz(e[i])));
	for(int i = 0; i < m; i++) {
		int u = uu[i], v = vv[i], w = ww[i];
		int id = lower_bound(all(e[v]), make_pair(w, u)) - e[v].begin();
		int opt = 0;
		if(sz(e[u]) && e[u][0].first < w) {
			int lf = 0, rg = sz(e[u]) - 1;
			while(lf < rg) {
				int md = (lf + rg + 1) >> 1;
				if(e[u][md].first < w) lf = md;
				else rg = md - 1;
			}
			opt = t[u].get(0, lf);
		}
		t[v].upd(id, opt + 1);
		ans = max(ans, opt + 1);
	}
	cout << ans;
}