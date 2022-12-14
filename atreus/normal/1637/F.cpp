#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int n, h[maxn], parent[maxn], maxH, oneMax;
vector<int> t[maxn];
ll cost = 0;
ll answer = 1e18;
int seg[4 * maxn];
int st[maxn], ft[maxn], Time = 0;

int get(int id, int L, int R, int l, int r) {
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return max(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void add(int id, int L, int R, int idx, int val) {
	if (idx < L or R <= idx)
		return;
	seg[id] = max(seg[id], val);
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, idx, val);
	add(2 * id + 1, mid, R, idx, val);
}

int getMax(int v, int par) {
	if (par == -1)
		return max(get(1, 0, n, 0, st[v]), get(1, 0, n, st[v] + 1, n));
	else {
		if (par == parent[v])
			return get(1, 0, n, st[v] + 1, ft[v]);
		else
			return max({get(1, 0, n, 0, st[v]), get(1, 0, n, st[v] + 1, st[par]), get(1, 0, n, ft[par], n)});
	}
}

int getCost(int v, int par) {
	return max(0, h[v] - getMax(v, par));
}

void dfs_ans(int v, int par = -1) {
	int c = getCost(v, -1);
	if (v != oneMax)
		answer = min(answer, cost - c + maxH);
	for (auto u : t[v]) {
		ll tmp = cost;
		if (u != par) {
			cost -= getCost(v, -1);
			cost -= getCost(u, v);
			cost += getCost(v, u);
			cost += getCost(u, -1);
			dfs_ans(u, v);
			cost = tmp;
		}
	}
}

void dfs(int v, int par = -1) {
	st[v] = Time++;
	parent[v] = par;
	for (auto u : t[v])
		if (u != par)
			dfs(u, v);
	ft[v] = Time;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	maxH = *max_element(h + 1, h + n + 1);
	oneMax = max_element(h + 1, h + n + 1) - h;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		add(1, 0, n, st[i], h[i]);
	for (int i = 1; i <= n; i++) {
		int c = max(0, h[i] - getMax(i, parent[i]));
		cost += c;
	}
	dfs_ans(1);
	cout << answer << '\n';
}