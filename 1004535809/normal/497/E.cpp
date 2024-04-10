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
const int MAXK = 30;
const int LOG_N = 60;
const int MOD = 1e9 + 7;
const ll INF = 1.5e18;
ll n; int k;
struct mat {
	int a[MAXK + 5][MAXK + 5];
	mat() {memset(a, 0, sizeof(a));}
	mat operator * (const mat &rhs) {
		mat res;
		for (int i = 0; i <= k; i++) for (int j = 0; j <= k; j++) for (int l = 0; l <= k; l++)
			res.a[i][j] = (res.a[i][j] + 1ll * a[i][l] * rhs.a[l][j]) % MOD;
		return res;
	}
} pw[MAXK + 5][LOG_N + 2], pre[MAXK + 5][LOG_N + 2], suf[MAXK + 5][LOG_N + 2];
int main() {
	scanf("%lld%d", &n, &k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= k; j++) pw[i][0].a[j][j] = 1;
		for (int j = 0; j <= k; j++) pw[i][0].a[j][i] = 1;
	}
	pre[0][0] = pw[0][0];
	for (int j = 1; j < k; j++) pre[j][0] = pre[j - 1][0] * pw[j][0];
	suf[k - 1][0] = pw[k - 1][0];
	for (int j = k - 2; ~j; j--) suf[j][0] = pw[j][0] * suf[j + 1][0];
	ll cpw = 1; int lg = 0;
	while (cpw <= INF / k) lg++, cpw *= k;
	for (int i = 1; i <= lg; i++) {
		for (int j = 0; j < k; j++) {
			pw[j][i] = suf[j][i - 1];
			if (j) pw[j][i] = pw[j][i] * pre[j - 1][i - 1];
		}
		pre[0][i] = pw[0][i];
		for (int j = 1; j < k; j++) pre[j][i] = pre[j - 1][i] * pw[j][i];
		suf[k - 1][i] = pw[k - 1][i];
		for (int j = k - 2; ~j; j--) suf[j][i] = pw[j][i] * suf[j + 1][i];
	}
	mat trs;
	for (int i = 0; i <= k; i++) trs.a[i][i] = 1;
	static int b[LOG_N + 2], len = 0;
	while (n) b[len++] = n % k, n /= k;
//	for (int i = 0; i < len; i++) printf("%d%c", b[i], " \n"[i == len - 1]);
	int cur = 0;
	for (int i = len - 1; ~i; i--) {
		for (int j = 0; j < b[i]; j++) {
			trs = trs * pw[cur][i];
			cur = (cur + 1) % k;
		}
	}
	int res = 1;
	for (int i = 0; i < k; i++) res = (res + trs.a[k][i]) % MOD;
	printf("%d\n", res);
	return 0;
}