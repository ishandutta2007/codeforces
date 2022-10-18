#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;
int n, res[MAXN + 5];
struct dat {int a, b, id;} a[MAXN + 5];
bool cmp(dat x, dat y) {return x.a < y.a;}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].a);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].b), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	int mx = 0, mnx = INF, mny = INF;
	for (int i = 1; i <= n; i++) res[i] = 0;
	queue<int> q;
	for (int i = n; i; i--) if (a[i].b > mx) {
		res[a[i].id] = 1, mx = a[i].b; q.push(i);
		chkmin(mnx, a[i].a), chkmin(mny, a[i].b);
	}
	set<pii> sta, stb;
	for (int i = 1; i <= n; i++) {sta.insert(mp(a[i].a, i)); stb.insert(mp(a[i].b, i));}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		chkmin(mnx, a[x].a); chkmin(mny, a[x].b);
		res[a[x].id] = 1;
		while (!sta.empty()) {
			pii p = *sta.rbegin();
			if (p.fi > mnx) {
				q.push(p.se);
				sta.erase(sta.find(mp(a[p.se].a, p.se)));
				stb.erase(stb.find(mp(a[p.se].b, p.se)));
			} else break;
		}
		while (!stb.empty()) {
			pii p = *stb.rbegin();
			if (p.fi > mny) {
				q.push(p.se);
				sta.erase(sta.find(mp(a[p.se].a, p.se)));
				stb.erase(stb.find(mp(a[p.se].b, p.se)));
			} else break;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d", res[i]);
	puts("");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}