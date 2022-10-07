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
const int N = 200005, B1 = 233, B2 = 347;
int n, q, m, cnt[N], nx[N];
char a[N], b[N];
struct node{
	static const int P1 = 857893481, P2 = 935845487;
	int H1, H2;
	node(){}
	node(int _H1, int _H2){ H1 = _H1, H2 = _H2; }
	bool operator == (const node &rhs) const {
		return H1 == rhs.H1 && H2 == rhs.H2;
	}
	node operator * (const node &rhs) const {
		return node(1ll * H1 * rhs.H1 % P1, 1ll * H2 * rhs.H2 % P2);
	}
	node operator + (const node &rhs) const {
		return node((H1 + rhs.H1) % P1, (H2 + rhs.H2) % P2);
	}
	node operator - (const node &rhs) const {
		return node((H1 - rhs.H1 + P1) % P1, (H2 - rhs.H2 + P2) % P2);
	}
}h[N], pw[N];
node add(const node &a, const node &b, int len = 1){
	return a * pw[len] + b;
}
node query(const node &a, const node &b, int len = 1){
	return b - a * pw[len];
}
int main(){
	read(n), reads(a + 1);
	m = 0;
	for (register int i = 1, now = 0; i <= n; ++i)
		if (a[i] == '1') cnt[i] = m, now ^= 1;
		else ++m, b[m] = now ^ '0', cnt[i] = m, now = 0;
	h[0] = pw[0] = node(1, 1);
	for (register int i = 1; i <= m; ++i) pw[i] = pw[i - 1] * node(233, 341);
	for (register int i = 1; i <= m; ++i) h[i] = add(h[i - 1], node(b[i], b[i]));
	nx[n] = 0;
	for (register int i = n; i; --i) nx[i - 1] = a[i] == '1' ? nx[i] + 1 : 0;
	read(q);
	while (q--){
		int l1, l2, len, r1, r2;
		read(l1), read(l2), read(len), --l1, --l2, r1 = l1 + len, r2 = l2 + len;
		if (cnt[r1] - cnt[l1] == cnt[r2] - cnt[l2]){
			if (cnt[r1] - cnt[l1] == 0){ prints("Yes"); continue; }
			int x1 = nx[l1] & 1, x2 = nx[l2] & 1;
			l1 += nx[l1] + 1, l2 += nx[l2] + 1;
			l1 = cnt[l1], l2 = cnt[l2], r1 = cnt[r1], r2 = cnt[r2], len = r1 - l1;
			if (x1 == x2 && query(h[l1], h[r1], len) == query(h[l2], h[r2], len)) prints("Yes"); else prints("No");
		}
		else prints("No");
	}
}