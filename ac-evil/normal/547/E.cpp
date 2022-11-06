#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) (x & -x)
typedef long long ll;
const int N = 2e5 + 5, M = 26, Q = 5e5 + 5;
int n, q, ch[N][M], fa[N], fail[N], tot = 1, pos[N], ask[Q];
std::vector<int> tag[N], G[N];
char str[N]; ll ans[Q];
int ins(int n) {
	int o = 1;
	for (int i = 1; i <= n; i++) {
		int d = str[i] - 'a';
		if (!ch[o][d]) fa[ch[o][d] = ++tot] = o;
		o = ch[o][d];
	}
	return o;
}
void build() {
	std::queue<int> Q;
	for (int i = 0; i < M; i++)
		if (ch[1][i]) fail[ch[1][i]] = 1, Q.push(ch[1][i]);
		else ch[1][i] = 1;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < M; i++)
			if (ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], Q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
	}
	for (int i = 2; i <= tot; i++) G[fail[i]].pb(i);
}
int dfn[N], siz[N], dfs_clock = 0;
void dfs(int u) {
	dfn[u] = ++dfs_clock; siz[u] = 1;
	for (int v : G[u])
		dfs(v), siz[u] += siz[v];
}
ll bit[N];
void add(int i) {
	for (; i <= tot; i += lowbit(i)) bit[i]++;
}
ll qry(int i) {
	ll ans = 0;
	for (; i; i -= lowbit(i)) ans += bit[i];
	return ans;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str + 1);
		pos[i] = ins(strlen(str + 1));
	}
	build(); dfs(1);
	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d%d", &l, &r, &ask[i]);
		tag[l - 1].pb(-i), tag[r].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		int p = pos[i];
		while (p) add(dfn[p]), p = fa[p];
		for (int x : tag[i]) {
			int t = x < 0 ? -x : x, id = pos[ask[t]];
			ans[t] += (x < 0 ? -1 : 1) * (qry(dfn[id] + siz[id] - 1) - qry(dfn[id] - 1));
		}
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}