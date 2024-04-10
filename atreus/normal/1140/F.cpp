#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 10;
const int N = 300000;
map<pair<int, int>, int> mp;
ll a[maxn];
vector<pair<int,int> > seg[4 * maxn];
int par[maxn + maxn], numx[maxn + maxn], numy[maxn + maxn];
ll answer = 0;
stack<pair<pair<int,int>, int> > ops;
stack<ll> opsonans;

int get_par(int v){
	while (par[v] >= 0)
		v = par[v];
	return v;
}

void undo(){
	auto it = ops.top();
	ops.pop();
	answer = opsonans.top();
	opsonans.pop();
	int v = it.first.first, p = it.first.second, u = it.second;
	if (v == -1)
		return;
	par[v] = p;
	par[u] -= par[v];
	numx[u] -= numx[v], numy[u] -= numy[v];
}

void merge(int v, int u){
	v = get_par(v), u = get_par(u);
	if (par[v] < par[u])
		swap(v, u);
	if (v == u){
		ops.push({{-1, -1}, -1});
		opsonans.push(answer);
		return;
	}
	ops.push({{v, par[v]}, u});
	opsonans.push(answer);
	answer -= 1ll * numx[v] * numy[v] + 1ll * numx[u] * numy[u];
	par[u] += par[v];
	par[v] = u;
	numx[u] += numx[v], numy[u] += numy[v];
	answer += 1ll * numx[u] * numy[u];
}

void dfs(int id, int L, int R){
	for (auto e : seg[id]){
		int v = e.first, u = e.second;
		merge(v, u);
	}
	if (L + 1 == R){
		a[L] = answer;
		for (auto e : seg[id])
			undo();
		return;
	}
	int mid = (L + R) >> 1;
	dfs(2 * id + 0, L, mid);
	dfs(2 * id + 1, mid, R);
	for (auto e : seg[id])
		undo();
}

void add(int id, int L, int R, int l, int r, int x, int y){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id].push_back({x,y});
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, x, y);
	add(2 * id + 1, mid, R, l, r, x, y);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		y += N;
		if (mp.count({x,y})){
			add(1, 1, n + 1, mp[{x,y}], i, x, y);
			mp.erase({x,y});
		}
		else
			mp[{x,y}] = i;
	}
	for (auto it : mp){
		auto p = it.first;
		int idx = it.second;
		int x = p.first, y = p.second;
		add(1, 1, n + 1, idx, n + 1, x, y);
	}
	for (int i = 1; i <= N; i++)
		numx[i] = 1;
	for (int i = N + 1; i <= N+N; i++)
		numy[i] = 1;
	memset(par, -1, sizeof par);
	dfs(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
}