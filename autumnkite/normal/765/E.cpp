#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
using std :: vector;
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, cnt, Len;
int edge, to[N << 1], pr[N << 1], bo[N << 1], Bo[N << 1], hd[N], d[N], D[N];
int cn, num[N];
void addedge(int u, int v){
	to[edge] = v, pr[edge] = hd[u], bo[edge] = 1, hd[u] = edge++, ++d[u];
}
struct node{
	int len, x, y;
	bool operator < (const node &res) const {
		return len < res.len || len == res.len && x < res.x;
	}
}a[N];
int dfs(int u, int fa = 0, int len = 0){
	// printf("dfs : %d %d %d\n", u, fa, len);
	if (D[u] > 2) return a[cnt].len = len, a[cnt].x = u, -1;
	for (register int i = hd[u], v; ~i; i = pr[i])
		if (bo[i] && (v = to[i]) != fa)
			return --d[u], --d[v], bo[i] = bo[i ^ 1] = 0, dfs(v, u, len + 1);
	return Len = len;
}
void Dfs(int u, int e, int fa = 0){
	// printf("Dfs : %d %d %d\n", u, e, fa);
	if (u == e) return;
	for (register int i = hd[u], v; ~i; i = pr[i])
		if (Bo[i] && (v = to[i]) != fa)
			++d[u], ++d[v], bo[i] = bo[i ^ 1] = 1, Dfs(v, e, u);
}
int Link(){
	int tn = 0;
	for (register int i = 1; i <= n; ++i) if (d[i]) ++tn;
	for (register int i = 1; i <= n; ++i)
		if (d[i] == 1) { dfs(i); break; }
	if (Len != tn - 1) return -1;
	while ((Len & 1) == 0) Len >>= 1;
	return Len;
}
int main(){
    memset(hd, -1, sizeof hd);
	n = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	for (register int i = 1; i <= n; ++i) if (d[i] == 1) num[++cn] = i;
	int flag = 1;
	while (flag){
		memcpy(D, d, sizeof D), memcpy(Bo, bo, sizeof Bo), cnt = 0;
		for (register int i = 1, tmp; i <= cn; ++i){
			a[++cnt].y = num[i], tmp = dfs(num[i]);
			if (tmp != -1){
				while ((tmp & 1) == 0) tmp >>= 1;
				return printf("%d", tmp), 0;
			}
		}
		// printf("d: "); for (register int i = 1; i <= n; ++i) printf("%d ", d[i]); putchar('\n');
		flag = 0, std :: sort(a + 1, a + 1 + cnt), cn = 0;
		for (register int i = 1, j; i <= cnt; i = j){
			j = i + 1;
			while (j <= cnt && a[j].len == a[i].len && a[j].x == a[i].x) ++j;
			if (j - i > 1) flag = 1;
			Dfs(a[i].y, a[i].x), num[++cn] = a[i].y;
		}
		// printf("num: "); for (register int i = 1; i <= cn; ++i) printf("%d ", num[i]); putchar('\n');
		// printf("d: "); for (register int i = 1; i <= n; ++i) printf("%d ", d[i]); putchar('\n');
		// for (register int i = 1; i <= n; ++i)
		// 	for (register int j = hd[i]; ~j; j = pr[j])
		// 		if (bo[j]) printf("%d %d\n", i, to[j]);
		// putchar('\n');
	}
	printf("%d", Link());
	// getchar(), getchar();
}