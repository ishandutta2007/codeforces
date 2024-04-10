// khodaya khodet komak kon
// Maybe on the Moon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = 8 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 2e18 + 10;
const int mod = 998244353;
const int base = 257;
 
struct DSU{
	int par[xn];
	int sz[xn];
	DSU(){
		for (int i=1; i<xn; i++) par[i]=i;
		for (int i=1; i<xn; i++) sz[i]=1;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (sz[x]>sz[y]) swap(x, y);
		par[x]=y;
		sz[y]+=sz[x];
	}
} dsu;
 
int n, m, root=1, ps[xn], H[xn], P[xm][xn];
int mark[xn], xr, mn = inf;
ll ans, ted;
vector<int> G[xn];
vector<int> out[xn];
vector <pip> E;
vector <pii> adj[xn];
bool fl[xn];
 
void DFS(int v, int p = - 1){
	for (int i = 1; i < xm; ++ i)
		P[i][v] = P[i - 1][P[i - 1][v]];
	for (pii u : adj[v]){
		if (u.A == p)
			continue;
		H[u.A] = H[v] + 1;
		ps[u.A] = ps[v] + (u.B == 0);
		ted += (u.B == 0);
		P[0][u.A] = v;
		DFS(u.A, v);
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = P[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (P[i][v] != P[i][u])
			v = P[i][v], u = P[i][u];
	return P[0][v];
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i = 0; i< m ; ++ i){
		int v, u, w;
		cin>>u>>v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
		E.push_back({w, {v, u}});
		xr ^= w;
	}
	for (int i=2; i<=n; i++) if (G[i].size()<G[root].size()) root=i;
	for (int i=0; i<=n; i++) mark[i]=2;
	for (int i:G[root]) mark[i]=1;
	for (int i=1; i<=n; i++) if (mark[i]==2) dsu.join(root, i);
	
	for (int i:G[root]){
		int tmp=0;
		for (int j:G[i]){
			if (mark[j]==2) tmp++;
			else mark[j]=0;
		}
		if (tmp<n-G[root].size()) dsu.join(root, i);
		for (int j:G[root]) if (mark[j]==1) dsu.join(i, j);
		for (int j:G[i]) if (mark[j]!=2) mark[j]=1;
	}
	sort(all(E));
	int mf = n - 1;
	for (pip e : E){
		int w = e.A, v = e.B.A, u = e.B.B;
		if (dsu.get(v) == dsu.get(u))
			continue;
		ans += w;
		dsu.join(v, u);
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
		-- mf;
	}
	ted = 1ll * n * (n - 1) / 2;
	if (mf + m != ted)
		kill(ans);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j < i; ++ j)
			fl[j] = false;
		for (int u : G[i])
			fl[u] = true;
		for (int j = 1; j < i; ++ j){
			if (fl[j])
				continue;
			adj[i].push_back({j, 0});
			adj[j].push_back({i, 0});
		}
	}
	ted = 0;
	DFS(1);
	for (pip e : E){
		int w = e.A, v = e.B.A, u = e.B.B;
		if (H[v] < H[u])
			swap(v, u);
		int lca = LCA(v, u);
		if (ps[v] + ps[u] - 2 * ps[lca])
			mn = min(mn, w);
	}
	mn = min(mn, xr);
	kill(ans + mn);
		
	return 0;
}