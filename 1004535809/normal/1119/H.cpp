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
const int MAXN = 131072;
const int MOD = 998244353;
const int INV2 = 499122177;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, k, a[MAXN + 5], b[MAXN + 5], c[MAXN + 5], sum, x, y, z;
int sa[MAXN + 5], sb[MAXN + 5], sc[MAXN + 5], res[MAXN + 5];
void FWTxor(int *a, int len, int type) {
	for (int i = 2; i <= len; i <<= 1)
		for (int j = 0; j < len; j += i)
			for (int k = 0; k < (i >> 1); k++) {
				int X = a[j + k], Y = a[(i >> 1) + j + k];
				a[j + k] = 1ll * (X + Y) * type % MOD;
				a[(i >> 1) + j + k] = 1ll * (X - Y + MOD) * type % MOD;
			}
}
int main() {
	scanf("%d%d%d%d%d", &n, &k, &x, &y, &z);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]); sum ^= a[i];
		sa[b[i] ^ a[i]]++; sb[c[i] ^ a[i]]++; sc[b[i] ^ c[i]]++;
	}
	FWTxor(sa, 1 << k, 1); FWTxor(sb, 1 << k, 1); FWTxor(sc, 1 << k, 1);
	for (int i = 0; i < (1 << k); i++) {
		if (sa[i] > 1e6) sa[i] -= MOD;
		if (sb[i] > 1e6) sb[i] -= MOD;
		if (sc[i] > 1e6) sc[i] -= MOD;
	}
	for (int i = 0; i < (1 << k); i++) {
		int bc = (n - sc[i]) / 2;
		int bd = (n - sa[i]) / 2;
		int cd = (n - sb[i]) / 2;
		int bcd = bc + bd + cd >> 1;
		int b = bcd - cd, c = bcd - bd, d = bcd - bc;
		int a = n - b - c - d;
//		printf("%d %d %d %d\n", a, b, c, d);
		res[i] = 1ll * qpow((0ll + x + y + z) % MOD, a) *
					   qpow((0ll + x - y + z + MOD) % MOD, b) % MOD *
					   qpow((0ll + x + y - z + MOD) % MOD, c) % MOD *
					   qpow((0ll + x - y - z + MOD + MOD) % MOD, d) % MOD;
	}
	FWTxor(res, 1 << k, INV2);
	for (int i = 0; i < (1 << k); i++) printf("%d%c", res[i ^ sum], " \n"[i == ((1 << k) - 1)]);
	return 0;
}