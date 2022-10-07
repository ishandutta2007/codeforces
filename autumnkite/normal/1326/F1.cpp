#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
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
int n, E[14][14], bitcnt[1 << 14], rev[1 << 14], p[14], f[1 << 14][1 << 6][14];
long long ans[1 << 14];
std::vector<int> G[14][2];
void solve(){
	read(n);
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < n; ++j){
			while (!isdigit(E[i][j] = getchar())) ;
			E[i][j] ^= '0';
			G[i][E[i][j]].push_back(j);
		}
	bitcnt[0] = 0;
	for (register int i = 1; i < (1 << n); ++i) bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	rev[0] = 0;
	for (register int i = 1; i < (1 << (n - 1)); ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (n - 2);
	int B1 = n >> 1, B2 = n - B1;
	for (register int S = 0; S < (1 << n); ++S)
		if (bitcnt[S] == B1 || bitcnt[S] == B2){
			int cnt = 0;
			for (register int i = 0; i < n; ++i)
				if (S >> i & 1) p[cnt++] = i;
			while (1){
				int T = 0;
				for (register int i = 0; i < cnt - 1; ++i)
					if (E[p[i]][p[i + 1]]) T |= 1 << i;
				++f[S][T][p[cnt - 1]];
				if (!std::next_permutation(p, p + cnt)) break;
			}
		}
	int U = (1 << n) - 1, U1 = (1 << (B1 - 1)) - 1, U2 = (1 << (B2 - 1)) - 1;
	for (register int S = 0; S < (1 << n); ++S)
		if (bitcnt[S] == B1){
			for (register int T = 0; T < (1 << (n - 1)); ++T)
				if (T <= rev[T]){
					int T1 = T & U1, T2 = rev[T] & U2, t = (T >> (B1 - 1)) & 1, _S = U ^ S;
					for (register int i = 0; i < n; ++i)
						if (f[S][T1][i])
							for (int j : G[i][t])
								ans[T] += f[S][T1][i] * f[_S][T2][j];
				}
		}
	for (register int T = 0; T < (1 << (n - 1)); ++T)
		if (T <= rev[T]) print(ans[T], ' '); else print(ans[rev[T]], ' ');
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