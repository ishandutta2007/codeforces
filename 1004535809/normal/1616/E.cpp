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
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n; char s[MAXN + 5], t[MAXN + 5];
namespace segtree {
	struct node {int l, r, mn, cnt;} s[MAXN * 4 + 5];
	void pushup(int k) {
		s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
		s[k].cnt = s[k << 1].cnt + s[k << 1 | 1].cnt;
	}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; if (l == r) return s[k].mn = :: s[l], s[k].cnt = 1, void();
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		pushup(k);
	}
	void turnoff(int k, int p) {
		if (s[k].l == s[k].r) return s[k].mn = 1e9, s[k].cnt = 0, void();
		int mid = s[k].l + s[k].r >> 1;
		if (p <= mid) turnoff(k << 1, p);
		else turnoff(k << 1 | 1, p);
		pushup(k);
	}
	int query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].cnt;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
	}
	int walk(int k, int v) {
		if (s[k].mn > v) return n + 1;
		if (s[k].l == s[k].r) return s[k].l;
		if (s[k << 1].mn <= v) return walk(k << 1, v);
		else return walk(k << 1 | 1, v);
	}
}
using segtree :: build;
using segtree :: query;
using segtree :: walk;
using segtree :: turnoff;
void solve() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	build(1, 1, n); ll res = INFll, sum = 0;
	for (int i = 1; i <= n; i++) {
		int pos = walk(1, t[i] - 1);
		if (pos != n + 1) chkmin(res, sum + query(1, 1, pos) - 1);
		pos = walk(1, t[i]);
//		printf("%d\n", pos);
		if (pos == n + 1) break;
		else if (s[pos] == t[i]) {
			sum += query(1, 1, pos) - 1;
			turnoff(1, pos);
		} else break;
	}
	printf("%lld\n", (res == INFll) ? -1 : res);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
5
ecabd
abced

1
5
adbba
abbeb
*/