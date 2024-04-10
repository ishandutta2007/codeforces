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
int n, qu, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], val[MAXN * 2 + 5], ec = 0;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
ll d_sub[MAXN + 5], d_out[MAXN + 5], d[MAXN + 5];
int ord[MAXN + 5];
void dfs1(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e], z = val[e]; if (y == f) continue;
		dfs1(y, x); chkmax(d_sub[x], d_sub[y] + z);
	}
}
void dfs2(int x, int f) {
	multiset<ll> st;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e], z = val[e];
		if (y == f) st.insert(d_out[x]);
		else st.insert(d_sub[y] + z);
	}
	st.insert(0);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e], z = val[e]; if (y == f) continue;
		st.erase(st.find(d_sub[y] + z)); d_out[y] = (*st.rbegin()) + z;
		dfs2(y, x); st.insert(d_sub[y] + z);
	}
}
int fa[MAXN + 5];
void dfs_f(int x, int f) {
	fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs_f(y, x);
	}
}
int f[MAXN + 5], siz[MAXN + 5], res;
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y); f[x] = y;
	siz[y] += siz[x]; chkmax(res, siz[y]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w); adde(v, u, w);
	}
	dfs1(1, 0); dfs2(1, 0);
	for (int i = 1; i <= n; i++) d[i] = max(d_sub[i], d_out[i]), ord[i] = i;
	sort(ord + 1, ord + n + 1, [&](int x, int y) {return d[x] < d[y];});
//	for (int i = 1; i <= n; i++) printf("%lld%c", d[i], " \n"[i == n]);
	dfs_f(ord[1], 0); scanf("%d", &qu);
//	for (int i = 1; i <= n; i++) printf("%d%c", fa[i], " \n"[i == n]);
	while (qu--) {
		ll L; scanf("%lld", &L); res = 0;
		for (int i = 1; i <= n; i++) f[i] = 0, siz[i] = 1;
		for (int i = n, j = n; i >= 1; i--) {
			while (j >= 1 && d[ord[i]] - d[ord[j]] <= L) {
				for (int e = hd[ord[j]]; e; e = nxt[e]) {
					int p = to[e];
					if (p != fa[ord[j]]) merge(p, ord[j]);
				}
				j--;
			}
			siz[find(ord[i])]--;
		}
		printf("%d\n", res);
	}
	return 0;
}