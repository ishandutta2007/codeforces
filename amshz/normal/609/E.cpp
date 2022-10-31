# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

struct edge{
	int V, U, ind, fl;
	ll W;
};

const int xn = 2e5+10;
const int xk = 1e2+10;

edge e[xn];
int sz[xn], par[xn], h[xn], s, start[xn], finish[xn];
ll MST;
vector <int> flor[xn];
vector <pii> adj[xn];
pii p[xn], state[xn];
bool mark[xn];

bool cmp(edge a1, edge a2){
	return a1.W < a2.W;
}
bool cmp2(edge a1, edge a2){
	return a1.ind < a2.ind;
}

int get_root(int v){
	if (par[v] == v) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v), u = get_root(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	
	par[u] = v;
	sz[v] += sz[u];
}

void DFS(int v, int d){
	mark[v] = true;
	h[v] = d;
	flor[d].pb(v);
	start[v] = s++;
	
	if (v == 1) state[v].S = 0;
	else{
		if (d%320 == 0) state[v].S = v, state[v].F = p[v].S;
		else state[v].F = max(state[p[v].F].F, p[v].S), state[v].S = state[p[v].F].S;
	}
	
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i].F;
		if (mark[u]) continue;
		
		p[u].F = v, p[u].S = adj[v][i].S;
		DFS(u, d+1);
	}
	finish[v] = s++;
}

int parv(int v, int d){
	int l = 0, r = flor[d].size();
	
	while (r-l > 1){
		int mid = (l+r)/2;
		
		if (start[flor[d][mid]] <= start[v]) l = mid;
		else r = mid;
	}
	
	return flor[d][l];
}

bool check(int x, int v, int u){
	int g = parv(v, x);
	return (start[g] < start[u] && finish[g] > finish[u]);
}

int lca(int v, int u){
	if (h[v] > h[u]) swap(v, u);
	
	int l = 0, r = h[v]+1;
	
	//cout << h[v] << endl;
	
	while (r-l > 1){
		int mid = (l+r)/2;
		//cout << l << sep << r << endl;
		if (check(mid, v, u)) l = mid;
		else r = mid;
	}
	
	return parv(v, l);
}

int maxp(int v, int u){
	int mx = 0;
	while (true){
		if (h[state[v].S]-1 < h[u]){
			while (v != u) mx = max(mx, p[v].S), v = p[v].F;
			break;
		}
		mx = max(mx, state[v].F);
		v = p[state[v].S].F;
	}
	return mx;
}

int solve(int v, int u){
	int g = lca(v, u);
	return max(maxp(v, g), maxp(u, g));
}

int main(){
	fast_io;
	
	int n, m;
	h[0] = -1;
	cin >> n >> m;
	
	for (int i=0; i<=n; i++) par[i] = i, sz[i] = 1;
	
	int v, u;
	ll w;
	//cout << 2 << endl;
	for (int i=0; i<m; i++) cin >> v >> u >> w, e[i].V = v, e[i].U = u, e[i].W = w, e[i].ind = i, e[i].fl = false;
	
	sort(e, e+m, cmp);
	
	
	for (int i=0; i<m; i++){
		v = e[i].V, u = e[i].U;
		if (get_root(v) == get_root(u)) continue;
		
		merge(v, u);
		adj[v].pb({u, e[i].W}), adj[u].pb({v, e[i].W});
		e[i].fl = true;
		MST += e[i].W;
	}
	
	//cout << MST << endl;
	
	DFS(1, 0);
	
	sort(e, e+m, cmp2);
	
	
	for (int i=0; i<m; i++){
		if (e[i].fl) cout << MST << endl;
		else cout << MST - solve(e[i].V, e[i].U) + e[i].W << endl;
	}
	
	return 0;
}