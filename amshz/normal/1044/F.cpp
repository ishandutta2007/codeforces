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
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, q, L[xn], R[xn], par[xm][xn];
int lazy[xn << 2], ptr, H[xn], res;
pii seg[xn << 2];
vector <int> adj[xn];
map <pii, bool> mp;

void DFS(int v){
	L[v] = ptr ++;
	R[v] = ptr;
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		par[0][u] = v;
		H[u] = H[v] + 1;
		DFS(u);
		R[v] = R[u];
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((H[u] - H[v]) >= (1 << i))
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
int find_par(int v, int d){
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= d)
			v = par[i][v], d -= (1 << i);
	return v;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].B = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id].B = seg[id << 1].B + seg[id << 1 | 1].B;
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id].A += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = seg[id << 1];
	if (seg[id << 1 | 1].A == seg[id].A)
		seg[id].B += seg[id << 1 | 1].B;
	else if (seg[id << 1 | 1].A > seg[id].A)
		seg[id] = seg[id << 1 | 1];
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++ i){
    	int v, u;
    	cin >> v >> u;
    	adj[v].push_back(u);
    	adj[u].push_back(v);
	}
	DFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	build(1, 1, n + 1);
	while (q --){
		int v, u;
		cin >> v >> u;
		if (H[v] > H[u]) swap(v, u);
		int lca = LCA(v, u);
		if (!mp[{v, u}]){
			mp[{v, u}] = mp[{u, v}] = true;
			if (lca == v){
				int x = find_par(u, H[u] - H[v] - 1);
				update(1, 0, ptr, L[x], R[x], - 1);
				update(1, 0, ptr, L[u], R[u], 1);
			}
			else{
				update(1, 0, ptr, L[v], R[v], 1);
				update(1, 0, ptr, L[u], R[u], 1);
				++ res;
			}
		}
		else{
			mp[{v, u}] = mp[{u, v}] = false;
			if (lca == v){
				int x = find_par(u, H[u] - H[v] - 1);
				update(1, 0, ptr, L[x], R[x], 1);
				update(1, 0, ptr, L[u], R[u], - 1);
			}
			else{
				update(1, 0, ptr, L[v], R[v], - 1);
				update(1, 0, ptr, L[u], R[u], - 1);
				-- res;
			}
		}
		if (seg[1].A == res)
			cout << seg[1].B << endl;
		else
			cout << 0 << endl;
	}
 
    return 0;
}