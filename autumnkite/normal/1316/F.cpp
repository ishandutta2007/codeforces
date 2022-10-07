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
const int N = 300005, P = 1000000007, inv2 = (P + 1) >> 1;
int n, q, a[N], pw[N], ipw[N];
struct node{
	int v, vl, vr, c;
};
node operator + (const node &a, const node &b){
	node res;
	res.v = (1ll * b.vr * ipw[a.c] % P * a.vl + a.v + b.v) % P;
	res.vl = (a.vl + 1ll * b.vl * pw[a.c]) % P;
	res.vr = (a.vr + 1ll * b.vr * ipw[a.c]) % P;
	res.c = a.c + b.c;
	return res;
}
node operator - (const node &res, const node &b){
	node a;
	a.c = res.c - b.c;
	a.vr = (res.vr + 1ll * (P - b.vr) * ipw[a.c]) % P;
	a.vl = (res.vl + 1ll * (P - b.vl) * pw[a.c]) % P;
	a.v = (res.v + 1ll * (P - b.vr) * ipw[a.c] % P * a.vl + P - b.v) % P;
	return a;
}
struct Segment_Tree{
	int cnt, ls[N * 30], rs[N * 30];
	node val[N * 30];
	void modify(int &u, int l, int r, int x, int op){
		if (!u) u = ++cnt, ls[u] = 0, rs[u] = 0;
		if (l == r){
			node tmp = {0, x, 1ll * x * ipw[1] % P, 1};
			if (op) val[u] = val[u] + tmp; else val[u] = val[u] - tmp;
			return;
		}
		int md = (l + r) >> 1;
		if (x <= md) modify(ls[u], l, md, x, op);
		else modify(rs[u], md + 1, r, x, op);
		val[u] = val[ls[u]] + val[rs[u]];
	}
}T;
int rt;
int main(){
	read(n);
	pw[0] = ipw[0] = 1;
	for (register int i = 1; i <= n; ++i)
		pw[i] = 2ll * pw[i - 1] % P, ipw[i] = 1ll * inv2 * ipw[i - 1] % P;
	for (register int i = 1; i <= n; ++i)
		read(a[i]), T.modify(rt, 1, P - 1, a[i], 1);
	read(q);
	print(T.val[rt].v);
	while (q--){
		int x, v;
		read(x), read(v);
		T.modify(rt, 1, P - 1, a[x], 0);
		a[x] = v;
		T.modify(rt, 1, P - 1, a[x], 1);
		print(T.val[rt].v);
	}
}