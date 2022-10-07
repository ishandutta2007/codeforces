#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int read(char *s){
	int n = 0;
	char ch = getchar();
	for (; isspace(ch) && ch != EOF; ch = getchar()) ;
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
	return s[n] = '\0', n;
}
char pbuf[1 << 23], *pp = pbuf;
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
void print(const char *s, int n = -1, char ch = '\n'){
	if (n == -1) n = strlen(s);
	for (register int i = 0; i < n; ++i) putchar(s[i]);
	putchar(ch);
}
const int N = 100005, INF = 0x3f3f3f3f;
int n, a[N];
int abs(int a){ return a > 0 ? a : -a; }
void solve(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	int ans = 0, l = INF, r = -INF;
	for (register int i = 1; i < n; ++i)
		if (~a[i] && ~a[i + 1]) ans = std::max(ans, abs(a[i] - a[i + 1]));
		else if (~a[i + 1]) l = std::min(l, a[i + 1]), r = std::max(r, a[i + 1]);
		else if (~a[i]) l = std::min(l, a[i]), r = std::max(r, a[i]);
	if (l > r) return print(ans, ' '), print(0), void(0);
	int k = (l + r) >> 1;
	print(std::max(ans, std::max(k - l, r - k)), ' '), print(k);
}
int main(){
	int T = read();
	while (T--) solve();
}