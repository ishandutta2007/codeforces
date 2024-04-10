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
const int N = 1005;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const char op[] = "UDLRX", op_[] = "DURLX";
int n;
struct node{
	int x, y;
	bool operator == (const node &rhs) const { return x == rhs.x && y == rhs.y; }
}a[N][N];
char s[N][N];
void bfs(node st){
	std::vector<node> Q;
	Q.push_back(st);
	for (register int i = 0; i < (int)Q.size(); ++i){
		node u = Q[i], v;
		for (register int j = 0; j < 4; ++j){
			v = u, v.x += dx[j], v.y += dy[j];
			if (!s[v.x][v.y] && a[v.x][v.y] == st) s[v.x][v.y] = op_[j], Q.push_back(v);
		}
	}
}
int main(){
	read(n);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j){
			read(a[i][j].x), read(a[i][j].y);
			if (i == a[i][j].x && j == a[i][j].y) s[i][j] = 'X';
		}
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			if (s[i][j] == 'X') bfs(a[i][j]);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			if (!s[i][j] && ~a[i][j].x) return prints("INVALID"), 0;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			if (!s[i][j]){
				for (register int k = 0; k < 4; ++k){
					node v = {i + dx[k], j + dy[k]};
					if (a[v.x][v.y].x == -1){ s[i][j] = op[k]; break; }
				}
				if (!s[i][j]) return prints("INVALID"), 0;
			}
	prints("VALID");
	for (register int i = 1; i <= n; ++i) prints(s[i] + 1);
}