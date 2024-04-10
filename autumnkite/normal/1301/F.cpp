#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
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
const int N = 1000055, INF = 0x3f3f3f3f;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int n, m, k, q, col[N];
std::vector<int> id[40];
int dis[40][N], h, t, Q[N];
int abs(int a){ return a > 0 ? a : -a; }
int GetID(int x, int y){ return x * m + y; }
void push(int *dis, int u, int d){
	if (dis[u] == INF) Q[++t] = u, dis[u] = d;
}
void BFS(int c, int *dis){
	for (register int i = 0; i < n * m + k; ++i) dis[i] = INF;
	h = 0, t = 1, Q[t] = n * m + c, dis[n * m + c] = 0;
	while (h < t){
		int now = h + 1, nd = dis[Q[now]];
		while (now < t && dis[Q[now + 1]] == nd) ++now;
		for (register int i = h + 1; i <= now; ++i){
			int u = Q[i];
			if (u >= n * m){
				for (int v : id[u - n * m]) push(dis, v, nd + 1);
				continue;
			}
			push(dis, n * m + col[u], nd + 1);
		}
		for (register int i = h + 1; i <= now; ++i){
			int u = Q[i];
			if (u >= n * m) continue;
			for (register int j = 0; j < 4; ++j){
				int x = u / m + dx[j], y = u % m + dy[j];
				if (0 <= x && x < n && 0 <= y && y < m)
					push(dis, GetID(x, y), nd + 2);
			}
		}
		h = now;
	}
}
int main(){
	n = read(), m = read(), k = read();
	for (register int i = 0; i < n * m; ++i)
		col[i] = read() - 1, id[col[i]].push_back(i);
	for (register int i = 0; i < k; ++i){
		BFS(i, dis[i]);
		// for (register int j = 0; j < n * m + k; ++j)
		// 	print(dis[i][j], ' ');
		// putchar('\n');
	}
	q = read();
	while (q--){
		int x0 = read() - 1, y0 = read() - 1, x1 = read() - 1, y1 = read() - 1;
		int u = GetID(x0, y0), v = GetID(x1, y1);
		int ans = abs(x1 - x0) + abs(y1 - y0);
		for (register int i = 0; i < k; ++i)
			ans = std::min(ans, dis[i][u] / 2 + dis[i][v] / 2 + 1);
		print(ans);
	}
}