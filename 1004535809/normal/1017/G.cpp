#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;
int n, qu, hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int fa[MAXN + 5], siz[MAXN + 5], wson[MAXN + 5], dep[MAXN + 5];
int top[MAXN + 5], dfn[MAXN + 5], edt[MAXN + 5], tim = 0;
void dfs1(int x) {
	siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; dep[y] = dep[x] + 1; dfs1(y); siz[x] += siz[y];
		if (siz[y] > siz[wson[x]]) wson[x] = y;
	}
}
void dfs2(int x, int tp) {
	top[x] = tp; dfn[x] = ++tim; if (wson[x]) dfs2(wson[x], tp);
	for (int e = hd[x]; e; e = nxt[e]) if (to[e] != wson[x]) dfs2(to[e], to[e]);
	edt[x] = tim;
}
struct dat {
	int sum, mxsuf;
	dat() {sum = mxsuf = 0;}
	friend dat operator + (dat x, dat y) {
		dat res; res.sum = x.sum + y.sum;
		res.mxsuf = max(y.mxsuf, y.sum + x.mxsuf);
		return res;
	}
};
struct node {int l, r, tg; dat v;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].v = s[k << 1].v + s[k << 1 | 1].v;}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].v.sum = s[k].v.mxsuf = -1, void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r); pushup(k);
}
void tag(int k) {s[k].tg = 1; s[k].v.sum = -(s[k].r - s[k].l + 1); s[k].v.mxsuf = -1;}
void pushdown(int k) {if (s[k].tg) tag(k << 1), tag(k << 1 | 1), s[k].tg = 0;}
void assign(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return tag(k), void(); pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) assign(k << 1, l, r); else if (l > mid) assign(k << 1 | 1, l, r);
	else assign(k << 1, l, mid), assign(k << 1 | 1, mid + 1, r); pushup(k);
}
void modify(int k, int p, int v) {
	if (s[k].l == s[k].r) return s[k].v.sum += v, s[k].v.mxsuf += v, void(); pushdown(k);
	int mid = s[k].l + s[k].r >> 1; (p <= mid) ? modify(k << 1, p, v) : modify(k << 1 | 1, p, v); pushup(k);
}
dat query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].v; pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r); else if (l > mid) return query(k << 1 | 1, l, r);
	else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
}
int askmx(int x) {
	int csum = 0, mx = -INF;
	while (x) {
		dat D = query(1, dfn[top[x]], dfn[x]);
		chkmax(mx, csum + D.mxsuf); csum += D.sum;
		x = fa[top[x]];
	}
//	printf("%d\n", mx);
	return mx;
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 2; i <= n; i++) scanf("%d", &fa[i]), adde(fa[i], i);
	dfs1(1); dfs2(1, 1); build(1, 1, n);
//	for (int i = 1; i <= n; i++) printf("%d%c", top[i], " \n"[i == n]);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", dfn[i], edt[i]);
	while (qu--) {
		int opt, x; scanf("%d%d", &opt, &x);
		if (opt == 1) modify(1, dfn[x], 1);
		else if (opt == 2) {
			if (dfn[x] != edt[x]) assign(1, dfn[x] + 1, edt[x]);
			modify(1, dfn[x], -(askmx(x) + 1));
		} else printf("%s\n", (askmx(x) >= 0) ? "black" : "white");
	}
	return 0;
}