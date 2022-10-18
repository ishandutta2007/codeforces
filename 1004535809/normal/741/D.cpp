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
		if (x<0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 5e5;
const int MAXP = 1 << 22;
const int INF = 0x3f3f3f3f;
int n, hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], val[MAXN + 5], ec = 0;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
int msk[MAXN + 5], siz[MAXN + 5], wson[MAXN + 5], dep[MAXN + 5];
void dfs0(int x) {
	siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e], z = val[e]; msk[y] = msk[x] ^ z;
		dep[y] = dep[x] + 1; dfs0(y); siz[x] += siz[y];
		if (siz[y] > siz[wson[x]]) wson[x] = y;
	}
}
int mx[MAXP + 5], res[MAXN + 5];
void clr(int x) {
	mx[msk[x]] = -INF;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; clr(y);
	}
}
void push(int x, int v) {
	chkmax(res[v], dep[x] + mx[msk[x]] - (dep[v] << 1));
	for (int i = 0; i < 22; i++) chkmax(res[v], dep[x] + mx[msk[x] ^ (1 << i)] - (dep[v] << 1));
}
void dfspush(int x, int v) {
	push(x, v);
	for (int e = hd[x]; e; e = nxt[e]) dfspush(to[e], v);
}
void dfsadd(int x) {
	chkmax(mx[msk[x]], dep[x]);
	for (int e = hd[x]; e; e = nxt[e]) dfsadd(to[e]);
}
void dfs1(int x) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == wson[x]) continue;
		dfs1(y); clr(y);
	}
	if (wson[x]) dfs1(wson[x]);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == wson[x]) continue;
		dfspush(y, x); dfsadd(y);
	}
	push(x, x); chkmax(mx[msk[x]], dep[x]);
}
void dfs2(int x) {
	for (int e = hd[x]; e; e = nxt[e]) {
		dfs2(to[e]); chkmax(res[x], res[to[e]]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 2, fa; i <= n; i++) {
		static char opt[5]; scanf("%d%s", &fa, opt + 1);
		adde(fa, i, (1 << (opt[1] - 'a')));
	}
	dfs0(1); memset(mx, 192, sizeof(mx)); dfs1(1); dfs2(1); //puts("-1");
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	return 0;
}