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
const int MAXN = 2e5;
int n, m, qu, a[MAXN + 5], b[MAXN + 5];
vector<pii> ps[MAXN + 5];
struct node {int l, r; ll mn, lz;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].mn = b[l - 1], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void tag(int k, ll v) {s[k].mn += v; s[k].lz += v;}
void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
ll mn[MAXN + 5];
multiset<ll> st;
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1; i < n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		ps[u].pb(mp(v, w));
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		for (pii p : ps[i]) modify(1, 1, p.fi, p.se);
		mn[i] = s[1].mn; st.insert(mn[i] + a[i]);
	}
	printf("%lld\n", *st.begin());
	while (qu--) {
		int x, v; scanf("%d%d", &x, &v);
		st.erase(st.find(mn[x] + a[x]));
		a[x] = v; st.insert(mn[x] + a[x]);
		printf("%lld\n", *st.begin());
	}
	return 0;
}