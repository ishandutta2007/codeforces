# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100051;
const int MAXV = 10000051;
const int MAXP = 700051;
const int P = 1000000007;
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int n, q;
int p[MAXV], psz;
bool flag[MAXV];
int b[MAXV];
int a[MAXP], bp[MAXP], asz;
vector <int> adj[MAXP], cdj[MAXP];
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int dsz;
int dfn[MAXN], sz[MAXN], dep[MAXN], fa[21][MAXN];
void dfs0(int nw){
	dfn[nw] = ++dsz;
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[0][nw]) continue;
		dep[nxtn] = dep[nw] + 1;
		fa[0][nxtn] = nw;
		dfs0(nxtn);
		sz[nw] += sz[nxtn];
	}
}
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--){
		if (dep[u] - (1 << i) >= dep[v]) u = fa[i][u];
	}
	if (u == v) return u;
	for (int i = 20; i >= 0; i--){
		if (fa[i][u] != fa[i][v]){
			u = fa[i][u];
			v = fa[i][v];
		}
	}
	return fa[0][u];
}
int w[MAXN];
int qu[MAXN], qv[MAXN], ql[MAXN];
ll ans[MAXN];
struct BIT{
	int c[MAXN];
	void modify(int pos, int nm){
		for (; pos <= n; pos += pos & (-pos)) c[pos] += nm;
	}
	int getsum(int pos){
		int ans = 0;
		for (; pos; pos ^= pos & (-pos)) ans += c[pos];
		return ans;
	}
} bt;
int main(){
	ios::sync_with_stdio(false);
	for (int i = 2; i < MAXV; i++){
		if (!flag[i]) p[++psz] = i;
		for (int j = 1; j <= psz && i * p[j] < MAXV; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
	for (int i = 1; i <= psz; i++){
		for (ll j = p[i]; j < MAXV; j *= p[i]){
			a[++asz] = j;
			bp[asz] = p[i];
			b[j] = asz;
		}
	}
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	dfs0(1);
	for (int j = 1; j <= 20; j++){
		for (int i = 1; i <= n; i++){
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
		}
	}
	for (int i = 1; i <= n; i++){
		cin >> w[i];
		for (int j = 1; j <= psz && 1ll * p[j] * p[j] <= w[i]; j++){
			if (w[i] % p[j]) continue;
			for (ll k = p[j]; k <= w[i]; k *= p[j]){
				if (w[i] % k) break;
				adj[b[k]].push_back(i);
			}
			while (w[i] % p[j] == 0) w[i] /= p[j];
		}
		if (w[i] > 1){
			adj[b[w[i]]].push_back(i);
			int pt = b[w[i]] + 1;
			while (a[pt] % a[pt - 1] == 0) pt++;
		}
	}
	cin >> q;
	for (int i = 1; i <= q; i++){
		int x;
		cin >> qu[i] >> qv[i] >> x;
		ql[i] = lca(qu[i], qv[i]);
		for (int j = 1; j <= psz && 1ll * p[j] * p[j] <= x; j++){
			if (x % p[j]) continue;
			ll nw = p[j];
			while (x % (nw * p[j]) == 0) nw *= p[j];
			cdj[b[nw]].push_back(i);
			x /= nw;
			// cout << "c " << nw << ' ' << i << '\n';
		}
		if (x > 1){
			cdj[b[x]].push_back(i);
			// cout << "c " << x << ' ' << i << '\n';
		}
		ans[i] = 1;
	}
	for (int i = 1; i <= asz; i++){
		if (bp[i] != bp[i - 1]){
			for (int k = i - 1; k >= 0 && bp[k] == bp[i - 1]; k--){
				for (int j = 0; j < adj[k].size(); j++){
					int nw = adj[k][j];
					bt.modify(dfn[nw], -1);
					bt.modify(dfn[nw] + sz[nw], 1);
				}
			}
		}
		for (int j = 0; j < adj[i].size(); j++){
			int nw = adj[i][j];
			bt.modify(dfn[nw], 1);
			bt.modify(dfn[nw] + sz[nw], -1);
		}
		for (int j = 0; j < cdj[i].size(); j++){
			int nw = cdj[i][j];
			int cnt = bt.getsum(dfn[qu[nw]]) + bt.getsum(dfn[qv[nw]]) - bt.getsum(dfn[ql[nw]]) - bt.getsum(dfn[fa[0][ql[nw]]]);
			ans[nw] = ans[nw] * pwr(bp[i], cnt) % P;
		}
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
	return 0;
}