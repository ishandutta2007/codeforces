#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
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
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 4e5 + 5;
const int K = 20;
const int S = 26;
struct SAM {
	int cnt = 1, las = 1, son[N][S], len[N], fa[N];
	void ins(char s) {
		int it = s - 'a', p = las, cur = ++cnt;
		len[cur] = len[p] + 1, las = cur;
		while(!son[p][it]) son[p][it] = cur, p = fa[p];
		if(!p) return fa[cur] = 1, void();
		int q = son[p][it];
		if(len[p] + 1 == len[q]) return fa[cur] = q, void();
		int cl = ++cnt; cpy(son[cl], son[q], S);
		len[cl] = len[p] + 1, fa[cl] = fa[q], fa[q] = fa[cur] = cl;
		while(son[p][it] == q) son[p][it] = cl, p = fa[p];
	} int find(int x) {return x == 1 ? 1 : len[x] - len[fa[x]];}
} ori, rev;

char s[N]; vint e[N], G[N];
int n, dn, dfn[N], re[N], dep[N], lg[N], mi[K][N];
int get(int u, int v) {return dfn[u] < dfn[v] ? u : v;}
void dfs(int id) {
	mi[0][dfn[id] = ++dn] = id, re[dn] = id, dep[id] = rev.len[id];
	for(int it : e[id]) dfs(it), mi[0][++dn] = id;
}
int lca(int u, int v) {
	if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
	int d = lg[v - u + 1];
	return get(mi[d][u], mi[d][v - (1 << d) + 1]);
} int dis(int u, int v) {return u && v ? dep[u] + dep[v] - (dep[lca(u, v)] << 1) : 0;}

int node, pre[N << 5], suf[N << 5], ls[N << 5], rs[N << 5];
ll ans, val[N << 5];
void push(int x) {
	val[x] = val[ls[x]] + val[rs[x]] + dis(re[suf[ls[x]]], re[pre[rs[x]]]);
	pre[x] = min(pre[ls[x]], pre[rs[x]]), suf[x] = max(suf[ls[x]], suf[rs[x]]);
}
void modify(int l, int r, int p, int &x) {
	x = ++node, pre[x] = suf[x] = p;
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	ls[x] = merge(ls[x], ls[y]);
	rs[x] = merge(rs[x], rs[y]);
	return push(x), x;
}

int pos[N], R[N];
void dfs2(int id) {
	for(int it : G[id]) dfs2(it), R[id] = merge(R[id], R[it]);
	if(!R[id]) return;
	int tot = dis(1, re[pre[R[id]]]) + dis(1, re[suf[R[id]]]);
	ans += 1ll * ori.find(id) * (val[R[id]] + tot >> 1);
}
bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> s + 1, n = strlen(s + 1), pre[0] = N - 1;
	for(int i = 1; i <= n; i++) ori.ins(s[i]), rev.ins(s[n - i + 1]);
	for(int i = 2; i < N << 1; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 2; i <= rev.cnt; i++) e[rev.fa[i]].pb(i);
	for(int i = 2; i <= ori.cnt; i++) G[ori.fa[i]].pb(i), ans += ori.find(i) * 2;
	for(int i = n, p = 1; i; i--) pos[i] = p = rev.son[p][s[i] - 'a'];
	for(int i = (dfs(1), 1); i <= lg[dn]; i++)
		for(int j = 1; j + (1 << i) - 1 <= dn; j++)
			mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
	modify(1, dn, dfn[pos[2]], R[1]);
	for(int i = 1, p = 1; i + 1 < n; i++) modify(1, dn, dfn[pos[i + 2]], R[p = ori.son[p][s[i] - 'a']]);
	dfs2(1), cout << ans - ori.find(ori.las) + 2 << endl;
	return flush(), 0;
}