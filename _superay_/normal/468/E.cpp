#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline vector<int> Merge(vector<int> a, vector<int> b) {
	vector<int> c(a.size() + b.size() - 1, 0);
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)b.size(); j++) {
			c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;
		}
	}
	return c;
}
namespace DP {
	int dp[1 << 17];
	inline vector<int> solve(int cl, int cr, vector<pair<pair<int, int>, int> > ve) {
		vector<vector<pair<int, int> > > G(cr);
		for (auto &P : ve) G[P.first.second].push_back(make_pair(P.first.first, P.second));
		memset(dp, 0, (1 << cl) << 2);
		dp[0] = 1;
		for (int i = 0; i < cr; i++) {
			for (int mask = (1 << cl) - 1; mask >= 0; mask--) {
				for (auto &P : G[i]) {
					int j = P.first;
					if (!(mask >> j & 1)) continue;
					dp[mask] = (dp[mask] + 1ll * dp[mask ^ (1 << j)] * P.second) % mod;
				}
			}
		}
		vector<int> ret(cl + 1, 0);
		for (int mask = 0; mask < (1 << cl); mask++) {
			int c = __builtin_popcount(mask);
			ret[c] = (ret[c] + dp[mask]) % mod;
		}
		while (!ret.back()) ret.pop_back();
		return ret;
	}
}
namespace TR {
	inline vector<int> solve(int cl, int cr, vector<pair<pair<int, int>, int> > ve) {
		int n = cl + cr;
		vector<vector<pair<int, int> > > G(n), T(n);
		vector<pair<pair<int, int>, int> > nte;
		for (auto &P : ve) {
			G[P.first.first].push_back(make_pair(P.first.second + cl, P.second));
			G[P.first.second + cl].push_back(make_pair(P.first.first, P.second));
		}
		vector<int> dep(n, -1);
		function<void(int, int, int)> dfs = [&](int u, int lst, int depth) {
			dep[u] = depth;
			for (auto &P : G[u]) {
				int v = P.first;
				if (v == lst) continue;
				if (dep[v] == -1) {
					T[u].push_back(P);
					dfs(v, u, depth + 1);
				} else if (dep[v] < dep[u]) {
					nte.push_back(make_pair(make_pair(u, v), P.second));
				}
			}
		};
		dfs(0, -1, 0);
		vector<int> ret(cl + 1, 0);
		for (int mask = 0; mask < (1 << nte.size()); mask++) {
			vector<int> lab(n, 0);
			int bad = 0, c = 0, prd = 1;
			for (int i = 0; i < (int)nte.size(); i++) if (mask >> i & 1) {
				c++;
				prd = 1ll * prd * nte[i].second % mod;
				int u = nte[i].first.first, v = nte[i].first.second;
				if (lab[u] || lab[v]) { bad = 1; break; }
				lab[u] = lab[v] = 1;
			}
			if (bad) continue;
			vector<vector<int> > f0(n), f1(n);
			function<void(int)> go = [&](int u) {
				f0[u].push_back(1);
				f1[u].push_back(0);
				for (auto &P : T[u]) {
					int v = P.first;
					go(v);
					int su = f0[u].size(), sv = f0[v].size();
					vector<int> nf0(su + sv, 0), nf1(su + sv, 0);
					for (int i = 0; i < su; i++) {
						for (int j = 0; j < sv; j++) {
							nf0[i + j] = (nf0[i + j] + 1ll * f0[u][i] * (f0[v][j] + f1[v][j])) % mod;
							if (!lab[u] && !lab[v]) nf1[i + j + 1] = (nf1[i + j + 1] + 1ll * f0[u][i] * f0[v][j] % mod * P.second) % mod;
							nf1[i + j] = (nf1[i + j] + 1ll * f1[u][i] * (f0[v][j] + f1[v][j])) % mod;
						}
					}
					while (nf0.size() && !nf0.back() && !nf1.back()) nf0.pop_back(), nf1.pop_back();
					f0[u] = nf0;
					f1[u] = nf1;
				}
			};
			go(0);
			for (int i = 0; i < (int)f0[0].size(); i++) {
				ret[i + c] = (ret[i + c] + 1ll * (f0[0][i] + f1[0][i]) * prd) % mod;
			}
		}
		while (!ret.back()) ret.pop_back();
		return ret;
	}
}
int n, m, fact[100005], fa[200005], id[200005], eu[55], ev[55], ew[55];
vector<int> buck[200005];
int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = fact[0] = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
		ew[i] = (ew[i] - 1 + mod) % mod;
		fa[Find(ev[i] + n)] = Find(eu[i]);
	}
	for (int i = 1; i <= 2 * n; i++) buck[Find(i)].push_back(i);
	vector<int> res;
	res.push_back(1);
	for (int i = 1; i <= 2 * n; i++) if (buck[i].size() > 1) {
		int cl = 0, cr = 0;
		for (int u : buck[i]) if (u <= n) id[u] = cl++; else id[u] = cr++;
		vector<pair<pair<int, int>, int> > ve;
		for (int j = 1; j <= m; j++) if (Find(eu[j]) == i)
			ve.push_back(make_pair(make_pair(id[eu[j]], id[ev[j] + n]), ew[j]));
		if (cl > cr) {
			swap(cl, cr);
			for (auto &P : ve) swap(P.first.first, P.first.second);
		}
		res = Merge(res, cl <= 17 ? DP::solve(cl, cr, ve) : TR::solve(cl, cr, ve));
	}
	int ans = 0;
	for (int i = 0; i < (int)res.size(); i++) {
		ans = (ans + 1ll * fact[n - i] * res[i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}