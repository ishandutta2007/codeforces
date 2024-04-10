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
const int N = 3505, INF = 0x3f3f3f3f;
int n, m, k, a[N], ans;
void solve(){
	n = read(), m = read() - 1, k = std::min(m, read());
	for (register int i = 1; i <= n; ++i) a[i] = read();
	ans = 0;
	for (register int i = 1; i <= k + 1; ++i){
		int j = i + n - k - 1, s = INF;
		for (register int l = i; l <= j - (n - m) + 1; ++l){
			int r = l + n - m - 1;
			s = std::min(s, std::max(a[l], a[r]));
		}
		ans = std::max(ans, s);
	}
	print(ans);
}
int main(){
	int T = read();
	while (T--) solve();
}