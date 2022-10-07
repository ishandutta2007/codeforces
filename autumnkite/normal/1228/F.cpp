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
#define N 150005
int n, d[N];
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int nx[N], cnt, p[N];
std :: pair<int, int> dfs(int u, int fa = 0){
	nx[u] = fa;
	std :: pair<int, int> res = std :: make_pair(0, u), tmp;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			tmp = dfs(v, u), ++tmp.first;
			res = std :: max(res, tmp);
		}
	return res;
}
int son[N][2], id;
bool flag;
int build(int u, int fa = 0){
	int D = 0, res;
	std :: pair<int, int> tmp[5];
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) tmp[D++] = std :: make_pair(build(v, u), v);
	if (!D) return 0;
	std :: sort(tmp, tmp + D), res = tmp[D - 1].first + 1;
	if (D == 3)
		if (!id && tmp[0].first == tmp[1].first && tmp[0].first + 1 == tmp[2].first)
			id = u, son[u][0] = tmp[2].second, son[u][1] = n + 1, son[n + 1][0] = tmp[0].second, son[n + 1][1] = tmp[1].second;
		else flag = 0;
	if (D == 1){
		if (!id && tmp[0].first == 0) id = u, son[u][0] = tmp[0].second, son[u][1] = n + 1;
		else flag = 0;
	}
	if (D == 2)
		if (tmp[0].first == tmp[1].first) son[u][0] = tmp[0].second, son[u][1] = tmp[1].second;
		else flag = 0;
	return res;
}
int dep[N];
bool check(int u){
	if (!u) return 1;
	if (!check(son[u][0]) || !check(son[u][1]) || dep[son[u][0]] != dep[son[u][1]]) return 0;
	return dep[u] = dep[son[u][0]] + 1, 1;
}
int main(){
	n = read(), n = (1 << n) - 2;
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u), ++d[u], ++d[v];
	for (register int i = 1; i <= n; ++i)
		if (d[i] > 4) return printf("0\n"), 0;
	int s, t;
	t = dfs(s = dfs(1).second).second;
	for (register int u = t; u; u = nx[u]) p[++cnt] = u;
	if (cnt & 1){
		int rt = p[(cnt + 1) >> 1];
		flag = 1, build(rt);
		if (!flag) return printf("0\n"), 0;
		if (!check(rt)) return printf("0\n"), 0;
		return printf("1\n%d\n", id), 0;
	}
	else{
		int u = p[cnt / 2], v = p[cnt / 2 + 1];
		if (u > v) std :: swap(u, v);
		flag = 1, build(u, v), build(v, u);
		if (id || !flag) return printf("0\n"), 0;
		return printf("2\n%d %d\n", u, v), 0;
	}
}