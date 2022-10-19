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

const int mod[2] = {1000000007, 1000000009}, N = 300015, base = 114;

int n, q, up[2][N], down[2][N], dep[N], fa[N][19], pd[2][N], ipd[2][N];
char s[N];
vector<int> e[N];

int qpow(int a, int b, int md) {
	int res = 1;

	while (b) {
		if (b & 1) res = (ll) res * a % md;

		a = (ll) a * a % md;
		b >>= 1;
	}

	return res;
}

void init() {
	rep(p, 0, 1) {
		pd[p][0] = ipd[p][0] = 1;
		int iv = qpow(base, mod[p] - 2, mod[p]);
		rep(i, 1, n) {
			pd[p][i] = (ll) pd[p][i - 1] * base % mod[p];
			ipd[p][i] = (ll) ipd[p][i - 1] * iv % mod[p];
		}
	}
}

int son[N], dis[N], top[N];

vector<int> cf[N], cs[N];

void dfs(int u, int pa) {
	fa[u][0] = pa; dep[u] = dep[pa] + 1;
	rep(j, 1, 18) fa[u][j] = fa[fa[u][j - 1]][j - 1];
	rep(p, 0, 1) {
		up[p][u] = ((ll) up[p][pa] * base + s[u]) % mod[p];
		down[p][u] = ((ll) pd[p][dep[u]] * s[u] + down[p][pa]) % mod[p];
	}

	for (int v : e[u]) {
		if (v == pa) continue;

		dfs(v, u);

		if (!son[u] || dis[v] > dis[son[u]]) {
			// fprintf(stderr, "%d %d\n", son[u], v);
			dis[u] = dis[son[u] = v] + 1;
		}
	}
}

void dfs2(int u, int pa, int tp) {

	top[u] = tp;

	if (son[u]) dfs2(son[u], u, tp);

	for (int v : e[u]) {
		if (v == pa || v == son[u]) continue;

		dfs2(v, u, v);
	}

	if (u == tp) {
		int f = u, s = u;

		cf[u].resize(dis[u] + 1);
		cs[u].resize(dis[u] + 1);

		// printf("line %d\n", u);

		rep(_, 0, dis[u]) {
			// printf("(%d %d)\n", f, s);
			cf[u][_] = f;
			cs[u][_] = s;
			f = fa[f][0];
			s = son[s];
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);

	int t = dep[u] - dep[v];

	rep(j, 0, 18) if (t >> j & 1) u = fa[u][j];

	if (u == v) return u;

	per(j, 0, 18) if (fa[u][j] != fa[v][j]) {
		u = fa[u][j];
		v = fa[v][j];
	}

	return fa[u][0];
}

int kth(int u, int k) {
	if (!k) return u;

	int kk = 31 - __builtin_clz(k);

	u = fa[u][kk]; k -= (1 << kk);

	// fprintf(stderr, "!!! %d %d %d\n", u, k, kk);

	if (!u) return u;

	if (dep[u] - k <= dep[top[u]])
		return cf[top[u]][dep[top[u]] - dep[u] + k];
	else
		return cs[top[u]][dep[u] - k - dep[top[u]]];
}

int calc(int u, int l, int v, int len) {
	int o = dep[u] - dep[l] + 1;

	if (len <= o) {
		int uu = kth(u, len);
		// return mp((up[0][u] - (ll) up[0][uu] * pd[0][len] % mod[0] + mod[0]) % mod[0],
		//           (up[1][u] - (ll) up[1][uu] * pd[1][len] % mod[1] + mod[1]) % mod[1]);
		return (up[0][u] - (ll) up[0][uu] * pd[0][len] % mod[0] + mod[0]) % mod[0];

	} else {
		int vv = kth(v, dep[v] - dep[l] - len + o), oo = - dep[vv] + len - 1;

		// printf("!! vv %d (%d %d %d %d) \n", vv, (up[1][u] - (ll) up[1][fa[l][0]] * pd[1][o] % mod[1] + mod[1]) % mod[1], (ll)(down[1][vv] + mod[1] - down[1][l]) % mod[1] , oo, (oo > 0 ? pd[1][oo] : ipd[1][-oo]) % mod[1]);

		// return mp(
		//            ((up[0][u] - (ll) up[0][fa[l][0]] * pd[0][o] % mod[0] + mod[0]) % mod[0]
		//             + (ll)(down[0][vv] + mod[0] - down[0][l]) % mod[0] * (oo > 0 ? pd[0][oo] : ipd[0][-oo]) % mod[0]) % mod[0],
		//            ((up[1][u] - (ll) up[1][fa[l][0]] * pd[1][o] % mod[1] + mod[1]) % mod[1]
		//             + (ll)(down[1][vv] + mod[1] - down[1][l]) % mod[1] * (oo > 0 ? pd[1][oo] : ipd[1][-oo]) % mod[1]) % mod[1]
		//        );
		return
		    ((up[0][u] - (ll) up[0][fa[l][0]] * pd[0][o] % mod[0] + mod[0]) % mod[0]
		     + (ll)(down[0][vv] + mod[0] - down[0][l]) % mod[0] * (oo > 0 ? pd[0][oo] : ipd[0][-oo]) % mod[0]) % mod[0];
	}
}

const int SZ = 1 << 25;
struct IO {
	char buf[SZ], *p1, *p2;
	char fub[SZ], *pp;
	IO() : p1(buf), p2(buf), pp(fub) {}
	~IO() {fwrite(fub, 1, pp - fub, stdout);}
	char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, SZ, stdin);

		return p1 == p2 ? ' ' : *p1++;
	}
	int read() {
		int x = 0;
		char ch = gc();

		while (!isdigit(ch)) ch = gc();

		while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'), ch = gc();

		return x;
	}
	void pc(char c) {
		if (pp - fub == SZ) fwrite(fub, 1, SZ, stdout), pp = fub;

		*pp++ = c;
	}
	void write(int x) {
		static int sta[25];

		if (x < 0) pc('-'), x = -x;

		int top = 0;

		do {
			sta[top++] = x % 10, x /= 10;
		} while (x);

		while (top) pc(sta[--top] + '0');
	}
} io;
int read() {return io.read();};
void write(int x) {io.write(x);};

int main() {
	// freopen("string.in", "r", stdin);
	// freopen("string.out", "w", stdout);
	clock_t st = clock();
	n = read();
	init();
	rep(i, 1, n) {
		do {
			s[i] = io.gc();
		} while (s[i] < 'a' || s[i] > 'z');
	}
	rep(i, 2, n) {
		int u = read(), v = read();
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1, 0);
	dfs2(1, 0, 1);
	q = read();
	rep(_, 1, q) {
		int a = read(), b = read(), c = read(), d = read();

		if (s[a] != s[c]) {
			io.pc('0'); io.pc('\n');
			continue;
		}

		int l1 = lca(a, b), l2 = lca(c, d);

		int len1 = dep[a] + dep[b] - 2 * dep[l1] + 1, len2 = dep[c] + dep[d] - 2 * dep[l2] + 1;

		int l = 0, r = min(len1, len2), ans = 0;

		while (l <= r) {
			int mid = (l + r) >> 1;

			// printf("mid %d: (%d %d) (%d %d)\n", mid, calc(a, l1, b, mid).fi, calc(a, l1, b, mid).se, calc(c, l2, d, mid).fi, calc(c, l2, d, mid).se);

			if (calc(a, l1, b, mid) == calc(c, l2, d, mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}

		write(ans); io.pc('\n');

	}
	cerr << clock() - st << endl;
	return 0;
}