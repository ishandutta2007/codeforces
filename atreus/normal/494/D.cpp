#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
 
int n;
ll h[maxn], answer[maxn];
vector<pair<int, int> > t[maxn], query[maxn];
int Time = 0, st[maxn], ft[maxn];
 
struct node{
	ll d1;
	ll d2;
	ll lazy;
	node(){
		d1 = 0, d2 = 0, lazy = 0;
	}
};
 
node seg[4 * maxn];
 
void propagate(int, int, int);
 
int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id].d2;
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	return (get(2 * id + 0, L, mid, l, r) + get(2 * id + 1, mid, R, l, r)) % mod;
}
 
void add(int id, int L, int R, int l, int r, ll val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		val %= mod;
		val = (val + mod) % mod;
		seg[id].d2 = (seg[id].d2 + 1ll * (R - L) * val % mod * val % mod + 2ll * val % mod * seg[id].d1 % mod) % mod;
		seg[id].d1 = (seg[id].d1 + 1ll * (R - L) * val % mod) % mod;
		seg[id].lazy = (seg[id].lazy + val) % mod;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
	seg[id].d1 = (seg[2 * id + 0].d1 + seg[2 * id + 1].d1) % mod;
	seg[id].d2 = (seg[2 * id + 0].d2 + seg[2 * id + 1].d2) % mod;
}
 
void propagate(int id, int L, int R){
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	add(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}
 
void dfs(int v, int par = -1){
	for (auto Q : query[v]){
		int idx = Q.first, u = Q.second;
		answer[idx] = 2ll * get(1, 0, n, st[u], ft[u]) % mod - get(1, 0, n, 0, n);
		answer[idx] = (answer[idx] + mod) % mod;
	}
	for (auto edge : t[v]){
		int u = edge.first, w = edge.second;
		if (u != par){
			add(1, 0, n, 0, n, +w);
			add(1, 0, n, st[u], ft[u], -2 * w);
			dfs(u, v);
			add(1, 0, n, st[u], ft[u], +2 * w);
			add(1, 0, n, 0, n, -w);
		}
	}
}
 
void dfs_init(int v, int par = -1){
	st[v] = Time ++;
	for (auto edge : t[v]){
		int u = edge.first, w = edge.second;
		if (u != par){
			h[u] = h[v] + w;
			dfs_init(u, v);
		}
	}
	ft[v] = Time;
}
 
int main(){
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v --, u --;
		t[v].push_back({u, w});
		t[u].push_back({v, w});
	}
	dfs_init(0);
	for (int i = 0; i < n; i++)
		add(1, 0, n, st[i], st[i] + 1, h[i]);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		v --, u --;
		query[v].push_back({i, u});
	}
	dfs(0);
	for (int i = 0; i < q; i++)
		cout << answer[i] << endl;
}