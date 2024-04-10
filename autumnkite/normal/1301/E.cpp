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
const int N = 505;
char tmp[N];
int n, m, q, a[N][N], c[4][N][N];
int w[N][N], s[N][N];
struct node{
	int x0, y0, x1, y1, ans;
}Q[300005];
void init_sum(int a[N][N], int s[N][N], int op = -1){
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (~op ? (a[i][j] != op) : a[i][j]);
}
int query_sum(int s[N][N], int x0, int y0, int x1, int y1){
	if (x0 >= x1 || y0 >= y1) return 0;
	return s[x1][y1] - s[x1][y0] - s[x0][y1] + s[x0][y0];
}
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 1; i <= n; ++i){
		read(tmp + 1);
		for (register int j = 1; j <= m; ++j){
			if (tmp[j] == 'R') a[i][j] = 0;
			if (tmp[j] == 'Y') a[i][j] = 1;
			if (tmp[j] == 'B') a[i][j] = 2;
			if (tmp[j] == 'G') a[i][j] = 3;
		}
	}
	for (register int i = 1; i <= q; ++i)
		Q[i].x0 = read() - 1, Q[i].y0 = read() - 1, Q[i].x1 = read(), Q[i].y1 = read(), Q[i].ans = 0;
	for (register int k = 0; k < 4; ++k) init_sum(a, c[k], k);
	for (register int k = std::min(n, m) >> 1; k; --k){
		for (register int i = k; i <= n - k; ++i)
			for (register int j = k; j <= m - k; ++j)
				w[i][j] = !query_sum(c[0], i - k, j - k, i, j) && !query_sum(c[1], i, j - k, i + k, j)
				  && !query_sum(c[2], i, j, i + k, j + k) && !query_sum(c[3], i - k, j, i, j + k);
		init_sum(w, s);
		for (register int i = 1; i <= q; ++i){
			if (Q[i].ans) continue;
			if (query_sum(s, Q[i].x0 + k - 1, Q[i].y0 + k - 1, Q[i].x1 - k, Q[i].y1 - k))
				Q[i].ans = k;
		}
	}
	for (register int i = 1; i <= q; ++i) print(4 * Q[i].ans * Q[i].ans);
}