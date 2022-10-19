#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 400005;

int n, m, ti = 0, sta[N], en[N], c[N];	

ll it[4 * N], lazy[4 * N];
vector<int> adj[N];

int bit_count(long long x) {
	int res = 0;
	while (x) {
		res += (x & 1);
		x /= 2;
	}
	return res;
}

void lazy_down(int k) {
	if (lazy[k] == 0) return;
	lazy[2 * k] = lazy[k];
	it[2 * k] = lazy[k];
	lazy[2 * k + 1] = lazy[k];
	it[2 * k + 1] = lazy[k];
	lazy[k] = 0;
}

void update(int k, int l, int r, int u, int v, int c) {
	if (l > v || r < u) {
		return;
	}
	if (l >= u && r <= v) {
		it[k] = (1LL << c);
		lazy[k] = (1LL << c);
		return;
	}
	lazy_down(k);
	int mid = (l + r) / 2;
	update(2 * k, l, mid, u, v, c);
	update(2 * k + 1, mid + 1, r, u, v, c);
	it[k] = (it[2 * k] | it[2 * k + 1]);
}

ll query(int k, int l, int r, int u, int v) {
	if (l > v || r < u) {
		return 0;
	}
	if (l >= u && r <= v) {
		return it[k];
	}
	lazy_down(k);
	int mid = (l + r) / 2;
	ll q1 = query(2 * k, l, mid, u, v);
	ll q2 = query(2 * k + 1, mid + 1, r, u, v);
	return (q1 | q2);
}

void dfs(int u, int v) {
	sta[u] = ++ti;
	for (auto t : adj[u]) {
		if (t == v) continue;
		dfs(t, u);
	}
	en[u] = ti;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i =1 ; i <= n; i++) {
		update(1, 1, n, sta[i], sta[i], c[i]);
	}
	for (int i = 1; i <= m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, c;
			cin >> u >> c;
			update(1, 1, n, sta[u], en[u], c);
		} else {
			int u;
			cin >> u;
			cout << bit_count(query(1, 1, n, sta[u], en[u])) << endl;
		}
	}
	return 0;
}