/**
 *    author:  Atrues
 *    created: 28.01.2019 12:43
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

int Time = 1;

int n, st[maxn], ft[maxn], h[maxn], par[maxn][18];
vector<int> t[maxn];
pair<int, int> seg[4 * maxn];
int lazy[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int x){
	if (L == l and R == r){
		seg[id].first += x;
		lazy[id] += x;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), x);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, x);
	seg[id].first = min(seg[2 * id + 0].first, seg[2 * id + 1].first);
	seg[id].second = 0;
	if (seg[2 * id + 0].first == seg[id].first)
		seg[id].second += seg[2 * id + 0].second;
	if (seg[2 * id + 1].first == seg[id].first)
		seg[id].second += seg[2 * id + 1].second;
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

void build(int id, int L, int R){
	seg[id].second = R - L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
}

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = 17; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[v][i];
	if (v == u)
		return v;
	for (int i = 17; i >= 0; i--){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

int get_par(int v, int x){
	for (int i = 17; i >= 0; i--){
		if (x & (1 << i)){
			v = par[v][i];
		}
	}
	return v;
}

void dfs(int v, int p = -1){
	par[v][0] = p;
	for (int i = 1; i <= 17 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	st[v] = Time ++;
	for (auto u : t[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
	ft[v] = Time;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	build(1, 1, n + 1);
	set<pair<int, int> > s;
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		if (v > u)
			swap(v, u);
		int val;
		if (s.find({v, u}) == s.end()){
			val = 1;
			s.insert({v, u});
		}
		else{
			val = -1;
			s.erase({v, u});
		}
		int w = lca(v, u);
		if (v != w)
			swap(v, u);
		if (v == w){
			int z = get_par(u, h[u] - h[v] - 1);
			change(1, 1, n + 1, st[z], ft[z], +val);
			change(1, 1, n + 1, st[u], ft[u], -val);
		}
		else{
			change(1, 1, n + 1, 1, n + 1, +val);
			change(1, 1, n + 1, st[v], ft[v], -val);
			change(1, 1, n + 1, st[u], ft[u], -val);
		}
		cout << (seg[1].first == 0 ? seg[1].second : 0) << '\n';
	}
}