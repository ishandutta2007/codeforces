#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int BSZ = 600;
const int N = 100228;
const int LG = 17;

int n, m;
vector<vi> g;
vi pred;
vi in, out;
int timer;
int up[LG][N];
vi ts;
vi evs;
vi sgn;
vector<bool> alive;
vi cnt;
vi dif;
vector<bool> any;
int cur_add;
vi ans;
vi bkt[2 * N];
vi srt[2 * BSZ];

void dfs(int v) {
	in[v] = timer++;
	for (int to : g[v]) {
		dfs(to);
	}
	out[v] = timer++;
}

bool upper(int u, int v) {
	return (in[u] <= in[v] && out[v] <= out[u]);
}

int lca(int u, int v) {
	if (in[u] > in[v]) {
		swap(u, v);
	}
	if (upper(u, v)) {
		return u;
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (!upper(up[i][u], v)) {
			u = up[i][u];
		}
	}
	return up[0][u];
}

void dfs_calc(int v) {
	cnt[v] = !alive[v];
	for (int to : g[v]) {
		dfs_calc(to);
		cnt[v] += cnt[to];
		any[v] = any[v] | any[to];
	}
	dif[v] = ts[v] - cnt[v];
	if (!any[v] && alive[v]) {
		cur_add += (dif[v] < 0);
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	pred.resize(n, -1);
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int p; cin >> p; --p; pred[i + 1] = p; g[p].pb(i + 1); up[0][i + 1] = p;
	}
	ts.resize(n);
	for (auto& x : ts) {
		cin >> x;
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 0; i < n; i++) {
			up[j][i] = up[j - 1][up[j - 1][i]];
		}
	}
	in.resize(n);
	out.resize(n);
	dfs(0);
	evs.resize(m);
	sgn.resize(m);
	for(int i = 0; i < m; i++) {
		auto& x = evs[i];
		cin >> x;
		sgn[i] = (x > 0 ? -1 : 1);
		x = abs(x) - 1;
	}
	alive.resize(n, true);
	cnt.resize(n);
	dif.resize(n);
	any.resize(n);
	ans.resize(m, 0);
	for (int lb = 0; lb < m; lb += BSZ) {
		int rb = min(m, lb + BSZ);
		vi guys(rb - lb);
		fill(all(any), false);
		for (int i = lb; i < rb; i++) {
			guys[i - lb] = evs[i];
			any[guys[i - lb]] = true;
		}
		sort(all(guys), [](int u, int v) { return (in[u] < in[v]); });
		guys.reserve(2 * sz(guys));
		for (int i = sz(guys) - 2; i >= 0; i--) {
			guys.pb(lca(guys[i], guys[i + 1]));
		}
		guys.pb(0);
		sort(all(guys), [](int u, int v) { return (in[u] < in[v]); });
		guys.resize(unique(all(guys)) - guys.begin());
		vi comp_pred(sz(guys), -1);
		vi st;
		int edge_check = 0;
		for(int i = 0; i < sz(guys); i++) {
			while (!st.empty() && !upper(guys[st.back()], guys[i])) {
				st.pop_back();
			}
			if (!st.empty()) {
				comp_pred[i] = st.back();
				edge_check++;
			}
			st.pb(i);
		}
		assert(edge_check == sz(guys) - 1);
		cur_add = 0;
		dfs_calc(0);
		for (int i = lb; i < rb; i++) {
			ans[i] = cur_add;
		}
		for (int i = 0; i < sz(guys); i++) {
			srt[i].clear();
		}
		for (int i = 0; i < 2 * N; i++) {
			bkt[i].clear();
		}
		for(int i = 0; i < sz(guys); i++) {
			int u = guys[i];
			bool st = alive[u];
			int udif = dif[u];
			for (int j = lb; j < rb; j++) {
				if (upper(u, evs[j])) {
					udif += sgn[j];
				}
				if (evs[j] == u) {
					st = !st;
				}
				if (st) {
					ans[j] += (udif < 0);
				}
			}
			if (i) { // edge
				int anc = guys[comp_pred[i]];
				int v = pred[u];
				if (anc != v) {
					while (v != anc) {
						if (alive[v]) {
							bkt[dif[v] + N].pb(i);
						}
						v = pred[v];
					}
				}
			}
		}
		for (int i = 0; i < 2 * N; i++) {
			for (int who : bkt[i]) {
				srt[who].pb(i - N);
			}
		}
		for(int i = 0; i < sz(guys); i++) {
			auto u = guys[i];
			auto& difs = srt[i];
			vector<pii> pref;
			pref.reserve(sz(difs));
			for (auto x : difs) {
				if (pref.empty()) {
					pref.pb({ x, 1 });
				}
				else if (x != pref.back().first) {
					pref.pb({ x, pref.back().second + 1 });
				}
				else {
					pref.back().second++;
				}
			}
			int pt = sz(pref);
			while (pt > 0 && pref[pt - 1].first >= 0) {
				pt--;
			}
			int bound = 0;
			for (int j = lb; j < rb; j++) {
				if (upper(u, evs[j])) {
					bound -= sgn[j];
					if (pt < sz(pref) && pref[pt].first < bound) {
						pt++;
					}
					if (pt > 0 && pref[pt - 1].first >= bound) {
						pt--;
					}
				}
				ans[j] += (pt ? pref[pt - 1].second : 0);
			}
		}
		for (int i = lb; i < rb; i++) {
			int u = evs[i];
			alive[u] = !alive[u];
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
}