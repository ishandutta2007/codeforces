#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
long long read(){
	register long long x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}
#define N 100005
#define P 1000000007
int n, ans;
long long val[N];
std :: vector<int> E[N];
std :: vector< std :: pair<long long, int> > g[N];
void dfs(int u, int fa = 0){
	g[u] = g[fa];
	for (register int i = 0; i < g[u].size(); ++i) g[u][i].first = gcd(g[u][i].first, val[u]);
	g[u].push_back(std :: make_pair(val[u], 1));
	std :: vector< std :: pair<long long, int> > tmp;
	tmp.push_back(g[u][0]);
	for (register int i = 1; i < g[u].size(); ++i)
		if (g[u][i].first == tmp.back().first) tmp.back().second += g[u][i].second;
		else tmp.push_back(g[u][i]);
	g[u] = tmp;
	for (auto v : g[u]) ans = (ans + v.first * v.second) % P;
	for (int v : E[u]) if (v != fa) dfs(v, u);
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) val[i] = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), E[u].push_back(v), E[v].push_back(u);
	dfs(1);
	printf("%d\n", ans);
}