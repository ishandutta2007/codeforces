#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 100015;

int n, q, t;

struct solver {
	vector<pii> e[N];

	int rt, rk[N], son[N];

	int dep[N], dis[N];

	void add(int u, int v, int w) {
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	pii dfs0(int u, int pa) {
		pii res = mp(0, u);

		for (auto [v, w] : e[u]) {
			if (v == pa) continue;

			auto nres = dfs0(v, u); nres.fi += w;
			res = max(res, nres);
		}

		return res;
	}

	void dfs1(int u, int pa) {
		for (auto [v, w] : e[u]) {
			if (v == pa) continue;

			dis[v] = dis[u] + w;
			dfs1(v, u);

			if (dep[v] + w > dep[u]) {
				dep[u] = dep[v] + w;
				son[u] = v;
			}
		}
	}

	vector<pii> vec;

	int bel[N], len[N];

	void dfs2(int u, int pa, int top) {
		if (son[u]) dfs2(son[u], u, top);

		bel[u] = top;

		for (auto [v, w] : e[u]) {
			if (v == pa || v == son[u]) continue;

			len[v] = w;
			dfs2(v, u, v);
		}

		if (u == top) vec.emplace_back(dep[u] + len[u], u);
	}

	int Min[N][18], fa[N][18];

	void dfs3(int u, int pa) {
		fa[u][0] = pa; Min[u][0] = rk[pa];
		rep(i, 1, 17) fa[u][i] = fa[fa[u][i - 1]][i - 1], Min[u][i] = min(Min[u][i - 1], Min[fa[u][i - 1]][i - 1]);

		for (auto [v, w] : e[u]) {
			if (v == pa) continue;

			dfs3(v, u);
		}
	}

	int val[N], sum[N];

	int build(int o) {
		dfs1(rt = dfs0(o, 0).se, 0);
		dfs2(rt, 0, rt);
		sort(all(vec), greater<pii>());
		rep(i, 0, SZ(vec) - 1) rk[vec[i].se] = i + 1, val[i + 1] = vec[i].fi, sum[i + 1] = sum[i] + val[i + 1];
		rep(i, 1, n) rk[i] = rk[bel[i]];
		rk[0] = inf; dfs3(rt, 0);
		return rt;
	}

	int up(int u, int k) {
		if (rk[u] <= k) return u;

		per(j, 0, 17) if (Min[u][j] > k) u = fa[u][j];

		return fa[u][0] == 0 ? rt : fa[u][0];
	}

	int mdis(int u) {return dep[u] + dis[u];}

	int ask(int u, int k) {
		k = min(k * 2 - 1, SZ(vec));

		if (rk[u] <= k) return sum[k];

		return max(sum[k] - val[k] + dep[u] + dis[u] - dis[up(u, k - 1)],
		           sum[k] - mdis(up(u, k - 1)) + mdis(u));
	}
} jt, hyh;

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 2, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		jt.add(u, v, w);
		hyh.add(u, v, w);
	}
	hyh.build(jt.build(1));

	int las = 0;

	rep(_, 1, q) {
		int u, k;
		scanf("%d%d", &u, &k);
		u = (u + las - 1) % n + 1;
		k = (k + las - 1) % n + 1;
		printf("%d\n", las = max(hyh.ask(u, k), jt.ask(u, k)));
	}

	return 0;
}