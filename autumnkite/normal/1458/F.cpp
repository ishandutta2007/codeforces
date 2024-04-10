#include <bits/stdc++.h>

class tree {
	static int get_log(int n) {
		int res = 1;
		while ((1 << res) < n) {
			++res;
		}
		return res;
	}

	int n, LG;
	std::vector<std::vector<int>> E;
	std::vector<int> dep;
	std::vector<std::vector<int>> fa;

	void dfs(int u) {
		for (int i = 1; i < LG && fa[u][i - 1] != -1; ++i) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		for (int v : E[u]) {
			if (v != fa[u][0]) {
				fa[v][0] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
			}
		}
	}

	int LCA(int u, int v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[u][i] != -1 && dep[fa[u][i]] >= dep[v]) {
				u = fa[u][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		return fa[u][0];
	}

	int jump(int u, int d) {
		for (int i = LG - 1; i >= 0; --i) {
			if (d >> i & 1) {
				u = fa[u][i];
			}
		}
		return u;
	}

	std::vector<int> pfa, pdep;
	std::vector<int> sz;
	std::vector<bool> vis;
	std::vector<std::vector<int>> dis;
	std::vector<int> c;
	std::vector<long long> s, sf;

	void build(int rt, int d, int lst) {
		std::function<void(int, int)> get_sz = [&](int u, int fa) {
			sz[u] = 1;
			for (int v : E[u]) {
				if (v != fa && !vis[v]) {
					get_sz(v, u);
					sz[u] += sz[v];
				}
			}
		};
		get_sz(rt, -1);
		int ct = rt;
		std::function<void(int, int)> get_ct = [&](int u, int fa) {
			bool flag = true;
			for (int v : E[u]) {
				if (v != fa && !vis[v]) {
					get_ct(v, u);
					flag &= sz[v] <= sz[rt] / 2;
				}
			}
			flag &= sz[rt] - sz[u] <= sz[rt] / 2;
			if (flag) {
				ct = u;
			}
		};
		get_ct(rt, -1);
		pfa[ct] = lst, pdep[ct] = d;
		std::function<void(int, int)> build_dis = [&](int u, int fa) {
			for (int v : E[u]) {
				if (v != fa && !vis[v]) {
					dis[v][d] = dis[u][d] + 1;
					build_dis(v, u);
				}
			}
		};
		dis[ct][d] = 0;
		build_dis(ct, -1);
		vis[ct] = true;
		for (int v : E[ct]) {
			if (!vis[v]) {
				build(v, d + 1, ct);
			}
		}
	}

public:
	tree(const std::vector<std::pair<int, int>> &edge) : 
	  n(2 * edge.size() + 1), LG(get_log(n)), E(n), 
	  dep(n), fa(n, std::vector<int>(LG, -1)), 
	  pfa(n, -1), pdep(n), sz(n), vis(n), dis(n, std::vector<int>(LG + 1, 0)), c(n), s(n), sf(n) {
		int tn = (n + 1) / 2;
		for (int i = 0; i < tn - 1; ++i) {
			E[edge[i].first].push_back(tn + i);
			E[tn + i].push_back(edge[i].first);
			E[edge[i].second].push_back(tn + i);
			E[tn + i].push_back(edge[i].second);
		}
		dfs(0);
		build(0, 0, -1);
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
	}

	struct cover {
		int U, V, X, R;

		cover() : U(-1), V(-1), X(-1), R(0) {}

		cover(int u, int v, int x, int r) : U(u), V(v), X(x), R(r) {}
	};

	cover update(cover st, int u) {
		if (st.U == -1) {
			return cover(u, u, u, 0);
		}
		int dx = dist(st.U, u), dy = dist(st.V, u);
		if (std::max(dx, dy) > 2 * st.R) {
			if (dx > dy) {
				st.V = u;
				st.R = dx / 2;
			} else {
				st.U = u;
				st.R = dy / 2;
			}
		}
		if (dep[st.U] < dep[st.V]) {
			std::swap(st.U, st.V);
		}
		st.X = jump(st.U, st.R);
		return st;
	}

	bool inside(cover a, cover b) {
		return a.U == -1 || a.R + dist(a.X, b.X) <= b.R;
	}

	void insert(int u, int v) {
		for (int i = u, d = pdep[u]; i != -1; i = pfa[i], --d) {
			c[i] += v;
			s[i] += dis[u][d] * v;
			if (d > 0) {
				sf[i] += dis[u][d - 1] * v;
			}
		}
	}

	long long query(int u) {
		long long res = 0;
		for (int i = u, d = pdep[u]; i != -1; i = pfa[i], --d) {
			res += 1ll * dis[u][d] * c[i] + s[i];
			if (d > 0) {
				res -= 1ll * dis[u][d - 1] * c[i] + sf[i];
			}
		}
		return res;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> E(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> E[i].first >> E[i].second;
		--E[i].first, --E[i].second;
	}
	
	tree T(E);

	std::function<long long(int l, int r)> solve = [&](int l, int r) -> long long {
		if (l + 1 == r) {
			return 0;
		}
		int mid = (l + r + 1) >> 1;
		long long res = solve(l, mid) + solve(mid, r);
		std::vector<tree::cover> s(r - mid);
		for (int i = 0; i < r - mid; ++i) {
			s[i] = T.update(i > 0 ? s[i - 1] : tree::cover(), i + mid);
		}
		int p1 = 0, p2 = 0;
		tree::cover now;
		std::vector<long long> pre(r - mid + 1);
		for (int i = 0; i < r - mid; ++i) {
			pre[i + 1] = pre[i] + s[i].R;
		}
		for (int i = mid - 1; i >= l; --i) {
			now = T.update(now, i);
			while (p2 < r - mid && !T.inside(now, s[p2])) {
				T.insert(s[p2].X, 1);
				++p2;
			}
			while (p1 < p2 && T.inside(s[p1], now)) {
				T.insert(s[p1].X, -1);
				++p1;
			}
			res += 1ll * p1 * now.R;
			res += (1ll * T.query(now.X) + 1ll * now.R * (p2 - p1) + pre[p2] - pre[p1]) / 2;
			res += pre[r - mid] - pre[p2];
		}
		while (p1 < p2) {
			T.insert(s[p1].X, -1);
			++p1;
		}
		return res;
	};
	std::cout << solve(0, n) << "\n";
}