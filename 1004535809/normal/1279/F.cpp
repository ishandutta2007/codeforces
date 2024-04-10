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
const int MAXN = 1e6;
int n, k, L; char s[MAXN + 5];
int val[MAXN + 5], sum[MAXN + 5], mx, mnc[MAXN + 5];
ll dp[MAXN + 5];
bool check(int mid) {
	memset(dp, 0, sizeof(dp)); memset(mnc, 0, sizeof(mnc));
	for (int i = 1; i <= n; i++) {
		ll A = dp[i - 1], B = dp[max(i - L, 0)] + sum[i] - sum[max(i - L, 0)] - mid;
		if (A > B) dp[i] = A, mnc[i] = mnc[i - 1];
		else if (B > A) dp[i] = B, mnc[i] = mnc[max(i - L, 0)] + 1;
		else dp[i] = A, mnc[i] = min(mnc[i - 1], mnc[max(i - L, 0)] + 1);
	}
//	printf("check %d %d\n", mid, mnc[n]);
	return (mnc[n] <= k) ? (mx = dp[n] + k * mid, 1) : 0;
}
int calc() {
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + val[i];
	mx = 0; int l = 0, r = n, p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
//	printf("! %d\n", p);
	check(p); return sum[n] - mx;
}
int main() {
	scanf("%d%d%d%s", &n, &k, &L, s + 1);
	for (int i = 1; i <= n; i++) val[i] = (s[i] <= 'Z');
	int res = calc();
	for (int i = 1; i <= n; i++) val[i] = (s[i] >= 'a');
	chkmin(res, calc());
	printf("%d\n", res);
	return 0;
}