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
const int MAXN = 3e5;
const int MOD = 1e9 + 9;
int n, qu, a[MAXN + 5], sa[MAXN + 5], F[MAXN + 5];
int fib(int k) {return (k < 0) ? ((k & 1) ? (F[-k]) : (MOD - F[-k])) : F[k];}
struct solver {
	int op;
	struct node {int l, r, sum, val, lz;} s[MAXN * 4 + 5];
	void pushup(int k) {s[k].val = (s[k << 1].val + s[k << 1 | 1].val) % MOD;}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; if (l == r) return s[k].sum = fib(l + op), void();
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		s[k].sum = (s[k << 1].sum + s[k << 1 | 1].sum) % MOD;
	}
	void tag(int k, int v) {
		s[k].lz = (s[k].lz + v) % MOD;
		s[k].val = (s[k].val + 1ll * v * s[k].sum) % MOD;
	}
	void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
	void modify(int k, int l, int r, int v) {
		if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) modify(k << 1, l, r, v);
		else if (l > mid) modify(k << 1 | 1, l, r, v);
		else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
		pushup(k);
	}
	int query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].val;
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return (query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r)) % MOD;
	}
} T[2];
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sa[i] = (sa[i - 1] + a[i]) % MOD;
	F[1] = F[2] = 1;
	for (int i = 3; i <= n + 1; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;
	T[0].op = 0; T[1].op = 1; T[0].build(1, 1, n); T[1].build(1, 1, n);
	while (qu--) {
		int opt, l, r; scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1) {
			T[0].modify(1, l, r, fib(-l));
			T[1].modify(1, l, r, fib(1 - l));
		} else {
			int res = (sa[r] - sa[l - 1] + MOD) % MOD;
			res = (res + T[0].query(1, l, r)) % MOD;
			res = (res + T[1].query(1, l, r)) % MOD;
			printf("%d\n", res);
		}
	}
	return 0;
}