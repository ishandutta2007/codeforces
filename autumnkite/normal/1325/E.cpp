#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
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
const int N = 1000005, M = 100005, INF = 0x3f3f3f3f;
int n;
int cnt, p[N], vis[N];
void init(int n){
	for (register int i = 2; i <= n; ++i){
		if (!vis[i]) p[++cnt] = i, vis[i] = cnt;
		for (register int j = 1; j <= cnt && p[j] * i <= n; ++j){
			vis[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
std::vector<int> v[M];
std::vector<std::pair<int, int>> E[N];
int ans, ont[M], tim[N], dis[N];
void bfs(int S){
	for (register int i = 1; i <= n; ++i) ont[i] = 0;
	std::vector<int> Q;
	Q.push_back(S), tim[S] = S, dis[S] = 0;
	for (register int i = 0; i < (int)Q.size(); ++i){
		int u = Q[i];
		for (auto p : E[u]){
			int v = p.first, eid = p.second;
			if (tim[v] != S) Q.push_back(v), tim[v] = S, dis[v] = dis[u] + 1, ont[eid] = 1;
		}
	}
	for (register int i = 1; i <= n; ++i)
		if (!ont[i] && tim[v[i][0]] == S && tim[v[i][1]] == S)
			ans = std::min(ans, dis[v[i][0]] + dis[v[i][1]] + 1);
}
void solve(){
	read(n);
	init(1000000), p[0] = 1, vis[1] = 0;
	for (register int i = 1, x; i <= n; ++i){
		read(x);
		for (register int j = 1; j <= cnt && 1ll * p[j] * p[j] <= x; ++j)
			if (x % p[j] == 0){
				int k = 0;
				while (x % p[j] == 0) x /= p[j], k ^= 1;
				if (k) v[i].push_back(j);
			}
		if (x > 1) v[i].push_back(vis[x]);
		while (v[i].size() < 2) v[i].push_back(0);
		E[v[i][1]].push_back({v[i][0], i}), E[v[i][0]].push_back({v[i][1], i});
	}
	for (register int i = 0; i <= cnt; ++i) tim[i] = -1;
	ans = INF;
	for (register int i = 0; i <= cnt; ++i)
		if (p[i] <= 1000) bfs(i); else break;
	if (ans == INF) print(-1); else print(ans);
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