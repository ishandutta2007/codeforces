#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
// char buf[1 << 23], *ps = buf, *pt = buf, pbuf[1 << 23], *pp = pbuf;
// #define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, m, q, cnt, rt[N], d[N], mx[N], cmx[N], g[N];
int edge, to[N << 1], pr[N << 1], hd[N];
std :: vector<int> f[N];
std :: vector<long long> sum[N];
std :: map<std :: pair<int, int>, long long> M;
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
void dfs(int Rt, int u, int fa = 0){
	rt[u] = Rt, mx[u] = cmx[u] = 0;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			dfs(Rt, v, u);
			if (mx[v] + 1 > mx[u]) cmx[u] = mx[u], mx[u] = mx[v] + 1;
			else if (mx[v] + 1 > cmx[u]) cmx[u] = mx[v] + 1;
		}
	d[Rt] = std :: max(d[Rt], mx[u] + cmx[u]);
}
void getg(int Rt, int u, int fa = 0){
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			if (mx[v] + 1 == mx[u]) g[v] = std :: max(g[u], cmx[u]) + 1;
			else g[v] = std :: max(g[u], mx[u]) + 1;
			getg(Rt, v, u);
		}
	g[u] = std :: max(g[u], mx[u]), f[Rt].push_back(g[u]);
}
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	for (register int i = 1; i <= n; ++i)
		if (!rt[i]){
			++cnt, dfs(cnt, i), getg(cnt, i), std :: sort(f[cnt].begin(), f[cnt].end());
			sum[cnt].resize(f[cnt].size());
			sum[cnt].back() = f[cnt].back();
			for (register int j = int(sum[cnt].size()) - 2; ~j; --j)
				sum[cnt][j] = sum[cnt][j + 1] + f[cnt][j];
		}
	while (q--){
		int x = rt[read()], y = rt[read()];
		if (x == y){ puts("-1"); continue; }
		if (f[x].size() > f[y].size()) std :: swap(x, y);
		long long ans = 0;
		if (M.count(std :: make_pair(x, y))) ans = M[std :: make_pair(x, y)];
		else{
			int k = std :: max(d[x], d[y]);
			long long s = 0;
			for (register int i = 0; i < f[x].size(); ++i){
				int j = std :: lower_bound(f[y].begin(), f[y].end(), k - f[x][i]) - f[y].begin();
				s += f[y].size() - j, ans += 1ll * (f[y].size() - j) * (f[x][i] + 1) + sum[y][j];
			}
			ans += (1ll * f[x].size() * f[y].size() - s) * k;
			M[std :: make_pair(x, y)] = ans;
		}
		printf("%.12lf\n", 1.0 * ans / (1ll * f[x].size() * f[y].size()));
	}
}