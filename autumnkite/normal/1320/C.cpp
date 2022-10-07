#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
namespace fastIO{
#define getchar() my_getchar()
#define putchar(x) my_putchar(x)
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
	char buf[IN_BUF], *ps = buf, *pt = buf;
	inline char my_getchar() {
		return ps == pt && (pt = (ps = buf) + fread(buf, 1, IN_BUF, stdin), ps == pt) ? EOF : *ps++;
	}
	template<typename T> inline bool read(T &x){
		char op = 0, ch = getchar();
		for (x = 0; !isdigit(ch) && ch != EOF; ch = getchar()) if (ch == '-') op ^= 1;
		if (ch == EOF) return false;
		for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ '0');
		if (ch != '.') return op ? x = -x : 0, true; else ch = getchar();
		T t = 1;
		for (; isdigit(ch); ch = getchar()) t /= 10, x += (ch ^ '0') * t;
		return op ? x = -x : 0, true;
	}
	inline int reads(char *s){
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar()) ;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
		return s[n] = '\0', n;
	}
	char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher{ ~_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } OutputFlusher;
	inline void my_putchar(char x){
		pp == pbuf + OUT_BUF ? fwrite(pbuf, 1, OUT_BUF, stdout), pp = pbuf : 0, *pp++ = x;
	}
	template<typename T> inline void print_(T x){
		if (x == 0) return putchar('0'), void(0);
		std::vector<int> num;
		for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num.push_back(x % 10);
		while (!num.empty()) putchar(num.back() ^ '0'), num.pop_back();
	}
	template<typename T> inline void print(T x, char ch = '\n'){
		print_(x), putchar(ch);
	}
	inline void prints_(const char *s, int n = -1){
		if (n == -1) n = strlen(s);
		for (register int i = 0; i < n; ++i) putchar(s[i]);
	}
	inline void prints(const char *s, int n = -1, char ch = '\n'){
		prints_(s, n), putchar(ch);
	}
	template<typename T> inline void printd_(T x, int n){
		if (x < 0) x = -x, putchar('-');
		long long a, b;
		for (register int i = 0; i < n; ++i) x *= 10;
		x = (long long)(x + 0.5);
		for (register int i = 0; i < n; ++i) x /= 10;
		a = x, x -= a;
		for (register int i = 0; i < n; ++i) x *= 10;
		b = x;
		print_(a);
		if (n) putchar('.'); else return;
		std::vector<int> num(n);
		for (register int i = 0; i < n; ++i) num[i] = b % 10, b /= 10;
		while (!num.empty()) putchar(num.back() ^ '0'), num.pop_back();
	}
	template<typename T> inline void printd(T x, int n, char ch = '\n'){
		printd_(x, n), putchar(ch);
	}
}
using namespace fastIO;
const int N = 1000005, INF = 0x7f7f7f7f;
int n, m, k, mxa, a[N], mxb, b[N], ans;
std::vector<std::pair<int, int>> p[N];
struct Segment_Tree{
	int val[N << 2], lz[N << 2];
	void build(int u, int l, int r){
		if (l == r) return val[u] = -b[l], void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		val[u] = std::max(val[u << 1], val[u << 1 | 1]);
	}
	void add(int u, int v){
		val[u] += v, lz[u] += v;
	}
	void down(int u){
		if (lz[u]) add(u << 1, lz[u]), add(u << 1 | 1, lz[u]), lz[u] = 0;
	}
	void modify(int u, int l, int r, int L, int R, int v){
		if (L > R) return;
		if (L <= l && r <= R) return add(u, v), void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify(u << 1, l, md, L, R, v);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, v);
		val[u] = std::max(val[u << 1], val[u << 1 | 1]);
	}
	int query(){ return val[1]; }
}T;
void solve(){
	read(n), read(m), read(k);
	memset(a, 0x7f, sizeof a);
	memset(b, 0x7f, sizeof b);
	for (register int i = 1, x, y; i <= n; ++i)
		read(x), read(y), a[x] = std::min(a[x], y), mxa = std::max(mxa, x);
	for (register int i = 1, x, y; i <= m; ++i)
		read(x), read(y), b[x] = std::min(b[x], y), mxb = std::max(mxb, x);
	for (register int i = 1, x, y, w; i <= k; ++i){
		read(x), read(y), read(w);
		mxa = std::max(mxa, x), mxb = std::max(mxb, y);
		p[x].push_back({y, w});
	}
	T.build(1, 1, mxb);
	ans = -INF;
	for (register int i = 1; i <= mxa; ++i){
		ans = std::max((long long)ans, (long long)T.query() - a[i]);
		for (auto v : p[i]) T.modify(1, 1, mxb, v.first + 1, mxb, v.second);
	}
	print(ans);
}
int main(){
	int T = 1;
	// read(T);
	while (T--) solve();
}