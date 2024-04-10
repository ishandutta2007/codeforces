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
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 1005, C = 14;
int n;
char t[N], s[400005];
std::pair<int, long long> go[N][C + 1];
int bitcnt[1 << C];
long long f[1 << C][N];
struct AC_Automaton{
	int rt, cnt, trans[N][C], fail[N];
	long long w[N];
	int new_node(){
		int u = cnt++;
		w[u] = 0, fail[u] = -1;
		for (register int i = 0; i < C; ++i) trans[u][i] = -1;
		return u;
	}
	void init(){
		cnt = 0, rt = new_node();
	}
	void insert(const std::vector<int> &s, long long _w){
		int u = rt;
		for (register int i = 0; i < (int)s.size(); ++i){
			if (trans[u][s[i]] == -1) trans[u][s[i]] = new_node();
			u = trans[u][s[i]];
		}
		w[u] += _w;
	}
	void build(){
		std::vector<int> Q;
		fail[rt] = -1;
		for (register int i = 0; i < C; ++i)
			if (~trans[rt][i]) Q.push_back(trans[rt][i]), fail[trans[rt][i]] = rt;
			else trans[rt][i] = rt;
		for (register int i = 0; i < (int)Q.size(); ++i){
			int u = Q[i];
			w[u] += w[fail[u]];
			for (register int j = 0; j < C; ++j)
				if (~trans[u][j]) Q.push_back(trans[u][j]), fail[trans[u][j]] = trans[fail[u]][j];
				else trans[u][j] = trans[fail[u]][j];
		}
	}
	std::pair<int, long long> run(int u, const std::vector<int> &s){
		long long sum = 0;
		for (register int i = 0; i < (int)s.size(); ++i)
			u = trans[u][s[i]], sum += w[u];
		return {u, sum};
	}
}A;
int main(){
#ifdef AT_HOME
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	read(n);
	A.init();
	for (register int i = 0; i < n; ++i){
		int m = reads(t), w;
		std::vector<int> tmp;
		read(w);
		for (register int j = 0; j < m; ++j) tmp.push_back(t[j] - 'a');
		A.insert(tmp, w);
	}
	// for (register int i = 0; i < A.cnt; ++i){
	// 	debug("%d %d %lld\n", i, A.fail[i], A.w[i]);
	// 	for (register int j = 0; j < C; ++j) debug("%d ", A.trans[i][j]);
	// 	debug("\n");
	// }
	A.build();
	int len = reads(s);
	std::vector<int> tmp;
	int cnt = 0;
	for (register int i = 0; i <= len; ++i)
		if (i == len || s[i] == '?'){
			for (register int j = 0; j < A.cnt; ++j)
				go[j][cnt] = A.run(j, tmp);
			tmp.clear(), ++cnt;
		}
		else tmp.push_back(s[i] - 'a');
	bitcnt[0] = 0;
	for (register int i = 1; i < (1 << C); ++i)
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	for (register int i = 0; i < (1 << C); ++i)
		for (register int j = 0; j < A.cnt; ++j)
			f[i][j] = -INF;
	f[0][go[A.rt][0].first] = go[A.rt][0].second;
	long long ans = -INF;
	for (register int S = 0; S < (1 << C); ++S){
		int k = bitcnt[S] + 1;
		if (k == cnt){
			for (register int u = 0; u < A.cnt; ++u)
				ans = std::max(ans, f[S][u]);
		}
		if (k >= cnt) continue;
		for (register int u = 0; u < A.cnt; ++u)
			if (f[S][u] != -INF){
				for (register int i = 0; i < C; ++i)
					if (!(S >> i & 1)){
						int v = A.trans[u][i];
						int S_ = S | (1 << i), u_ = go[v][k].first;
						f[S_][u_] = std::max(f[S_][u_], f[S][u] + A.w[v] + go[v][k].second);
					}
			}
	}
	print(ans);
}