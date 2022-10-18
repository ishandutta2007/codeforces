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
const int MAXN = 100;
const int MOD = 1e9 + 7;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dp[MAXN + 5][MAXN + 5][2], siz[MAXN + 5];
void dfs(int x, int f) {
	dp[x][0][0] = dp[x][0][1] = 1; siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; dfs(y, x);
		static int tmp[MAXN + 5][2];
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < siz[x]; i++) for (int j = 0; j < siz[y]; j++)
			for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++)
				if (!(p & q)) tmp[i + j][p | q] = (tmp[i + j][p | q] + 1ll * dp[x][i][p] * dp[y][j][q]) % MOD;
		for (int i = 0; i < siz[x]; i++) for (int j = 0; j < siz[y]; j++)
			for (int p = 0; p < 2; p++) tmp[i + j + 1][p] = (tmp[i + j + 1][p] + 1ll * dp[x][i][p] * dp[y][j][1]) % MOD;
		siz[x] += siz[y];
		for (int i = 0; i < siz[x]; i++) for (int j = 0; j < 2; j++) dp[x][i][j] = tmp[i][j];
	}
}
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int way[MAXN + 5], res[MAXN + 5];
int binom(int n, int k) {return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;}
int main() {
	scanf("%d", &n); init_fac(MAXN);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs(1, 0);
	for (int i = 0; i < n; i++) way[i] = 1ll * dp[1][n - 1 - i][1] * qpow(n, MOD - 2 + (n - 1 - i)) % MOD;
//	for (int i = 0; i < n; i++) printf("%d%c", way[i], " \n"[i == n - 1]);
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
		if (~(j - i) & 1) res[i] = (res[i] + 1ll * way[j] * binom(j, i)) % MOD;
		else res[i] = (res[i] - 1ll * way[j] * binom(j, i) % MOD + MOD) % MOD;
	}
	for (int i = 0; i < n; i++) printf("%d%c", res[i], " \n"[i == n - 1]);
	return 0;
}