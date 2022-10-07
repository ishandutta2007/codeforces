#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
namespace fastIO{
#define getchar() my_getchar()
#define putchar(x) my_putchar(x)
#define debug(...) fprintf(stderr, __VA_ARGS__)
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
	char buf[IN_BUF], *ps = buf, *pt = buf;
	inline char my_getchar(){
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
const int N = 1000005;
int n, k, id[N], sp[N];
char fw[N], tmp[5];
std::vector<int> E[N];
int idx, dfn[N], cnt[N];
void dfs(int u){
	dfn[u] = ++idx, cnt[idx] = sp[u];
	for (int v : E[u]) dfs(v);
}
int f[N];
std::multiset<int> S;
void DP(int u, int fa = -1){
	if (~fa) f[u] = f[fa] + 1; else f[u] = 0;
	if (sp[u]) f[u] = std::min(f[u], *S.begin() + cnt[dfn[u]]);
	int val = f[u] - (dfn[u] ? cnt[dfn[u] - 1] : 0);
	S.insert(val);
	for (int v : E[u]) DP(v, u);
	S.erase(S.find(val));
}
void solve(){
	read(n);
	for (register int i = 1, x; i <= n; ++i)
		read(x), reads(tmp), fw[i] = tmp[0], E[x].push_back(i);
	for (register int i = 0; i <= n; ++i)
		std::sort(E[i].begin(), E[i].end(), [=](int a, int b){ return fw[a] < fw[b]; });
	read(k);
	for (register int i = 1; i <= k; ++i) read(id[i]), sp[id[i]] = 1;
	idx = -1, dfs(0);
	for (register int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
	DP(0);
	for (register int i = 1; i <= k; ++i) print(f[id[i]], " \n"[i == k]);
}
int main(){
#ifdef AT_HOME
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T = 1;
	// read(T);
	while (T--) solve();
}