#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXN 200002
#define MAXL 20

int n, m;
vector <int> g[MAXN];
vector < pair<int, pair<int, int> > > f[MAXN];
int lvl[MAXN];
int p[MAXL][MAXN];
int h[MAXL][MAXN];
int d[MAXN][2];

inline int lca(int v1, int v2) {
	if (lvl[v1] < lvl[v2]) swap(v1, v2);
	for (int i = MAXL - 1; i >= 0; --i) {
		if (lvl[p[i][v1]] >= lvl[v2]) {
			v1 = p[i][v1];
		}
	}
	if (v1 == v2) return v1;
	for (int i = MAXL - 1; i >= 0; --i) {
		if (p[i][v1] != p[i][v2]) {
			v1 = p[i][v1];
			v2 = p[i][v2];
		}
	}
	return p[0][v1];
}

void dfs(int v = 0, int level = 0, int pr = 0) {
	lvl[v] = level;
	p[0][v] = pr;
	for (int i = 1; i < MAXL; ++i)
		p[i][v] = p[i - 1][p[i - 1][v]];

	for (const int& v2 : g[v]) {
		dfs(v2, level + 1, v);
	}
}

inline int getit(int v, int k) {
	if (h[k][v] != -1) return h[k][v];
	return h[k][v] = getit(p[k - 1][v], k - 1) + getit(v, k - 1);
}

inline int get(int v, int k) {
	if (k < 0) return 0;
	int res = 0;
	for (int i = MAXL - 1; i >= 0; --i) {
		if ((k & (1 << i)) > 0) {
			res += getit(v, i);
			k ^= (1 << i);
			v = p[i][v];
		}
	}
	return res;
}

void go(int v = 0) {
	for (const int& v2 : g[v]) {
		go(v2);
		d[v][0] += max(d[v2][0], d[v2][1]);
	}
	for (const int& v2 : g[v]) {
		h[0][v2] = d[v][0] - max(d[v2][0], d[v2][1]);
	}
	for (const auto& t : f[v]) {
		int cost = t.f;
		int v1 = t.s.f;
		int v2 = t.s.s;
		int w =  -d[v][0] + get(v1, lvl[v1] - lvl[v]) + get(v2, lvl[v2] - lvl[v]) + d[v1][0] + d[v2][0] + cost;
		d[v][1] = max(d[v][1], w);
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	memset(h, -1, sizeof(h));

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		int t;
		scanf("%d", &t);
		--t;
		g[t].pb(i + 1);
	}

	dfs();

	for (int i = 0; i < m; ++i) {
		int v1, v2, cost;
		scanf("%d%d%d", &v1, &v2, &cost);
		--v1, --v2;
		int lcav = lca(v1, v2);
		f[lcav].pb(mp(cost, mp(v1, v2)));
	}

	go();

	printf("%d\n", max(d[0][0], d[0][1]));

	return 0;
}