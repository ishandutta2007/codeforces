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
const int MAXN = 102;
const int MOD = 1e9 + 7;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int r, p[4], sum, pos[MAXN + 5];
bool in(int x, int y) {return x * x + y * y <= r * r;}
struct dat {
	int c[MAXN + 5];
	dat() {memset(c, 0, sizeof(c));}
	dat operator + (const dat &rhs) {
		dat res;
		for (int i = -r; i <= r + 1; i++) res.c[i + r] = (c[i + r] + rhs.c[i + r]) % MOD;
		return res;
	}
	dat operator - (const dat &rhs) {
		dat res;
		for (int i = -r; i <= r + 1; i++) res.c[i + r] = (c[i + r] - rhs.c[i + r] + MOD) % MOD;
		return res;
	}
	dat operator * (const int &rhs) {
		dat res;
		for (int i = -r; i <= r + 1; i++) res.c[i + r] = 1ll * c[i + r] * rhs % MOD;
		return res;
	}
} a[MAXN + 5][MAXN + 5], ONE;
int b[MAXN + 5][MAXN + 5], cnt = 0, res[MAXN + 5];
int main() {
	scanf("%d", &r); for (int i = 0; i < 4; i++) scanf("%d", &p[i]), sum += p[i];
	sum = qpow(sum, MOD - 2); for (int i = 0; i < 4; i++) p[i] = 1ll * p[i] * sum % MOD;
//	for (int i = 0; i < 4; i++) printf("%d ", p[i]); printf("\n");
	for (int i = -r; i <= r; i++) for (int j = -r; j <= r; j++)
		if (in(i, j)) {pos[i + r] = j; break;}
	ONE.c[r << 1 | 1] = 1;
	for (int i = -r; i <= r; i++) a[pos[i + r] + r][i + r].c[i + r] = 1;
	for (int x = -r; x <= r; x++) for (int y = -r; y <= r; y++) if (in(x, y)) {
		dat trs; trs = trs + a[x + r][y + r]; trs = trs - ONE;
		if (in(x - 1, y)) trs = trs - a[x - 1 + r][y + r] * p[0];
		if (in(x, y - 1)) trs = trs - a[x + r][y - 1 + r] * p[1];
		if (in(x, y + 1)) trs = trs - a[x + r][y + 1 + r] * p[3];
		trs = trs * qpow(p[2], MOD - 2);
		a[x + 1 + r][y + r] = a[x + 1 + r][y + r] + trs;
//		printf("(%d, %d): ", x, y);
//		for (int i = 0; i <= (r << 1 | 1); i++) printf("%d%c", trs.c[i], " \n"[i == (r << 1 | 1)]);
	}
	for (int y = -r; y <= r; y++) {
		int x = -pos[y + r] + 1;
		for (int j = 0; j <= 2 * r; j++) b[cnt][j] = a[x + r][y + r].c[j];
		b[cnt][r << 1 | 1] = (MOD - a[x + r][y + r].c[r << 1 | 1]) % MOD;
		cnt++;
	}
//	for (int i = 0; i < cnt; i++) for (int j = 0; j <= (r << 1 | 1); j++)
//		printf("%d%c", b[i][j], " \n"[j == (r << 1 | 1)]);
	for (int i = 0; i < cnt; i++) {
		int t = i;
		for (int j = i; j < cnt; j++) if (b[j][i]) t = j;
		for (int j = i; j <= cnt; j++) swap(b[i][j], b[t][j]);
		int iv = qpow(b[i][i], MOD - 2);
		for (int j = i; j <= cnt; j++) b[i][j] = 1ll * b[i][j] * iv % MOD;
		for (int j = i + 1; j < cnt; j++) {
			for (int k = i + 1; k <= cnt; k++) b[j][k] = (b[j][k] - 1ll * b[j][i] * b[i][k] % MOD + MOD) % MOD;
			b[j][i] = 0;
		}
	}
	for (int i = cnt - 1; ~i; i--) {
		res[i] = b[i][cnt];
		for (int j = i + 1; j < cnt; j++) res[i] = (res[i] - 1ll * b[i][j] * res[j] % MOD + MOD) % MOD;
	}
//	for (int i = 0; i < cnt; i++) printf("%d\n", res[i]);
	int ans = a[r][r].c[r << 1 | 1];
	for (int i = 0; i < cnt; i++) ans = (ans + 1ll * res[i] * a[r][r].c[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}