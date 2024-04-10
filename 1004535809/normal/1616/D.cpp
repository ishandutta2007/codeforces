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
const int MAXN = 5e4;
const int LOG_N = 18;
int n, a[MAXN + 5], x, pos[MAXN + 5], mx[MAXN + 5], dp[MAXN + 5];
ll sum[MAXN + 5], st[MAXN + 5][LOG_N + 2];
ll query(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &x);
	for (int i = 1; i <= n; i++) a[i] -= x;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 0; i <= n; i++) st[i][0] = sum[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 0; j + (1 << i) - 1 <= n; j++)
		st[j][i] = max(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
//	for (int i = 1; i <= n; i++) printf("%lld%c", sum[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i - 2, p = i - 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(mid, i - 2) <= sum[i]) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		pos[i] = p;
	}
	for (int i = 1; i <= n; i++) chkmax(pos[i], pos[i - 1]);
//	for (int i = 1; i <= n; i++) printf("%d%c", pos[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) {
		dp[i] = mx[max(pos[i] - 1, 0)] + i - pos[i];
		mx[i] = max(mx[i - 1], dp[i]);
	}
	printf("%d\n", mx[n]);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}