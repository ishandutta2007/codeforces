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
const int MAXN = 80;
int n, k, mod, fac[MAXN + 5], ifac[MAXN + 5];
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % mod)
		if (e & 1) ret = 1ll * ret * x % mod;
	return ret;
}
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[mod % i] * (mod - mod / i) % mod;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % mod;
	}
}
int binom(int n, int k) {return 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod;}
int f[MAXN + 5][MAXN + 5], all[MAXN + 5][MAXN + 5], dp[MAXN + 5][MAXN + 5];
int pw2[MAXN * MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &k, &mod); init_fac(MAXN);
	for (int i = (pw2[0] = 1); i <= MAXN * MAXN; i++) pw2[i] = (pw2[i - 1] << 1) % mod;
	for (int j = 0; j <= k; j++) {
		int tot = pw2[j] - 1, prd = 1; f[0][j] = 1;
		for (int i = 1; i <= n; i++) {
			prd = 1ll * prd * (tot - i + 1) % mod;
			f[i][j] = prd;
		}
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) all[i][j] = pw2[i * j];
	for (int i = 0; i <= n; i++) for (int j = k; ~j; j--) {
		for (int l = 0; l < j; l++) {
			if ((j - l) & 1) {
				f[i][j] = (f[i][j] - 1ll * f[i][l] * binom(j, l) % mod + mod) % mod;
				all[i][j] = (all[i][j] - 1ll * all[i][l] * binom(j, l) % mod + mod) % mod;
			} else {
				f[i][j] = (f[i][j] + 1ll * f[i][l] * binom(j, l)) % mod;
				all[i][j] = (all[i][j] + 1ll * all[i][l] * binom(j, l)) % mod;
			}
		}
	}
//	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++)
//		printf("%d %d %d %d\n", i, j, f[i][j], all[i][j]);
	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++)
		for (int ii = 0; ii < i; ii++) for (int jj = 0; jj < j; jj++) {
			if ((n & 1) && (i == n) && (ii == i - 1)) continue;
			dp[i][j] = (dp[i][j] + 1ll * binom(i, ii) * binom(j, jj) % mod *
			pw2[(i - ii) * jj] % mod * f[i - ii][j - jj] % mod * (all[ii][jj] - dp[ii][jj] + mod)) % mod;
		}
	int res = 0;
	for (int i = 0; i <= k; i++) res = (res + 1ll * binom(k, i) * (all[n][i] - dp[n][i] + mod)) % mod;
	printf("%d\n", res);
	return 0;
}