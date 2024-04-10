/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

vector<int> t[maxn], g[maxn], cycle;
int n, N, par[maxn], pos[maxn], h[maxn], st[maxn], sz[maxn], up[maxn], seg[8 * maxn], lazy[8 * maxn], root[maxn];
bool in_cycle[maxn], visited[maxn], isheavy[maxn];

void propagate(int, int, int);

int get(int id, int L, int R, int l, int r){
	if (R <= l or r <= L)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	propagate(id, L, R);
	int mid = (L + R) >> 1, ret = 0;
	ret += get(2 * id + 0, L, mid, l, r);
	ret += get(2 * id + 1, mid, R, l, r);
	return ret;
}

void change(int id, int L, int R, int l, int r){
	if (R <= l or r <= L)
		return;
	if (l <= L and R <= r){
		seg[id] = (R - L) - seg[id];
		lazy[id] ^= 1;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, l, r);
	change(2 * id + 1, mid, R, l, r);
	seg[id] = seg[2 * id + 0] + seg[2 * id + 1];
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid);
	change(2 * id + 1, mid, R, mid, R);
	lazy[id] = 0;
}

void change(int v){
	while (v != 0 and v != -1 and par[v] != 0){
		if (!isheavy[v]){
			change(1, 0, N, st[v], st[v] + 1);
			v = par[v];
			continue;
		}
		int u = up[v];
		if (u == 0){
			change(1, 0, N, st[u] + 2, st[v] + 1);
		}
		else if (par[u] == 0){
			change(1, 0, N, st[u] + 1, st[v] + 1);
		}	
		else{
			change(1, 0, N, st[u], st[v] + 1);
		}	
		v = par[u];
	}
}

void change_cycle(int v, int u){
	if (pos[v] <= pos[u]){
		int a = pos[u] - pos[v], b = cycle.size();
		if (a < b - a or (a == b - a and cycle[(pos[v] + 1) % b] < cycle[(pos[v] - 1 + b) % b])){
			change(1, 0, N, n + pos[v], n + pos[u]);
		}
		else{
			change(1, 0, N, n, n + pos[v]);
			change(1, 0, N, n + pos[u], N);
		}
	}
	else{
		int a = pos[v] - pos[u], b = cycle.size();
		if (a < b - a or (a == b - a and cycle[(pos[v] + 1) % b] > cycle[(pos[v] - 1 + b) % b])){
			change(1, 0, N, n + pos[u], n + pos[v]);
		}
		else{
			change(1, 0, N, n, n + pos[u]);
			change(1, 0, N, n + pos[v], N);
		}
	}
}

bool cmp(int v, int u){ 
	return sz[v] > sz[u];
}

int Time = 0;
void dfs_up(int v, int r = -1, int p = -1){
	if (p == -1)
		up[v] = v;
	root[v] = r;
	par[v] = p;
	sort(t[v].begin(), t[v].end(), cmp);
	st[v] = Time ++;
	bool heavy = 1;
	for (auto u : t[v]){
		if (u != p and !(in_cycle[u] and in_cycle[v])){
			if (heavy)
				up[u] = up[v];
			else
				up[u] = u;
			isheavy[u] = heavy;
			heavy = 0;
			if (in_cycle[u])
				r = u;
			dfs_up(u, r, v);
		}
	}
}

void dfs_sz(int v, int p = -1){
	sz[v] = 1;
	for (auto u : t[v]){
		if (u != p and !(in_cycle[u] and in_cycle[v])){
			h[u] = h[v] + 1;
			dfs_sz(u, v);
			sz[v] += sz[u];
		}
	}
}

int dfs_find_cycle(int v, int p = -1){
	visited[v] = 1;
	int ret = n + 1;
	for (auto u : t[v]){
		if (u == p)
			continue;
		if (!visited[u]){
			h[u] = h[v] + 1;
			ret = min(dfs_find_cycle(u, v), ret);
		}
		else
			ret = min(ret, h[u]);
	}
	if (ret <= h[v]){
		pos[v] = cycle.size();
		cycle.push_back(v);
		in_cycle[v] = 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs_find_cycle(1);
	memset(h, 0, sizeof h);
	for (auto v : cycle){
		t[0].push_back(v);
		t[v].push_back(0);
	}
	n ++;
	dfs_sz(0);
	dfs_up(0);
	N = n + cycle.size();
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u;
		change(v);
		change(u);
		v = root[v], u = root[u];
		change_cycle(v, u);
		cout << (n - (int)cycle.size() - 1) - get(1, 0, N, 0, n) + max((int)cycle.size() - get(1, 0, N, n, N), 1) << endl;
	}
}