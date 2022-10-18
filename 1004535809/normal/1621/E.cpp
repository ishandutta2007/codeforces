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
const int MAXN = 1e5;
int n, m, a[MAXN + 5], c[MAXN + 5], pos[MAXN + 5];
int ban1[MAXN + 5], ban2[MAXN + 5], ban3[MAXN + 5];
pair<double, int> s[MAXN + 5];
vector<int> b[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) c[i] = a[i + (n - m)];
	for (int i = 1; i <= m; i++) {
		int len, tmp; scanf("%d", &len);
		tmp = len; b[i].clear(); ll sum = 0;
		while (len--) {
			int x; scanf("%d", &x);
			b[i].pb(x); sum += x;
		}
		s[i].se = i; s[i].fi = 1.0 * sum / tmp;
	}
	sort(s + 1, s + m + 1);
//	for (int i = 1; i <= m; i++) printf("%.10lf %d\n", s[i].fi, s[i].se);
	for (int i = 1; i <= m; i++) pos[s[i].se] = i;
	for (int i = 1; i <= m; i++) ban1[i] = s[i].fi > c[i];
	for (int i = 1; i < m; i++) ban2[i] = s[i].fi > c[i + 1];
	for (int i = 2; i <= m; i++) ban3[i] = s[i].fi > c[i - 1];
	ban2[m] = ban3[1] = 0;
	for (int i = 1; i <= m; i++) {
		ban1[i] += ban1[i - 1];
		ban2[i] += ban2[i - 1];
		ban3[i] += ban3[i - 1];
	}
//	for (int i = 1; i <= m; i++) printf("%d %d %d\n", ban1[i], ban2[i], ban3[i]);
	for (int i = 1; i <= m; i++) {
		ll sum = 0;
		for (int x : b[i]) sum += x;
		for (int x : b[i]) {
			double nw = 1.0 * (sum - x) / (b[i].size() - 1);
			int l = 1, r = m, p = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (nw >= s[mid].fi) p = mid, l = mid + 1;
				else r = mid - 1;
			}
			p++; p -= (p > pos[i]); int cnt = 0;
//			printf("%.10lf %d %d\n", nw, p, pos[i]);
			if (p < pos[i]) {
				cnt = ban1[p - 1] + ban1[m] - ban1[pos[i]];
				cnt += ban2[pos[i] - 1] - ban2[p - 1];
				cnt += (nw > c[p]);
			} else if (p == pos[i]){
				cnt = ban1[p - 1] + ban1[m] - ban1[p];
				cnt += (nw > c[p]);
			} else {
				cnt = ban1[pos[i] - 1] + ban1[m] - ban1[p];
				cnt += ban3[p] - ban3[pos[i]];
				cnt += (nw > c[p]);
			}
			putchar(cnt ? '0' : '1');
		}
	}
	putchar('\n');
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
5 3
3 5 8 9 11
2
6 9
2
7 10
2
9 12
*/