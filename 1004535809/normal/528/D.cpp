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
const int MAXN = 2e5;
const int MAXP = 1 << 19;
const double Pi = acos(-1);
char s[MAXN + 5], t[MAXN + 5];
int n, m, k, res[MAXN + 5], d[MAXN + 5];
struct comp {
	double x, y; //(real, imag)
	comp(double _x = 0, double _y = 0) {x = _x; y = _y;}
	friend comp operator + (comp lhs, comp rhs) {return comp(lhs.x + rhs.x, lhs.y + rhs.y);}
	friend comp operator - (comp lhs, comp rhs) {return comp(lhs.x - rhs.x, lhs.y - rhs.y);}
	friend comp operator * (comp lhs, comp rhs) {return comp(lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x);}
} A[MAXP + 5], B[MAXP + 5];
int rev[MAXP + 5];
void FFT(comp *a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (rev[i] < i) swap(a[rev[i]], a[i]);
	for (int i = 2; i <= len; i <<= 1) {
		comp W(cos(2 * Pi / i), type * sin(2 * Pi / i));
		for (int j = 0; j < len; j += i) {
			comp w(1, 0);
			for (int k = 0; k < (i >> 1); k++, w = w * W) {
				comp X = a[j + k], Y = a[(i >> 1) + j + k] * w;
				a[j + k] = X + Y; a[(i >> 1) + j + k] = X - Y;
			}
		}
	}
	if (!~type)
		for (int i = 0; i < len; i++) a[i].x = (int)(a[i].x / len + 0.5);
}
void solve(char c) {
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) if (s[i] == c) {
		int l = max(i - k, 1), r = min(i + k, n);
		d[r + 1]--; d[l]++;
	}
	int LEN = 1; while (LEN <= n + m) LEN <<= 1;
	for (int i = 0; i < LEN; i++) A[i] = B[i] = comp(0, 0);
	for (int i = 1; i <= n; i++) d[i] += d[i - 1];
	for (int i = 1; i <= n; i++) if (d[i]) A[i] = comp(1, 0);
	for (int i = 1; i <= m; i++) B[i].x = (t[i] == c); reverse(B + 1, B + m + 1);
	FFT(A, LEN, 1); FFT(B, LEN, 1);
	for (int i = 0; i < LEN; i++) A[i] = A[i] * B[i];
	FFT(A, LEN, -1);
	for (int i = 1; i <= n - m + 1; i++) res[i] += A[i + m].x;
}
int main() {
	scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
	solve('A'); solve('C'); solve('G'); solve('T');
	int ans = 0; for (int i = 1; i <= n - m + 1; i++) ans += (res[i] == m);
	printf("%d\n", ans);
	return 0;
}