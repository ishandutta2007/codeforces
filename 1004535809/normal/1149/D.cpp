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
const int MAXN = 70;
const int MAXM = 200;
const int MAXP = 131072;
const int INF = 0x3f3f3f3f;
int n, m, a, b, hd[MAXN + 5], to[MAXM * 2 + 5], nxt[MAXM * 2 + 5], val[MAXM * 2 + 5], ec = 0;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
int f[MAXN + 5], siz[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y); if (x == y) return;
	f[x] = y; siz[y] += siz[x];
}
int id[MAXN + 5], cnt = 0, dp[MAXP + 5][MAXN + 5];
typedef pair<int, pii> ppii;
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++) siz[i] = 1;
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w); adde(u, v, w); adde(v, u, w);
		if (w == a) merge(u, v);
	}
	for (int i = 1; i <= n; i++) if (find(i) == i && siz[i] >= 4) id[i] = ++cnt;
	int cntc = cnt;
	for (int i = 1; i <= n; i++) if (find(i) == i && siz[i] < 4) id[i] = ++cnt;
	for (int i = 1; i <= n; i++) if (!id[i]) id[i] = id[find(i)];
	memset(dp, 63, sizeof(dp)); dp[(id[1] > cntc) ? 0 : (1 << id[1] - 1)][1] = 0;
	priority_queue<ppii, vector<ppii>, greater<ppii> > q;
	q.push(mp(0, mp((id[1] > cntc) ? 0 : (1 << id[1] - 1), 1)));
//	printf("%d\n", cnt);
	while (!q.empty()) {
		ppii p = q.top(); q.pop();
		int msk = p.se.fi, x = p.se.se;
//		printf("%d %d %d\n", msk, x, dp[msk][x]);
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = val[e];
			if (z == b && id[y] <= cntc && (msk >> (id[y] - 1) & 1)) continue;
			if (z == b && id[y] == id[x]) continue;
			int nmsk = (id[y] <= cntc) ? (msk | (1 << id[y] - 1)) : msk;
			if (dp[nmsk][y] > dp[msk][x] + z) {
				dp[nmsk][y] = dp[msk][x] + z;
				q.push(mp(dp[nmsk][y], mp(nmsk, y)));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int res = INF;
		for (int j = 0; j < (1 << cntc); j++) chkmin(res, dp[j][i]);
		printf("%d%c", res, " \n"[i == n]);
	}
	return 0;
}