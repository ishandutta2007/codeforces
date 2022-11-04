#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOGN = 19;
int n, dep[N];
long long ans;
vector<int> G[N];
inline void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}
namespace TR {
	int dfn[N], pa[LOGN][N], lg2[N * 2], st[LOGN][N * 2], dfc;
	inline void Pre() {
		lg2[0] = -1;
		for (int i = 1; i <= dfc; i++) lg2[i] = lg2[i - 1] + ((i & (i - 1)) ? 0 : 1);
		for (int i = 1; i <= lg2[dfc]; i++) {
			for (int j = 1; j + (1 << i) - 1 <= dfc; j++) {
				if (dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << (i - 1))]])
					st[i][j] = st[i - 1][j];
				else
					st[i][j] = st[i - 1][j + (1 << (i - 1))];
			}
		}
		for (int i = 1; i < LOGN; i++)
			for (int u = 1; u <= 2 * n - 1; u++)
				pa[i][u] = pa[i - 1][pa[i - 1][u]];
	}
	inline int LCA(int l, int r) {
		l = dfn[l], r = dfn[r];
		if (l > r) swap(l, r);
		int i = lg2[r - l + 1];
		if (dep[st[i][l]] < dep[st[i][r - (1 << i) + 1]])
			return st[i][l];
		else
			return st[i][r - (1 << i) + 1];
	}
	inline int Dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
	}
	inline int Anc(int u, int k) {
		for (int i = 0; i < LOGN; i++) if (k >> i & 1) u = pa[i][u];
		return u;
	}
}
using TR::LCA;
using TR::Dist;
using TR::Anc;
void pre_dfs(int u, int lst, int depth) {
	using namespace TR;
	dep[u] = depth;
	pa[0][u] = lst;
	st[0][dfn[u] = ++dfc] = u;
	for (int v : G[u]) if (v != lst) {
		pre_dfs(v, u, depth + 1);
		st[0][++dfc] = u;
	}
}
int sz[N], vis[N], fr[N], bl[N], cd[LOGN][N], sumsz[N];
long long sumd[N], sumdfr[N];
pair<int, int> findrt(int u, int lst, int totsz) {
	pair<int, int> ret(1e9, 0);
	int mx = 0;
	sz[u] = 1;
	for (int v : G[u]) if (v != lst && !vis[v]) {
		ret = min(ret, findrt(v, u, totsz));
		mx = max(mx, sz[v]);
		sz[u] += sz[v];
	}
	mx = max(mx, totsz - sz[u]);
	ret = min(ret, make_pair(mx, u));
	return ret;
}
void ff(int u, int lst, int depth, int *dis) {
	dis[u] = depth;
	sz[u] = 1;
	for (int v : G[u]) if (v != lst && !vis[v]) {
		ff(v, u, depth + 1, dis);
		sz[u] += sz[v];
	}
}
void DC(int rt, int totsz, int lst, int depth) {
	rt = findrt(rt, 0, totsz).second;
	vis[rt] = 1;
	fr[rt] = lst;
	bl[rt] = depth;
	ff(rt, 0, 0, cd[depth]);
	for (int v : G[rt]) if (!vis[v]) {
		DC(v, sz[v], rt, depth + 1);
	}
}
inline void Modify(int u, int op) {
	for (int c = u; c; c = fr[c]) {
		sumsz[c] += op;
		sumd[c] += op * cd[bl[c]][u];
		if (fr[c]) {
			sumdfr[c] += op * cd[bl[c] - 1][u];
		}
	}
}
inline long long Query(int u) {
	long long ret = 0, lds = 0;
	for (int c = u, lsz = 0; c; c = fr[c]) {
		ret += 1ll * (sumsz[c] - lsz) * cd[bl[c]][u] + sumd[c] - lds;
		lsz = sumsz[c];
		lds = sumdfr[c];
	}
	return ret;
}
pair<int, int> ar[N];
int vr[N], rr[N];
long long ps[N];
inline pair<int, int> AP(pair<int, int> p, int u) {
	int d0 = Dist(p.first, p.second), d1 = Dist(u, p.first), d2 = Dist(u, p.second);
	int mx = max(max(d1, d2), d0);
	if (d0 == mx) return p;
	else if (d1 == mx) return make_pair(u, p.first);
	else return make_pair(u, p.second);
}
inline bool Contain(int i, int j) {
	return Dist(vr[i], vr[j]) <= rr[j] - rr[i];
}
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	ar[mid] = make_pair(mid, mid);
	for (int i = mid - 1; i >= l; i--) {
		ar[i] = AP(ar[i + 1], i);
	}
	ar[mid + 1] = make_pair(mid + 1, mid + 1);
	for (int i = mid + 2; i <= r; i++) {
		ar[i] = AP(ar[i - 1], i);
	}
	for (int i = l; i <= r; i++) {
		rr[i] = Dist(ar[i].first, ar[i].second) / 2;
		if (dep[ar[i].first] > dep[ar[i].second]) {
			vr[i] = Anc(ar[i].first, rr[i]);
		} else {
			vr[i] = Anc(ar[i].second, rr[i]);
		}
	}
	ps[r + 1] = 0;
	for (int i = r; i > mid; i--) {
		ps[i] = ps[i + 1] + rr[i];
	}
	int ql = mid + 1, qr = mid + 1;
	for (int i = mid; i >= l; i--) {
		while (qr <= r && !Contain(i, qr)) Modify(vr[qr], 1), qr++;
		while (ql < qr && Contain(ql, i)) Modify(vr[ql], -1), ql++;
		ans += 1ll * (ql + qr - 2 * mid - 2) * rr[i] + ps[ql] + ps[qr] + Query(vr[i]);
	}
	for (int u = ql; u < qr; u++) Modify(vr[u], -1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, n + i);
		add_edge(v, n + i);
	}
	pre_dfs(1, 0, 0);
	TR::Pre();
	DC(1, 2 * n - 1, 0, 0);
	solve(1, n);
	printf("%lld\n", ans / 2);
	return 0;
}