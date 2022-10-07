#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <set>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, m, q, out[N];
std :: vector<int> in[N];
long long ans;
int main(){
	n = read(), m = read();
	for (register int i = 1, u, v; i <= m; ++i){
		u = read(), v = read();
		if (u > v) std :: swap(u, v);
		in[u].push_back(v), ++out[v];
	}
	for (register int i = 1; i <= n; ++i) ans += 1ll * in[i].size() * out[i];
	printf("%lld\n", ans);
	q = read();
	for (register int i = 1; i <= q; ++i){
		int u = read();
		ans -= 1ll * in[u].size() * out[u];
		for (int v : in[u])
			ans -= 1ll * in[v].size() * out[v], in[v].push_back(u), --out[v], ans += 1ll * in[v].size() * out[v], ++out[u];
		in[u].clear();
		printf("%lld\n", ans);
	}
}