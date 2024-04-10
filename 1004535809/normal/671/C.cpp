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
int n, a[MAXN + 5], b[MAXN + 5], buc[MAXN + 5], lst[MAXN + 5];
vector<int> fac[MAXN + 5];
void calc_f1() {
	multiset<int> st; st.insert(0);
	for (int i = n; i; i--) {
		b[i] = *st.rbegin();
		for (int f : fac[i]) {
			buc[f]++;
			if (!lst[f]) lst[f] = i;
			if (buc[f] == 2) st.insert(f);
		}
	}
}
struct node {int l, r, rit, lz; ll sum;} s[MAXN * 4 + 5];
void pushup(int k) {
	s[k].rit = s[k << 1 | 1].rit;
	s[k].sum = s[k << 1].sum + s[k << 1 | 1].sum;
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].rit = s[k].sum = b[l], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void tag(int k, int v) {
	s[k].rit = s[k].lz = v;
	s[k].sum = 1ll * (s[k].r - s[k].l + 1) * v;
}
void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
ll query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].sum;
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
}
int findle(int k, int p) { // find the first position < p
	if (s[k].l == s[k].r) return (s[k].rit < p) ? (s[k].l) : (s[k].l + 1);
	pushdown(k);
	if (s[k << 1].rit < p) return findle(k << 1, p);
	else return findle(k << 1 | 1, p);
}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
void makemax(int l, int r, int v) {
	int pos = findle(1, v);
	if (pos <= r) modify(1, pos, r, v);
}
int main() {
	scanf("%d", &n); ll res = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j * j <= a[i]; j++) if (a[i] % j == 0) {
			fac[i].pb(j);
			if (a[i] / j != j) fac[i].pb(a[i] / j);
		}
	}
	calc_f1(); build(1, 1, n); memset(buc, 0, sizeof(buc));
	for (int i = 1; i <= n; i++) {
		res += query(1, i, n);
		for (int f : fac[i]) {
			if (buc[f]) makemax(1, n, f);
			if (lst[f] != i) makemax(1, lst[f] - 1, f);
			buc[f] = 1;
		}
	}
	printf("%lld\n", res);
	return 0;
}