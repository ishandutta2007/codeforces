#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
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
int n;
std::vector<int> bitcnt;
std::vector<std::vector<long long>> f;
std::vector<std::vector<long long>> g;
std::map<std::vector<int>, std::vector<int>> part;
std::vector<long long> ans;
void dfs(int r, const std::vector<int> &l, const std::vector<long long> &s){
	if (!r){
		long long res = 0;
		int mask = (1 << n) - 1;
		for (register int i = 0; i < (1 << n); ++i)
			if (bitcnt[mask ^ i] & 1) res -= s[i]; else res += s[i];
		const std::vector<int> &p = part[l];
		for (int v : p) ans[v] += res;
		return;
	}
	int lst = l.empty() ? 1 : l.back();
	for (register int k = lst; k <= r; ++k){
		if (k < r && r - k < k) continue;
		std::vector<int> nl(l);
		std::vector<long long> ns(s);
		nl.push_back(k);
		for (register int i = 0; i < (1 << n); ++i) ns[i] *= g[k - 1][i];
		dfs(r - k, nl, ns);
	}
}
void solve(){
	read(n);
	std::vector<std::vector<int>> E(n);
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < n; ++j){
			char ch;
			while (!isdigit(ch = getchar())) ;
			if (ch == '1') E[i].push_back(j);
		}
	bitcnt.resize(1 << n);
	bitcnt[0] = 0;
	for (register int i = 1; i < (1 << n); ++i) bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	f.resize(n, std::vector<long long>(1 << n, 0));
	g.resize(n, std::vector<long long>(1 << n, 0));
	for (register int i = 0; i < n; ++i) f[i][1 << i] = 1;
	for (register int S = 1; S < (1 << n); ++S)
		for (register int i = 0; i < n; ++i)
			if (f[i][S]){
				g[bitcnt[S] - 1][S] += f[i][S];
				for (int v : E[i]) if (!(S >> v & 1)) f[v][S | (1 << v)] += f[i][S];
			}
	for (register int k = 0; k < n; ++k)
		for (register int i = 0; i < n; ++i)
			for (register int S = 0; S < (1 << n); ++S)
				if (S >> i & 1) g[k][S] += g[k][S ^ (1 << i)];
	for (register int S = 0; S < (1 << (n - 1)); ++S){
		std::vector<int> p;
		int x = 1;
		for (register int i = 0; i < n - 1; ++i)
			if (S >> i & 1) ++x; else p.push_back(x), x = 1;
		p.push_back(x);
		std::sort(p.begin(), p.end());
		part[p].push_back(S);
	}
	ans.resize(1 << (n - 1), 0);
	dfs(n, std::vector<int>(), std::vector<long long>(1 << n, 1));
	for (register int i = 0; i < n - 1; ++i)
		for (register int S = 0; S < (1 << (n - 1)); ++S)
			if (S >> i & 1) ans[S ^ (1 << i)] -= ans[S];
	for (long long v : ans) print(v, ' ');
	putchar('\n');
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