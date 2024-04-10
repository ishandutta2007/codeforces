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
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[++n] = ch;
	return n;
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
const int N = 100005;
int n, a[N], pre[N], suf[N];
int f(int x, int y){ return (x | y) ^ y; }
void solve(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	pre[0] = suf[n + 1] = 0;
	for (register int i = 1; i <= n; ++i) pre[i] = pre[i - 1] | a[i];
	for (register int i = n; i >= 1; --i) suf[i] = suf[i + 1] | a[i];
	int ans = 0, id = 1;
	for (register int i = 1; i <= n; ++i){
		int t = f(a[i], pre[i - 1] | suf[i + 1]);
		if (t > ans) ans = t, id = i;
	}
	print(a[id], ' ');
	for (register int i = 1; i <= n; ++i)
		if (i != id) print(a[i], ' ');
	putchar('\n');
}
int main(){
	int T = 1;
	while (T--) solve();
}