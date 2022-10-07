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
	for (; isspace(ch); ch = getchar()) ;
	for (; !isspace(ch); ch = getchar()) s[++n] = ch;
	s[n + 1] = '\0';
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
const int N = 1000005, P = 998244353;
int n, nl, nr, zl[N], zr[N], f[N], s[N];
char a[N], l[N], r[N];
void z_algo(int *z, char *s, int n){
	z[1] = n;
	for (register int i = 2, l = 1, r = 1; i <= n; ++i){
		z[i] = i > r ? 0 : std::min(r - i + 1, z[i - l + 1]);
		while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}
int z[N << 1];
char t[N << 1];
void init(int nx, char *x, int *zx){
	for (register int i = 1; i <= nx; ++i) t[i] = x[i];
	t[nx + 1] = '#';
	for (register int i = 1; i <= n; ++i) t[nx + 1 + i] = a[i];
	z_algo(z, t, nx + n + 1);
	for (register int i = 1; i <= n; ++i) zx[i] = z[nx + 1 + i];
}
void inc(int &a, int b){ (a += b) >= P ? a -= P : 0; }
int plus(int a, int b){ return (a += b) >= P ? a - P : a; }
int minus(int a, int b){ return a < b ? a + P - b : a - b; }
int main(){
	n = read(a), nl = read(l), nr = read(r);
	init(nl, l, zl), init(nr, r, zr);
	f[0] = 1;
	if (a[1] == '0') s[0] = 0; else s[0] = 1;
	for (register int i = 1; i <= n; ++i){
		int L = i - nr, R = i - nl, pl = zl[R + 1] + 1, pr = zr[L + 1] + 1;
		if (pl <= nl && a[R + pl] < l[pl]) --R;
		if (pr <= nr && a[L + pr] > r[pr]) ++L;
		L = std::max(L, 0);
		if (L <= R) f[i] = minus(s[R], L ? s[L - 1] : 0); else f[i] = 0;
		if (a[i] == '0' && R == i - 1) inc(f[i], f[i - 1]);
		if (i < n && a[i + 1] == '0') s[i] = s[i - 1];
		else s[i] = plus(s[i - 1], f[i]);
	}
	print(f[n]);
}