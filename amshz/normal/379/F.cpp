//khodaya khodet komak kon
# pragma GCC optimize("O2")
# pragma GCC optimize("Ofast")
# pragma GCC optimize("unroll-loops")
# pragma GCC target("avx,avx2,sse,sse2,fma")
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
# define lc                                              id << 1
# define rc                                              lc | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e6 + 10;
const int xm = 5e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e12 + 10;
const int mod = 998244353;
const int base = 257;
 
struct node{
	int a, b, ab, ba, ans;
};
 
int q, n = 4, H[xm + xm], ptr, a[xn], ans[xm];
vector <int> adj[xm + xm], vec[xm + xm];
pii query[xm];
node seg[xn << 2];
 
void DFS(int v){
	vec[v].push_back(ptr);
	a[ptr ++] = v;
	for (int u : adj[v]){
		H[u] = H[v] + 1;
		DFS(u);
		vec[v].push_back(ptr);
		a[ptr ++] = v;
	}
}
node merge(node v, node u){
	node w;
	w.a = max(v.a, u.a);
	w.b = max(v.b, u.b);
	w.ab = max(v.ab, u.ab);
	w.ba = max(v.ba, u.ba);
	w.ans = max(v.ans, u.ans);
	w.ab = max(w.ab, v.a + u.b);
	w.ba = max(w.ba, v.b + u.a);
	w.ans = max(w.ans, v.ab + u.a);
	w.ans = max(w.ans, v.a + u.ba);
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		int v = a[l];
		seg[id].a = H[v];
		seg[id].b = - H[v] - H[v];
		seg[id].ab = seg[id].ba = seg[id].ans = - inf;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = merge(seg[lc], seg[rc]);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		seg[id].a = seg[id].b = - inf;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos);
	else
		modify(rc, mid, r, pos);
	seg[id] = merge(seg[lc], seg[rc]);
}
 
int main(){
	InTheNameOfGod;
	
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int v;
		cin >> v;
		adj[v].push_back(++ n);
		adj[v].push_back(++ n);
		query[i] = {n - 1, n};
	}
	DFS(1);
	build(1, 0, ptr);
	for (int i = q; i >= 1; -- i){
		ans[i] = seg[1].ans;
		for (int x : vec[query[i].A])
			modify(1, 0, ptr, x);
		for (int x : vec[query[i].B])
			modify(1, 0, ptr, x);
	}
	for (int i = 1; i <= q; ++ i)
		cout << ans[i] << endl;
	
	return 0;
}