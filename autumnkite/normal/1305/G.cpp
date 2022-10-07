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
const int N = 200005;
int n, a[N], mx, m;
long long ans;
struct dsu{
	int fa[N];
	void init(int _n){
		for (register int i = 1; i <= n; ++i) fa[i] = i;
	}
	int find(int x){ return fa[x] == x ? x : (fa[x] = find(fa[x])); }
	bool merge(int x, int y){
		x = find(x), y = find(y);
		if (x == y) return 0;
		return fa[y] = x, 1;
	}
}D;
struct node{
	int w, bel;
};
std::pair<node, node> f[1 << 18];
node g[N];
void upd(std::pair<node, node> &a, node b){
	if (b.w > a.first.w){
		if (a.first.bel != b.bel) a.second = a.first;
		a.first = b;
	}
	else if (b.w > a.second.w && b.bel != a.first.bel) a.second = b;
}
node get(int bel, std::pair<node, node> a){
	if (a.first.bel != bel) return a.first; else return a.second;
}
int main(){
	read(n);
	for (register int i = 1; i <= n; ++i) read(a[i]), mx = std::max(mx, a[i]), ans -= a[i];
	a[++n] = 0;
	while ((1 << m) <= mx) ++m;
	D.init(n);
	int now = n, U = (1 << m) - 1;
	while (now > 1){
		for (register int i = 0; i < (1 << m); ++i) f[i] = {{-1, 0}, {-1, 0}};
		for (register int i = 1; i <= n; ++i) upd(f[a[i]], {a[i], D.find(i)});
		for (register int i = 0; i < m; ++i)
			for (register int j = 0; j < (1 << m); ++j)
				if (j >> i & 1) upd(f[j], f[j ^ (1 << i)].first), upd(f[j], f[j ^ (1 << i)].second);
		for (register int i = 1; i <= n; ++i) g[i] = {-1, 0};
		for (register int i = 1; i <= n; ++i){
			int bel = D.find(i);
			node t = get(bel, f[U ^ a[i]]);
			t.w += a[i];
			if (t.bel && t.w > g[bel].w) g[bel] = t;
		}
		for (register int i = 1; i <= n; ++i)
			if (g[i].bel && D.merge(i, g[i].bel)) --now, ans += g[i].w;
	}
	print(ans);
}