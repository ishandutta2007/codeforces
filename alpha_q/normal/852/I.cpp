#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxlog = 20;
vector<int> adj[maxn], t;
int n, m, p[maxn][maxlog], l[maxn], f[maxn], lg, in[maxn], out[maxn], counter, block;
 
void dfs(int u, int par) {
    t.push_back(u);
	in[u] = counter++;
	p[u][0] = par; 
	if(par + 1) 
		l[u] = l[par] + 1;
	for(int i=1; i<lg; i++)
		if(p[u][i-1] + 1)
			p[u][i] = p[p[u][i-1]][i-1];
	for(int v : adj[u]) if(par-v) dfs(v,u);
	t.push_back(u);
	out[u] = counter++;
}
int lca(int u, int v) {
	if(l[u] < l[v]) swap(u,v);
	for(int i=lg; i>=0; i--) 
		if(p[u][i] + 1 && l[p[u][i]] >= l[v])
			u = p[u][i];
	if(v == u) return u;
	for(int i=lg; i>=0; i--) 
		if(p[u][i] - p[v][i])
			v = p[v][i], u = p[u][i];
	return p[u][0];
}
struct query{
	int l, r, u, id, flag;
	bool operator <(const query &p) const{
		int a = l/block, b = p.l/block; 
		return a == b ? r < p.r : a < b;
	}
} Q[100100];

int b[maxn]; 
int cnt[2][2*maxn], vis[maxn];
ll ans;

void check(int i) {
	int u = t[i], x = f[u];
	if(vis[u]) {
		ans -= 1ll * cnt[0][x] * cnt[1][x]; 
		cnt[b[u]][x]++; 
		ans += 1ll * cnt[0][x] * cnt[1][x]; 
	} else {
		ans -= 1ll * cnt[0][x] * cnt[1][x]; 
		cnt[b[u]][x]--; 
		ans += 1ll * cnt[0][x] * cnt[1][x]; 
	} vis[u] = 1 - vis[u];
}
void compress() {
	unordered_map<int,int> com; 
	vector<int> v; 
	for(int i=0; i<n; i++) v.push_back(f[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=0; i<v.size(); i++) 
		com[v[i]] = i;
	for(int i=0; i<n; i++) 
		f[i] = com[f[i]];
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n); 
	for(int i = 0; i < n; i++) 
		scanf("%d", &b[i]);
	for(int i=0; i<n; i++) 
		scanf("%d", &f[i]);
	compress();

	for(int i=0; i<n-1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v); 
		adj[v].push_back(u);
	} 
	while((1<<lg) <= n) lg++;
	memset(p, -1, sizeof p);
	dfs(0, -1);
	block = sqrt(t.size()) + 1;
	cin >> m; 
	for(int i=0; i<m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		u--, v--;
		if(in[u] > in[v]) swap(u,v);
		int P = lca(u,v); 
		Q[i].u = P; 
		Q[i].id = i;
		if(P == u) {
			Q[i].l = in[u], Q[i].r = in[v];
			Q[i].flag = 0;
		}
		else {
			Q[i].l = out[u], Q[i].r = in[v];
			Q[i].flag = 1;
		}
	} 
	sort(Q, Q+m);
	ll sol[m]; int l=0, r = -1;
	for(int i=0; i<m; i++) {
		int ql = Q[i].l, qr = Q[i].r;
		while(l > ql) check(--l);
		while(r < qr) check(++r);
		while(l < ql) check(l++);
		while(r > qr) check(r--);
		sol[Q[i].id] = ans;
		if(Q[i].flag) {	
			check(in[Q[i].u]);
			sol[Q[i].id] = ans;
			check(in[Q[i].u]);
		}
	} 
	for(int i=0; i<m; i++)
		printf("%lld\n", sol[i]);
}