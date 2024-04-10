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
const int N = 300005, INF = 0x3f3f3f3f;
int n, m, a[N], fa[N], w[N], sz[N], sum[N], col[N], ans;
std::vector<int> id[N];
void dec(int u){
	if (col[u] == -1) ans -= std::min(sum[u], sz[u] - sum[u]);
	if (col[u] == 0) ans -= sum[u];
	if (col[u] == 1) ans -= sz[u] - sum[u];
}
void inc(int u){
	if (col[u] == -1) ans += std::min(sum[u], sz[u] - sum[u]);
	if (col[u] == 0) ans += sum[u];
	if (col[u] == 1) ans += sz[u] - sum[u];
}
int find(int x){
	if (fa[x] == x) return x;
	int u = find(fa[x]);
	return w[x] ^= w[fa[x]], fa[x] = u;
}
void merge(int x, int y, int nw){
	int u = find(x), v = find(y);
	if (u == v) return;
	nw ^= w[x], nw ^= w[y];
	dec(u), dec(v);
	if (~col[v]) col[u] = col[v] ^ nw;
	if (nw) sum[u] += sz[v] - sum[v]; else sum[u] += sum[v];
	sz[u] += sz[v], w[v] = nw, fa[v] = u;
	inc(u);
}
int main(){
	m = read(), n = read();
	for (register int i = 1; i <= m; ++i){
		while (!isdigit(a[i] = getchar())) ;
		a[i] ^= '0', a[i] ^= 1;
	}
	for (register int i = 1; i <= n; ++i){
		int c = read();
		for (register int j = 1; j <= c; ++j)
			id[read()].push_back(i);
	}
	ans = 0;
	for (register int i = 1; i <= n; ++i) fa[i] = i, w[i] = sum[i] = 0, sz[i] = 1, col[i] = -1;
	for (register int i = 1; i <= m; ++i){
		if (id[i].size() == 2) merge(id[i][0], id[i][1], a[i]);
		if (id[i].size() == 1){
			int x = id[i][0], u = find(x);
			dec(u), col[u] = w[x] ^ a[i], inc(u);
		}
		print(ans);
	}
}