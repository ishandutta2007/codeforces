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
const int MAXN = 1e5;
const int ALPHA = 26;
const int SQRT = 316;
int n, qu, ch[MAXN + 5][ALPHA + 2], ncnt, fail[MAXN + 5], ed[MAXN + 5];
string s[MAXN + 5];
void insert(string ss, int id) {
	int cur = 0;
	for (int i = 0; i < ss.size(); i++) {
		if (!ch[cur][ss[i] - 'a']) ch[cur][ss[i] - 'a'] = ++ncnt;
		cur = ch[cur][ss[i] - 'a'];
	}
	ed[id] = cur;
}
void getfail() {
	queue<int> q;
	for (int i = 0; i < ALPHA; i++) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < ALPHA; i++) {
			if (ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
			else ch[x][i] = ch[fail[x]][i];
		}
	}
}
int hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int blk_sz, dfn[MAXN + 5], edt[MAXN + 5], tim = 0, rid[MAXN + 5];
void dfs(int x) {
//	printf("dfs %d\n", x);
	rid[dfn[x] = ++tim] = x;
	for (int e = hd[x]; e; e = nxt[e]) dfs(to[e]);
	edt[x] = tim;
}
void build_graph() {
	getfail();
//	for (int i = 1; i <= ncnt; i++) printf("%d %d\n", fail[i], i);
	for (int i = 1; i <= ncnt; i++) adde(fail[i], i);
	dfs(0);
}
ll res[MAXN + 5];
vector<tuple<int, int, int> > qv[MAXN + 5], qv_big[MAXN + 5];
int mark[MAXN + 5];
ll sum[MAXN + 5];
void calc(int x) {
	memset(mark, 0, sizeof(mark)); int cur = 0;
	for (int i = 0; i < s[x].size(); i++) {
		cur = ch[cur][s[x][i] - 'a'];
		mark[cur]++;
	}
	for (int i = ncnt + 1; i; i--) {
		int pt = rid[i];
		for (int e = hd[pt]; e; e = nxt[e]) mark[pt] += mark[to[e]];
	}
//	for (int i = 1; i <= ncnt; i++) printf("%d%c", mark[i], " \n"[i == ncnt]);
	for (int i = 1; i <= n; i++) sum[i] = mark[ed[i]]/*, printf("%d%c", mark[ed[i]], " \n"[i == n])*/;
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for (auto p : qv_big[x]) res[get<2>(p)] = sum[get<1>(p)] - sum[get<0>(p) - 1];
}
struct fenwick_tree {
	int t[MAXN + 5];
	void add(int x, int v) {for (int i = x; i <= ncnt + 1; i += (i & (-i))) t[i] += v;}
	int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
} T;
void ins(int id) {T.add(dfn[ed[id]], 1); T.add(edt[ed[id]] + 1, -1);}
int query(int id) {
	int sum = 0, cur = 0;
	for (int i = 0; i < s[id].size(); i++) {
		cur = ch[cur][s[id][i] - 'a'];
		sum += T.query(dfn[cur]);
	}
	return sum;
}
int main() {
	scanf("%d%d", &n, &qu); int ss = 0;
	for (int i = 1; i <= n; i++) {
		static char buf[MAXN + 5]; scanf("%s", buf + 1);
		int len = strlen(buf + 1);
		for (int j = 1; j <= len; j++) s[i].pb(buf[j]);
		insert(s[i], i); ss += s[i].size();
	}
//	for (int i = 1; i <= n; i++) printf("%d%c", ed[i], " \n"[i == n]);
	build_graph(); blk_sz = (int)sqrt(ss / log(ss));
	for (int i = 1; i <= qu; i++) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		if (s[k].size() > blk_sz) qv_big[k].pb(mt(l, r, i));
		else qv[r].pb(mt(k, i, 1)), qv[l - 1].pb(mt(k, i, -1));
	}
	for (int i = 1; i <= n; i++) if (s[i].size() > blk_sz) calc(i);
	for (int i = 1; i <= n; i++) {
		ins(i);
		for (auto p : qv[i]) res[get<1>(p)] += get<2>(p) * query(get<0>(p));
	}
	for (int i = 1; i <= qu; i++) printf("%lld\n", res[i]);
	return 0;
}