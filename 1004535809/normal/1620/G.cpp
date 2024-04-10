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
const int MAXN = 23;
const int ALPHA = 26;
const int MAXP = 8388608;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n, cnt[MAXN + 3][ALPHA + 2], prd[MAXP + 5];
int mn[ALPHA + 2][MAXP + 5], hib[MAXP + 5];
string s[MAXN + 5];
int main() {
	cin >> n;
	for (int i = 1; i <= MAXN; i++) hib[1 << i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) cnt[i][s[i][j] - 'a']++;
	}
	for (int i = 0; i < ALPHA; i++) mn[i][0] = INF;
	for (int i = 0; i < ALPHA; i++) for (int j = 1; j < (1 << n); j++) {
		mn[i][j] = min(mn[i][j & (j - 1)], cnt[hib[j & (-j)] + 1][i]);
	}
	for (int j = 1; j < (1 << n); j++) {
		prd[j] = 1;
		for (int i = 0; i < ALPHA; i++) prd[j] = 1ll * prd[j] * (mn[i][j] + 1) % MOD;
		if (!__builtin_parity(j)) prd[j] = MOD - prd[j];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < (1 << n); j++)
		if (j >> i & 1) prd[j] = (prd[j] + prd[j ^ (1 << i)]) % MOD;
	ll ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) if (i >> (j - 1) & 1) sum += j;
		ans ^= 1ll * __builtin_popcount(i) * sum * prd[i];
	}
	printf("%lld\n", ans);
	return 0;
}