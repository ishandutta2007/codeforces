#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using std :: vector;
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
int n, k, ans;
int edge, to[N << 1], pr[N << 1], hd[N], d[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge, ++d[u];
}
int dfs(int u, int fa = 0){
	if (d[u] == 1) return 0;
	vector<int> res;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) res.push_back(dfs(v, u) + 1);
	std :: sort(res.begin(), res.end());
	while (res.size() >= 2 && res[res.size() - 1] + res[res.size() - 2] > k)
		++ans, res.pop_back();
	return res[res.size() - 1];
}
int main(){
	n = read(), k = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	for (register int i = 1; i <= n; ++i)
		if (d[i] > 1) return dfs(i), printf("%d", ans + 1), 0;
}