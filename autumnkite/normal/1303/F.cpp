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
const int N = 305;
int n, m, q, cnt, nx, a[N][N], fa[N * N], f[2000005];
struct modpos{
	int x, y, t;
}p[2000005];
int get(int x, int y){ return (x - 1) * m + y; }
int find(int x){ return fa[x] == x ? x : (fa[x] = find(fa[x])); }
bool merge(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return 0;
	else return fa[y] = x, 1;
}
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = -1;
	for (register int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = -1;
	cnt = 1, p[1].x = read(), p[1].y = read(), nx = read(), --q;
	while (1){
		int c = nx;
		p[1].x = p[cnt].x, p[1].y = p[cnt].y, cnt = 1;
		while (1){
			if (!q) break;
			++cnt, p[cnt].x = read(), p[cnt].y = read(), nx = read(), --q;
			if (nx != c) break;
		}
		if (nx == c) ++cnt;
		for (register int i = 1; i < cnt; ++i)
			p[i].t = a[p[i].x][p[i].y], a[p[i].x][p[i].y] = c, f[i] = 0;
		int sum = 0;
		for (register int i = 1; i <= n * m; ++i) fa[i] = i;
		for (register int i = 1; i <= n; ++i)
			for (register int j = 1; j <= m; ++j)
				if (a[i][j] != c){
					++sum;
					if (j < m && a[i][j] == a[i][j + 1]) sum -= merge(get(i, j), get(i, j + 1));
					if (i < n && a[i][j] == a[i + 1][j]) sum -= merge(get(i, j), get(i + 1, j));
				}
		for (register int i = cnt - 1; i; --i)
			if (p[i].t != c){
				int x = p[i].x, y = p[i].y;
				f[i] += sum;
				++sum, a[x][y] = p[i].t;
				if (y < m && a[x][y] == a[x][y + 1]) sum -= merge(get(x, y), get(x, y + 1));
				if (x < n && a[x][y] == a[x + 1][y]) sum -= merge(get(x, y), get(x + 1, y));
				if (y > 1 && a[x][y] == a[x][y - 1]) sum -= merge(get(x, y), get(x, y - 1));
				if (x > 1 && a[x][y] == a[x - 1][y]) sum -= merge(get(x, y), get(x - 1, y));
			}
		sum = 0;
		for (register int i = 1; i <= n * m; ++i) fa[i] = i;
		for (register int i = 1; i < cnt; ++i)
			if (p[i].t != c){
				int x = p[i].x, y = p[i].y;
				++sum, a[x][y] = c;
				if (y < m && a[x][y] == a[x][y + 1]) sum -= merge(get(x, y), get(x, y + 1));
				if (x < n && a[x][y] == a[x + 1][y]) sum -= merge(get(x, y), get(x + 1, y));
				if (y > 1 && a[x][y] == a[x][y - 1]) sum -= merge(get(x, y), get(x, y - 1));
				if (x > 1 && a[x][y] == a[x - 1][y]) sum -= merge(get(x, y), get(x - 1, y));
				f[i] += sum;
			}
		for (register int i = 1; i < cnt; ++i) if (p[i].t == c) f[i] = f[i - 1];
		for (register int i = 1; i < cnt; ++i) print(f[i]);
		if (nx == c) break;
	}
}