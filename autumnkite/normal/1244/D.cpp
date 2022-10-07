#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
void print(long long x){
	if (x == 0) return putchar('0'), void(0);
	int cnt = 0, d[25];
	for (x < 0 ? x = -x, putchar('-') : 0; x; x /= 10) d[++cnt] = x % 10;
	while (cnt) putchar(d[cnt] ^ '0'), --cnt;
}
#define N 100005
int n, c[3][N], p[N], id[3], ansid[3], col[N];
std :: vector<int> E[N];
long long ans;
int main(){
	n = read();
	for (register int i = 0; i < 3; ++i)
		for (register int j = 1; j <= n; ++j)
			c[i][j] = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), E[u].push_back(v), E[v].push_back(u);
	for (register int i = 1; i <= n; ++i)
		if (E[i].size() > 2) return puts("-1"), 0;
	for (register int i = 1; i <= n; ++i)
		if (E[i].size() == 1){ p[1] = i; break; }
	for (register int i = 2; i <= n; ++i)
		for (int v : E[p[i - 1]]) if (v != p[i - 2]) p[i] = v;
	for (register int i = 0; i < 3; ++i) id[i] = i;
	ans = 1e18;
	while (1){
		long long s = 0;
		for (register int i = 1; i <= n; ++i) s += c[id[i % 3]][p[i]];
		if (s < ans) ans = s, memcpy(ansid, id, sizeof ansid);
		if (!std :: next_permutation(id, id + 3)) break;
	}
	for (register int i = 1; i <= n; ++i) col[p[i]] = ansid[i % 3] + 1;
	print(ans), putchar('\n');
	for (register int i = 1; i <= n; ++i) print(col[i]), putchar(' ');
}