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
const int MAXN = 16;
const int MAXK = 2000;
const int MAXP = 1 << 16;
int n, k, a[MAXN + 5], sum, b[MAXN + 5];
bitset<MAXK + 5> dp[MAXP + 5];
void dump(int msk, int v) {
	if (!msk) return;
	if (v * k <= MAXK && dp[msk][v * k]) {
		for (int i = 1; i <= n; i++) if (msk >> (i - 1) & 1) b[i]++;
		dump(msk, v * k); return;
	}
	for (int i = 1; i <= n; i++) if ((msk >> (i - 1) & 1) && v >= a[i] && dp[msk ^ (1 << i - 1)][v - a[i]])
		return dump(msk ^ (1 << i - 1), v - a[i]), void();
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
	dp[0][0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 1; j <= n; j++) if (i >> (j - 1) & 1)
			dp[i] |= (dp[i ^ (1 << j - 1)] << a[j]);
		for (int j = sum / k; j; j--) if (dp[i][j * k]) dp[i][j] = 1;
	}
	if (!dp[(1 << n) - 1][1]) puts("NO");
	else {
		puts("YES"); dump((1 << n) - 1, 1);
//		for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
		priority_queue<pii> q;
		for (int i = 1; i <= n; i++) q.push(mp(b[i], a[i]));
		while (q.size() > 1) {
			pii p1 = q.top(); q.pop();
			pii p2 = q.top(); q.pop();
			printf("%d %d\n", p1.se, p2.se);
			p1.se += p2.se;
			while (p1.se % k == 0) p1.se /= k, p1.fi--;
			q.push(p1);
		}
	}
	return 0;
}