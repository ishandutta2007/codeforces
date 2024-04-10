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
const int MOD = 1e9 + 7;
const int INV2 = MOD + 1 >> 1;
const ll INF = 2e18;
int n, qu, a[MAXN + 5], sum[MAXN + 5], res[MAXN + 5];
int pw2[MAXN + 5], ipw2[MAXN + 5];
vector<pii> qv[MAXN + 5];
set<pii> st;
int calc(int l, int r) {
	if (l > r) return 0;
	return 1ll * (sum[r] - sum[l - 1] + MOD) * ipw2[l] % MOD;
}
int t[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= n; i += (i & (-i))) t[i] = (t[i] + v) % MOD;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret = (ret + t[i]) % MOD; return ret;}
int f[MAXN + 5], siz[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
ll val[MAXN + 5];
void merge(int x, int y) {
	x = find(x); y = find(y);
	int Rx = st.lower_bound(mp(x, 0)) -> se;
	int Ry = st.lower_bound(mp(y, 0)) -> se;
//	printf("[%d, %d] [%d, %d]\n", x, Rx, y, Ry);
	add(Rx, MOD - calc(x, Rx));
	add(Ry, MOD - calc(y, Ry));
	if (siz[x] >= 60) val[x] = INF;
	else if (val[y] >= (INF >> siz[x]) + 1) val[x] = INF;
	else val[x] = min(val[x] + (val[y] << siz[x]), INF);
	siz[x] += siz[y]; f[y] = x;
	add(Rx, calc(x, Ry));
	st.erase(st.find(mp(x, Rx)));
	st.erase(st.find(mp(y, Ry)));
	st.insert(mp(x, Ry));
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), val[i] = a[i], siz[i] = 1;
	for (int i = 1; i <= n + 1; i++) st.insert(mp(i, i));
	for (int i = (pw2[0] = ipw2[0] = 1); i <= n; i++) {
		pw2[i] = 2ll * pw2[i - 1] % MOD;
		ipw2[i] = 1ll * ipw2[i - 1] * INV2 % MOD;
	}
	for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + 1ll * pw2[i] * (a[i] + MOD)) % MOD;
	for (int i = 1, l, r; i <= qu; i++) {scanf("%d%d", &l, &r); qv[r].pb(mp(l, i));}
	for (int i = 1; i <= n; i++) {
		add(i, (a[i] + MOD) % MOD);
		if (a[i] >= 0) {
			while (find(i) != 1 && val[find(i)] > 0) {
				int pos = find(find(i) - 1);
				merge(pos, i);
			}
		}
		for (auto p : qv[i]) {
			int tt = st.upper_bound(mp(p.fi + 1, 0)) -> fi;
//			printf("%d %d %d %d\n", p.fi, i, tt);
			res[p.se] = (0ll + 2ll * (query(n) - query(tt - 1) + MOD) + calc(p.fi, tt - 1)) % MOD;
		}
	}
	for (int i = 1; i <= qu; i++) printf("%d\n", res[i]);
	return 0;
}