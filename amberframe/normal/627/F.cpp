#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n) * (n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<int, int> mp;
typedef long long LL ;
const int maxn = 4e5 + 5;

vector<int> adj[maxn];
#define add(u, v) adj[u].pb(v)
int a[maxn], b[maxn], n, par[maxn], a0, b0; LL ans;
int dep[maxn], id[maxn], idx;
vector< mp> chain; bool vis[maxn];
void dfs(int u)
{
	id[++idx] = u;
	for (auto v : adj[u]) if (v != par[u])
		{par[v] = u; dep[v] = dep[u] + 1; dfs(v);}
}
int lca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] > dep[v]) u = par[u];
	while (u != v) u = par[u], v = par[v];
	return u;
}
int dist(int u, int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int stk[maxn];
void move(int *a, int u, int v)
{
	int t = lca(u, v), top = 0;
	for (int i = u; i != t; i = par[i]) swap(a[par[i]], a[i]);
	for (int i = v; i != t; i = par[i]) stk[++top] = i;
	while (top) swap(a[par[stk[top]]], a[stk[top]]), --top;
}
bool check()
{
	repi(n) if (a[i] != b[i]) return false;
	return true;
}
int cir[maxn], tot;
int main()
{
	#ifdef FILE_TEST
		freopen("puzzle.in", "r", stdin);
	#endif
	
	scanf("%d", &n);
	repi(n) scanf("%d", &a[i]);
	repi(n) scanf("%d", &b[i]);
	for (int u, v, i = 1; i < n ; i++)
		scanf("%d %d", &u, &v), add(u, v), add(v, u);
	
	repi(n) a[i] == 0 ? a0 = i : 0;
	repi(n) b[i] == 0 ? b0 = i : 0;
	dfs(b0); move(a, a0, b0);
	if (check()) {printf("0 %d", dist(a0, b0)); return 0;}
	
	repi(n) if (a[i] == b[i]) vis[i] = true;
	
	per(i, n) if (! vis[id[i]])
	{
		int u = id[i], v = u; vis[u] = true;
		while (par[v] && !vis[par[v]]) v = par[v], vis[v] = true;
		chain.pb( mp(u, v));
	}
	move(a, b0, a0);
	if (chain.size() > 2) {printf("-1"); return 0;}
	if (chain.size() == 2)
	{
		if (par[chain[0].second] != par[chain[1].second]) {printf("-1"); return 0;}
		int t = par[chain[0].second], ansu = chain[0].first, ansv = chain[1].first;
		for (int i = ansu ; i != t ; i = par[i]) cir[++tot] = i;
		int mid = tot;
		for (int i = ansv ; i != t ; i = par[i]) cir[++tot] = i;
		reverse(cir + mid + 1, cir + tot + 1);
		
		int brk = t, tmp = 0;
		if (dep[lca(a0, ansu)] > dep[brk])
		{
			brk = lca(a0, ansu);
			tmp = dist(brk, t);
			move(a, a0, brk); move(b, b0, t); move(a, brk, t);
		}
		else if (dep[lca(a0, ansv)] > dep[brk])
		{
			brk = lca(a0, ansv);
			tmp = tot + 1 - dist(brk, t);
			move(a, a0, brk); move(b, b0, t);
			move(a, brk, ansv);
			swap(a[ansu], a[ansv]);
			move(a, ansu, t);
		}
		else
		{
			move(a, a0, t); move(b, b0, t);
		}
		
		ans = dist(a0, brk) + dist(b0, t);
		int shift = 0 ;
		repi(tot) cir[i + tot] = cir[i];
		repi(tot) if (a[cir[i]] == b[cir[1]]) shift = i - 1;
		repi(tot) if (a[cir[i + shift]] != b[cir[i]]) {printf("-1"); return 0;}
		ans += min((LL) (tot + 1) * (tot - shift) - tmp, (LL) (tot + 1) * shift + tmp);
		if (ansu > ansv) swap(ansu, ansv);
		printf("%d %d %I64d", ansu, ansv, ans);
	}
	if (chain.size() == 1)
	{
		int bot = chain[0].first, t = par[chain[0].second];
		for (int i = bot ; i != t ; i = par[i]) cir[++tot] = i;
		
		int brk = lca(a0, bot); dep[brk] < dep[t] ? brk = t : 0;
		ans = dist(a0, brk) + dist(b0, t); move(a, a0, brk); move(b, b0, t);
		int tmp = dist(brk, t), shift = 0 ; move(a, brk, t);
		repi(tot) cir[i + tot] = cir[i];
		repi(tot) if (a[cir[i]] == b[cir[1]]) shift = i - 1;
		repi(tot) if (a[cir[i + shift]] != b[cir[i]]) {printf("-1"); return 0;}
		ans += min((LL) (tot + 1) * (tot - shift) - tmp, (LL) (tot + 1) * shift + tmp);
		if (bot > t) swap(bot, t);
		printf("%d %d %I64d", bot, t, ans);
	}
	return 0;
}