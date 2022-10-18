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
const int MAXN = 300;
const int MOD = 1e9 + 7;
int n, a[MAXN + 5], f[MAXN + 5], siz[MAXN + 5];
int b[MAXN + 5], m;
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x ^ y) f[x] = y, siz[y] += siz[x];}
bool issqr(ll x) {int y = (int)sqrt(x); return 1ll * y * y == x;}
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int binom(int n, int k) {
	if (n < k || n < 0 || k < 0) return 0;
	return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int falling(int n, int k) {
	if (n < k || n < 0) return 0;
	return 1ll * fac[n] * ifac[n - k] % MOD;
}
int dp[MAXN + 5][MAXN + 5];
int main() {
	scanf("%d", &n); init_fac(MAXN);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), siz[i] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (issqr(1ll * a[i] * a[j])) merge(i, j);
	for (int i = 1; i <= n; i++) if (find(i) == i) b[++m] = siz[i];
	dp[0][0] = 1; int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= sum; j++) for (int k = 1; k <= b[i + 1]; k++)
			for (int l = 0; l <= min(j, k); l++) {
				int coef = 1ll * fac[b[i + 1]] * binom(b[i + 1] - 1, k - 1) % MOD * ifac[k] % MOD;
				// seperate b[i + 1] balls into k groups
				coef = 1ll * coef * binom(k, l) % MOD * falling(j, l) % MOD;
				// choose l of the k groups and discard j adjacent balls with same colors
				coef = 1ll * coef * falling(sum + 1 - j, k - l) % MOD;
				// arrange the position of the rest k - l groups
				dp[i + 1][j - l + (b[i + 1] - k)] = (dp[i + 1][j - l + (b[i + 1] - k)] + 1ll * coef * dp[i][j]) % MOD;
			}
		sum += b[i + 1];
	}
	printf("%d\n", dp[m][0]);
	return 0;
}