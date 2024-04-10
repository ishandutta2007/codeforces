#include <bits/stdc++.h> ////////////////////////
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return x = sgn ? -x : x;
	}
	template <typename T>
	inline void recprint(T x) {if(x >= 10) recprint(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; recprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 1e5 + 5;
const int K = 17;
int cnt, hd[N], nxt[N << 1], to[N << 1], val[N << 1];
void add(int u, int v, int w) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, val[cnt] = w;}

int n, m, u, v, lg;
void dfs(int id, int f, ll *dis) {
	for(int i = hd[id]; i; i = nxt[i]) {
		int it = to[i]; if(it == f) continue;
		dis[it] = dis[id] + val[i], dfs(it, id, dis);
	}
}
void find() {
	static ll dis[N]; dis[0] = dis[1] = 0, dfs(1, 0, dis);
	for(int i = 1; i <= n; i++) if(dis[i] > dis[u]) u = i;
	dis[u] = 0, dfs(u, 0, dis);
	for(int i = 1; i <= n; i++) if(dis[i] > dis[v]) v = i;
}

struct Tree {
	int r, c, son[N], top[N], tag[N], fa[K][N];
	ll len[N], dep[N], mx[N], mxd[N], vv[N], ans[N];
	vint leaf;
	void dfs1(int id, int f) {
		fa[0][id] = f;
		for(int i = 1; i <= lg; i++)
			fa[i][id] = fa[i - 1][fa[i - 1][id]];
		for(int i = hd[id]; i; i = nxt[i]) {
			int it = to[i];
			if(it == f) continue;
			dep[it] = dep[id] + val[i], dfs1(it, id);
			if(len[it] + val[i] > len[id])
				len[id] = len[it] + val[i], vv[id] = val[i], son[id] = it;
		}
		if(len[id] == 0) leaf.pb(id);
	}
	void dfs2(int id, int tp) {
		top[id] = tp;
		if(son[id]) mx[son[id]] = mx[id] + vv[id], dfs2(son[id], tp);
		for(int i = hd[id]; i; i = nxt[i]) {
			int it = to[i];
			if(it == fa[0][id] || it == son[id]) continue;
			mx[it] = val[i], dfs2(it, it);
		}
	}
	void build(int _root) {
		r = _root, dfs1(r, 0), dfs2(r, r), c = leaf.size();
		sort(all(leaf), [&](int a, int b) {return mx[a] > mx[b];});
		for(int i = 1; i <= c; i++) {
			int u = leaf[i - 1], tp = top[u];
			ans[i] = ans[i - 1] + mx[u];
			while(top[u] == tp) tag[u] = i, u = fa[0][u];
		}
	}
	ll query(int x, int y) {
		y = y * 2 - 1;
		if(y >= c) return ans[c];
		if(tag[x] <= y) return ans[y];
		ll u = x, res = 0;
		for(int i = lg; ~i; i--) if(tag[fa[i][u]] >= y) u = fa[i][u];
		u = fa[0][u], res = ans[y - 1] - dep[u] + len[x] + dep[x], u = x;
		for(int i = lg; ~i; i--) if(tag[fa[i][u]] > y) u = fa[i][u]; u = fa[0][u];
		return max(res, ans[y] - len[u] + (dep[x] - dep[u]) + len[x]);
	}
} T1, T2;

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m, lg = log2(n);
	if(n == 1) {while(m--) puts("0"); exit(0);}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read(), w = read();
		add(u, v, w), add(v, u, w);
	} find(), T1.build(u), T2.build(v);
	for(ll i = 1, x, y, las = 0; i <= m; i++) {
		x = (read() + las - 1) % n + 1;
		y = (read() + las - 1) % n + 1;
		print(las = max(T1.query(x, y), T2.query(x, y))), pc('\n');
	} 
	return flush(), 0;
} ////