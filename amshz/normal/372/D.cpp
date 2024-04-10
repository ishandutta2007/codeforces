# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll MOD = 998244353;
const int TM = 30;
const int BASE = 257;
 
int n, par[xm][xn], seg[xn << 2], St[xn], R[xn], H[xn], ptr, ted, mx, k;
ll part[xn], ans;
bool mark[xn];
vector <pii> adj[xn];
set <int> st;
 
void update(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] += val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) update(id << 1, l, mid, pos, val);
	else update(id << 1 | 1, mid, r, pos, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
int get(int id, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return seg[id];
	if (qr <= l || r <= ql) return 0;
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}
void DFS(int v){
	mark[v] = true;
	St[v] = ++ ptr;
	R[v] = St[v] + 1;
	for (pii u : adj[v]){
		if (mark[u.A]) continue;
		H[u.A] = H[v] + 1;
		par[0][u.A] = v;
		part[u.A] = part[v] + u.B;
		DFS(u.A);
		R[v] = R[u.A];
	}
}
int find_par(int v, int d){
	for (int i = 16; i >= 0; -- i){
		if (H[par[i][v]] < d) continue;
		v = par[i][v];
	}
	return v;
}
int find_root(){
	int v = *st.begin();
	if (get(1, 0, xn, St[v], R[v]) == ted) return v;
	for (int i = 16; i >= 0; -- i){
		int u = par[i][v];
		if (u && get(1, 0, xn, St[u], R[u]) < ted) v = u;
	}
	return par[0][v];
}
int LCA(int v, int u){
	if (H[u] < H[v]) swap(v, u);
	int d = H[u] - H[v];
	for (int i = 16; i >= 0; -- i){
		if ((1 << i) > d) continue;
		d -= 1 << i;
		u = par[i][u];
	}
	if (v == u) return v;
	for (int i = 16; i >= 0; -- i){
		if (par[i][v] == par[i][u]) continue;
		v = par[i][v];
		u = par[i][u];
	}
	return par[0][v];
}
void add(int x){
	if (x > n){
		ans = inf;
		return;
	}
	if (!ted){
		st.insert(x);
		update(1, 0, xn, St[x], 1);
		++ ted;
		ans = 0;
		return;
	}
	if (ted + 1 == 2){
		st.insert(x);
		update(1, 0, xn, St[x], 1);
		++ ted;
		int v = *st.begin();
		st.erase(st.begin());
		int u = *st.begin();
		st.insert(v);
		ans = part[v] + part[u] - 2 * part[LCA(v, u)];
		return;
	}
	int v = x;
	for (int i = 16; i >= 0; -- i){
		int u = par[i][v];
		if (get(1, 0, xn, St[u], R[u]) == 0) v = u;
	}
	if (get(1, 0, xn, St[v], R[v]) == 0) v = par[0][v];
	ans += part[x] - part[v];
	int a = find_root();
	st.insert(x);
	++ ted;
	update(1, 0, xn, St[x], 1);
	int b = find_root();
	ans += part[a] - part[b];
}
void remove(int x){
	if (!x) return;
	if (ted < 3){
		-- ted;
		st.erase(x);
		update(1, 0, xn, St[x], - 1);
		ans = 0;
		return;
	}
	if (ted - 1 == 2){
		-- ted;
		st.erase(x);
		update(1, 0, xn, St[x], - 1);
		int v = *st.begin();
		st.erase(st.begin());
		int u = *st.begin();
		st.insert(v);
		ans = part[v] + part[u] - 2 * part[LCA(v, u)];
		return;
	}
	int v = x;
	for (int i = 16; i >= 0; -- i){
		int u = par[i][v];
		if (get(1, 0, xn, St[u], R[u]) < 2) v = u;
	}
	if (get(1, 0, xn, St[v], R[v]) < 2) v = par[0][v];
	ans -= part[x] - part[v];
	int a = find_root();
	st.erase(x);
	-- ted;
	update(1, 0, xn, St[x], - 1);
	int b = find_root();
	ans -= part[b] - part[a];
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++ i){
    	int v, u, w;
    	cin >> v >> u;
    	w = 1;
    	adj[v].push_back({u, w});
    	adj[u].push_back({v, w});
	}
	H[1] = 1;
	DFS(1);
	for (int i = 1; i < 20; ++ i) for (int v = 1; v <= n; ++ v) par[i][v] = par[i - 1][par[i - 1][v]];
	R[0] = R[1];
	int l = 0, r = 1;
	add(1);
	for (int i = 1; i <= n; ++ i){
		remove(l);
		++ l;
		while (ans < k && r <= n){
			++ r;
			add(r);
		}
		mx = max(mx, r - l);
	}
	cout << mx << endl;
    
    return 0;
}