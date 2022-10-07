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
const int N = 200005, INF = 0x3f3f3f3f;
int n, q, s[N][26];
char a[N];
int main(){
	char ch;
	while (islower(ch = getchar())) a[++n] = ch;
	for (register int i = 1; i <= n; ++i){
		for (register int j = 0; j < 26; ++j) s[i][j] = s[i - 1][j];
		++s[i][a[i] - 'a'];
	}
	q = read();
	while (q--){
		int l = read(), r = read(), cnt = 0;
		for (register int i = 0; i < 26; ++i)
			if (s[r][i] - s[l - 1][i]) ++cnt;
		if (l == r || cnt >= 3 || a[l] != a[r]) puts("Yes");
		else puts("No");
	}
}