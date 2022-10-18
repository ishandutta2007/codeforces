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
using namespace fastio;
const int MAXN = 5e5;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], val[MAXN * 2 + 5], ec = 1;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
int d1[MAXN + 5], d2[MAXN + 5];
void dfs(int x, int f, int *d) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		d[y] = d[x] + 1; dfs(y, x, d);
	}
}
int rt1, rt2;
struct solver {
	int rt;
	int dw[MAXN + 5], dep[MAXN + 5], num[MAXN + 5];
	int dfn[MAXN + 5], edt[MAXN + 5], tim = 0, rid[MAXN + 5];
	void dfs0(int x, int f) {
		rid[dfn[x] = ++tim] = x;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = val[e]; if (y == f) continue;
			dw[e >> 1] = y; dep[y] = dep[x] + 1; num[y] = num[x] ^ z;
			dfs0(y, x);
		}
		edt[x] = tim;
	}
	struct node {int l, r, mx[2], lz;} s[MAXN * 4 + 5];
	void pushup(int k) {
		s[k].mx[0] = max(s[k << 1].mx[0], s[k << 1 | 1].mx[0]);
		s[k].mx[1] = max(s[k << 1].mx[1], s[k << 1 | 1].mx[1]);
	}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; if (l == r) return s[k].mx[num[rid[l]]] = dep[rid[l]], void();
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r); pushup(k);
	}
	void tag(int k) {swap(s[k].mx[0], s[k].mx[1]); s[k].lz ^= 1;}
	void pushdown(int k) {if (s[k].lz) tag(k << 1), tag(k << 1 | 1), s[k].lz = 0;}
	void modify(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return tag(k), void();
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) modify(k << 1, l, r);
		else if (l > mid) modify(k << 1 | 1, l, r);
		else modify(k << 1, l, mid), modify(k << 1 | 1, mid + 1, r);
		pushup(k);
	}
	void flip(int id) {modify(1, dfn[dw[id]], edt[dw[id]]);}
	void init(int r) {rt = r; dfs0(rt, 0); build(1, 1, n);}
} S[2];
int main() {
	read(n);
	for (int i = 1, u, v, w; i < n; i++) {
		read(u); read(v); read(w);
		adde(u, v, w); adde(v, u, w);
	}
	dfs(1, 0, d1); rt1 = 1;
	for (int i = 2; i <= n; i++) if (d1[i] > d1[rt1]) rt1 = i;
	dfs(rt1, 0, d2); rt2 = rt1;
	for (int i = 1; i <= n; i++) if (d2[i] > d2[rt2]) rt2 = i;
	S[0].init(rt1); S[1].init(rt2); int qu; read(qu);
//	for (int i = 1; i < n; i++) printf("%d%c", S[0].dw[i], " \n"[i == n - 1]);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", S[0].dfn[i], S[0].edt[i]);
//	for (int i = 1; i < n; i++) printf("%d%c", S[1].dw[i], " \n"[i == n - 1]);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", S[1].dfn[i], S[1].edt[i]);
//	printf("%d\n", max(S[0].s[1].mx[0], S[1].s[1].mx[0]));
	while (qu--) {
		int id; read(id); S[0].flip(id); S[1].flip(id);
		print(max(S[0].s[1].mx[0], S[1].s[1].mx[0]), '\n');
	}
	print_final();
	return 0;
}