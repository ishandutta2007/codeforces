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
 
const int xn = 3e6 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;
 
int n, a[xn], seg[xn << 2], ptr, p[xn], m;
vector <int> adj[xn << 2];
bool mark[xn << 2];
 
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = ++ m;
	adj[seg[id]].push_back(seg[id << 1]);
	adj[seg[id]].push_back(seg[id << 1 | 1]);
}
void modify(int id, int l, int r, int pos){
	seg[id] = ++ m;
	if (r - l == 1) return;
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos);
	else modify(id << 1 | 1, mid, r, pos);
	adj[seg[id]].push_back(seg[id << 1]);
	adj[seg[id]].push_back(seg[id << 1 | 1]);
}
void update(int id, int l, int r, int ql, int qr, int v){
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr){
		adj[v].push_back(seg[id]);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, v);
	update(id << 1 | 1, mid, r, ql, qr, v);
}
void DFS(int v){
	mark[v] = true;
	for (int u : adj[v]) if (!mark[u]) DFS(u);
	if (v <= n) p[v] = ++ ptr;
}
 
int main(){
    InTheNameOfGod;
    
	cin >> n, m = n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i){
		if (a[i] == - 1){
			update(1, 1, n + 1, 1, i, i);
			update(1, 1, n + 1, i + 1, n + 1, i);
		}
		else{
			if (a[i] < i) update(1, 1, n + 1, 1, a[i], i);
			else{
				update(1, 1, n + 1, 1, i, i);
				update(1, 1, n + 1, i + 1, a[i], i);
			}
			modify(1, 1, n + 1, a[i]);
			adj[a[i]].push_back(i);
		}
	}
	for (int i = 1; i <= m; ++ i) if (!mark[i]) DFS(i);
	for (int i = 1; i <= n; ++ i) cout << p[i] << sep;
	cout << endl;
 
    return 0;
}