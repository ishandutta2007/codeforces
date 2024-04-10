# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, q, c[xn], sz[xn], par[xn], p[xn], ptr, P[xn], f[xn];
bool mark[xn];
pii E[xn], a[xn];
vector <int> Q[xn], vec[xn], adj[xn];
vector <int> st[xn];

bool cmp(int v, int u){ return p[v] > p[u];}
int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u, int ind){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	for (int x : vec[u]){
		vec[v].push_back(x);
		Q[ind].push_back(x);
	}
}
void DFS(int v, int x){
	mark[v] = true;
	st[x].push_back(v);
	c[v] = x;
	for (int u : adj[v]){
		if (mark[u]) continue;
		DFS(u, x);
	}
}
void get(int v){
	while (st[c[v]][P[c[v]]] == - 1) ++ P[c[v]];
	cout << p[st[c[v]][P[c[v]]]] << endl;
	p[st[c[v]][P[c[v]]]] = 0;
	f[st[c[v]][P[c[v]]]] = st[c[v]].size();
	st[c[v]].push_back(st[c[v]][P[c[v]]]);
	++ P[c[v]];
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i) cin >> p[i];
	for (int i = 1; i <= m; ++ i) cin >> E[i].A >> E[i].B;
	for (int i = 1; i <= q; ++ i){
		cin >> a[i].A >> a[i].B;
		if (a[i].A == 2) mark[a[i].B] = true;
	}
	for (int i = 1; i <= n; ++ i){
		sz[i] = 1;
		par[i] = i;
		vec[i].push_back(i);
	}
	for (int i = 1; i <= m; ++ i){
		adj[E[i].A].push_back(E[i].B);
		adj[E[i].B].push_back(E[i].A);
		if (mark[i]) continue;
		merge(E[i].A, E[i].B, 0);
	}
	for (int i = q; i >= 1; -- i){
		if (a[i].A == 1) continue;
		merge(E[a[i].B].A, E[a[i].B].B, i);
	}
	memset(mark, false, sizeof mark);
	for (int i = 1; i <= n; ++ i){
		if (mark[i]) continue;
		DFS(i, ++ ptr);
		sort(all(st[ptr]), cmp);
		for (int j = 0; j < st[ptr].size(); ++ j) f[st[ptr][j]] = j;
	}
	for (int i = 1; i <= q; ++ i){
		if (a[i].A == 1) get(a[i].B);
		else{
			++ ptr;
			for (int v : Q[i]){
				st[c[v]][f[v]] = - 1;
				c[v] = ptr;
				st[c[v]].push_back(v);
			}
			sort(all(st[ptr]), cmp);
			for (int j = 0; j < st[ptr].size(); ++ j) f[st[ptr][j]] = j;
		}
	}
 
    return 0;
}