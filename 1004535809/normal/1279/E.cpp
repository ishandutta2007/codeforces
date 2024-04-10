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
const int MAXN = 50;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int n, p[MAXN + 5]; ll k, dp[MAXN + 5], fac[MAXN + 5];
ll mul(ll x, ll y) {if (!x || !y) return 0; return (y <= INF / x) ? (x * y) : INF;}
int f[MAXN + 5], siz[MAXN + 5]; bool has[MAXN + 5], used[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y); if (x == y) has[x] = 1;
	else f[x] = y, siz[y] += siz[x];
}
ll calc() {
	memset(f, 0, sizeof(f)); memset(has, 0, sizeof(has));
	for (int i = 1; i <= n; i++) siz[i] = 1;
	for (int i = 1; i <= n; i++) if (p[i]) merge(i, p[i]);
	for (int l = 1, r; l <= n; l = r + 1) {
		if (!p[l]) return dp[n - l + 1];
		else {
			r = p[l]; bool flg = 0;
			for (int i = l; i <= r; i++) flg |= (!p[i]);
			if (flg) {
				int cnt = 0; static bool vis[MAXN + 5];
				memset(vis, 0, sizeof(vis));
				for (int i = l; i <= r; i++) vis[find(i)] = 1;
				for (int i = l; i <= r; i++) if (has[find(i)]) return 0;
				int sum = 0;
				for (int i = 1; i <= n; i++) sum += vis[i];
				return mul(fac[sum - 1], dp[n - r]);
			} else {
				if (!has[find(l)]) return 0;
				for (int i = l; i <= r; i++) if (find(i) != find(l))
					return 0;
				if (siz[find(l)] != r - l + 1) return 0;
			}
		}
	}
	return 1;
}
void solve() {
	scanf("%d%lld", &n, &k); memset(p, 0, sizeof(p));
	if (k > calc()) return puts("-1"), void();
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (!used[j]) {
			p[i] = j; ll c = calc();
			if (k > c) k -= c;
			else break;
		}
		used[p[i]] = 1;
	}
	for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
}
int main() {
	fac[0] = dp[0] = 1; for (int i = 1; i <= MAXN; i++) fac[i] = mul(fac[i - 1], i);
	for (int i = 1; i <= MAXN; i++) for (int j = 0; j < i; j++)
		dp[i] = min(dp[i] + mul(dp[j], fac[max(i - j - 2, 0)]), INF);
	int qu; scanf("%d", &qu); while (qu--) solve();
	return 0;
}