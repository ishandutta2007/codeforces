#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
#ifdef FASTIO
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
#endif
const int MAXN = 2e5;
int n, a[MAXN + 5], hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int mx[MAXN + 5], mx_out[MAXN + 5], fa[MAXN + 5];
void dfs1(int x, int f) {
	mx[x] = a[x]; fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs1(y, x); chkmax(mx[x], mx[y]);
	}
}
void dfs2(int x, int f) {
	multiset<int> st; st.insert(a[x]);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) st.insert(mx_out[x]);
		else st.insert(mx[y]);
	}
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; st.erase(st.find(mx[y]));
		mx_out[y] = *st.rbegin(); dfs2(y, x); st.insert(mx[y]);
	}
}
bool ban[MAXN + 5]; int R, mson[MAXN + 5];
void dfs3(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs3(y, x); chkmax(a[x], a[y]);
		if (a[y] > a[mson[x]]) mson[x] = y;
	}
}
ll sum = 0;
void dfs4(int x, int tp, int f) {
	if (x == tp) sum += a[x];
	if (mson[x]) dfs4(mson[x], tp, x);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f || y == mson[x]) continue;
		dfs4(y, y, x);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs1(1, 0); dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e];
			if (y == fa[i]) cnt += (mx_out[i] >= a[i]);
			else cnt += (mx[y] >= a[i]);
		}
		ban[i] = (cnt >= 2);
	}
	int mx = 0; for (int i = 1; i <= n; i++) chkmax(mx, a[i]);
	for (int i = 1; i <= n; i++) if (!ban[i] && a[i] == mx) R = i;
	dfs3(R, 0); dfs4(R, R, 0); int mxx = 0;
	for (int e = hd[R]; e; e = nxt[e]) {
		int y = to[e]; if (y == mson[R]) continue;
		chkmax(mxx, a[y]);
	}
	sum += a[R] - mxx; printf("%lld\n", sum);
	return 0;
}