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
int n, x, y, z, t, p;
std::vector<std::vector<int>> f;
std::map<std::vector<std::vector<int>>, int> M;
int mex(int a, int b, int c){
	if (a != 0 && b != 0 && c != 0) return 0;
	if (a != 1 && b != 1 && c != 1) return 1;
	if (a != 2 && b != 2 && c != 2) return 2;
	return 3;
}
void add(){
	int k = f.size();
	f.push_back(std::vector<int>(3));
	f[k][0] = mex(f[std::max(k - x, 0)][0], f[std::max(k - y, 0)][1], f[std::max(k - z, 0)][2]);
	f[k][1] = mex(f[std::max(k - x, 0)][0], 3, f[std::max(k - z, 0)][2]);
	f[k][2] = mex(f[std::max(k - x, 0)][0], f[std::max(k - y, 0)][1], 3);
}
int get(long long v){
	if (v < t) return v;
	return (v - t) % p + t;
}
void solve(){
	read(n), read(x), read(y), read(z);
	f.clear(), M.clear(), f.push_back({0, 0, 0});
	for (register int i = 1; i < 5; ++i) add();
	while (1){
		std::vector<std::vector<int>> tmp(f.end() - 5, f.end());
		if (M.count(tmp)){ t = M[tmp], p = f.size() - 5 - M[tmp]; break; }
		M[tmp] = f.size() - 5, add();
	}
	// debug("%d %d\n", t, p);
	int sum = 0, s[4] = {0, 0, 0, 0};
	for (register int i = 1; i <= n; ++i){
		long long v, v0, v1, v2;
		read(v);
		v0 = std::max(v - x, 0ll), v1 = std::max(v - y, 0ll), v2 = std::max(v - z, 0ll);
		int cur = f[get(v)][0], cur0 = f[get(v0)][0], cur1 = f[get(v1)][1], cur2 = f[get(v2)][2];
		sum ^= cur, ++s[cur ^ cur0], ++s[cur ^ cur1], ++s[cur ^ cur2];
	}
	print(s[sum]);
}
int main(){
#ifdef AT_HOME
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T = 1;
	read(T);
	while (T--) solve();
}