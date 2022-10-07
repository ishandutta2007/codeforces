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
void print(long long x, char ch = '\n'){
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
int n, g, b, need;
bool check(long long md){
	long long cg = md / (g + b) * g + std::min(md % (g + b), 1ll * g);
	if (cg >= need && md >= n) return 1; else return 0;
}
void solve(){
	n = read(), g = read(), b = read();
	if (g >= b) return print(n), void(0);
	need = (n + 1) >> 1;
	long long l = 1, r = 1ll * n * (g + b), md, ans = 0;
	while (l <= r) if (check(md = (l + r) >> 1)) r = md - 1, ans = md; else l = md + 1;
	print(ans);
}
int main(){
	int T = read();
	while (T--) solve();
}