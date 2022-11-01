#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

int n, q;
vector<pair<int, int>> g[200000];
int dep[200000];
vector<int> et;
int p1[200000], p2[200000];
int w[200000], W[200000];
int le[400000];

void dfs(int v) {
	p1[v] = et.size();
	et.push_back(v);
	for(pair<int, int> e : g[v]) {
		dep[e.first] = dep[v] + e.second;
		dfs(e.first);
	}
	p2[v] = et.size();
	et.push_back(v);
}

struct node {
	ll ad, mi;
};

node t[4 * 2 * 200000];

void build(int v, int l, int r) {
	if(l == r) {
		t[v].mi = dep[et[l]] + w[et[l]];
	} else {
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v].mi = min(t[v * 2 + 1].mi, t[v * 2 + 2].mi);
	}
}

void push(int v) {
	ll x = t[v].ad;
	if(!x)
		return;
	t[v].ad = 0;
	t[v * 2 + 1].mi += x;
	t[v * 2 + 1].ad += x;
	t[v * 2 + 2].mi += x;
	t[v * 2 + 2].ad += x;
}

void upd(int v, int l, int r, int l1, int r1, int x) {
	if(r < l1 || r1 < l)
		return;
	if(l1 <= l && r <= r1) {
		t[v].mi += x;
		t[v].ad += x;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	upd(v * 2 + 1, l, m, l1, r1, x);
	upd(v * 2 + 2, m + 1, r, l1, r1, x);
	t[v].mi = min(t[v * 2 + 1].mi, t[v * 2 + 2].mi);
}

ll get(int v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l)
		return INF;
	if(l1 <= l && r <= r1)
		return t[v].mi;
	push(v);
	int m = (l + r) / 2;
	return min(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
}

node t1[4 * 2 * 200000];

void build1(int v, int l, int r) {
	if(l == r) {
		t1[v].mi = dep[et[l]];
	} else {
		int m = (l + r) / 2;
		build1(v * 2 + 1, l, m);
		build1(v * 2 + 2, m + 1, r);
		t1[v].mi = min(t1[v * 2 + 1].mi, t1[v * 2 + 2].mi);
	}
}

void push1(int v) {
	ll x = t1[v].ad;
	if(!x)
		return;
	t1[v].ad = 0;
	t1[v * 2 + 1].mi += x;
	t1[v * 2 + 1].ad += x;
	t1[v * 2 + 2].mi += x;
	t1[v * 2 + 2].ad += x;
}

void upd1(int v, int l, int r, int l1, int r1, int x) {
	if(r < l1 || r1 < l)
		return;
	if(l1 <= l && r <= r1) {
		t1[v].mi += x;
		t1[v].ad += x;
		return;
	}
	push1(v);
	int m = (l + r) / 2;
	upd1(v * 2 + 1, l, m, l1, r1, x);
	upd1(v * 2 + 2, m + 1, r, l1, r1, x);
	t1[v].mi = min(t1[v * 2 + 1].mi, t1[v * 2 + 2].mi);
}

ll get1(int v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l)
		return INF;
	if(l1 <= l && r <= r1)
		return t1[v].mi;
	push1(v);
	int m = (l + r) / 2;
	return min(get1(v * 2 + 1, l, m, l1, r1), get1(v * 2 + 2, m + 1, r, l1, r1));
}

bool upper(int u, int v) {
	return p1[u] < p1[v] && p2[u] > p2[v];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].push_back({b, c});
		le[i] = b;
		W[b] = c;
	}
	dfs(0);
	for(int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		w[a] = c;
		le[n - 1 + i] = a;
	}
	build(0, 0, 2 * n - 1);
	build1(0, 0, 2 * n - 1);
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int e, w1;
			cin >> e >> w1;
			--e;
			if(e < n - 1) {
				upd(0, 0, 2 * n - 1, p1[le[e]], p2[le[e]], w1 - W[le[e]]);
				upd1(0, 0, 2 * n - 1, p1[le[e]], p2[le[e]], w1 - W[le[e]]);
				W[le[e]] = w1;
			} else {
				upd(0, 0, 2 * n - 1, p1[le[e]], p1[le[e]], w1 - w[le[e]]);
				upd(0, 0, 2 * n - 1, p2[le[e]], p2[le[e]], w1 - w[le[e]]);
				w[le[e]] = w1;
			}
		} else {
			int u, v;
			cin >> u >> v;
			if(u == v) {
				cout << 0 << '\n';
				continue;
			}
			--u; --v;
			ll x = get1(0, 0, 2 * n - 1, p1[v], p1[v]) - get1(0, 0, 2 * n - 1, p1[u], p1[u]);
			if(upper(u, v))
				cout << x << '\n';
				//cout << dep[v] - dep[u] << '\n'; // dep  ,     
			else
				cout << get(0, 0, 2 * n - 1, p1[u], p2[u]) + x << '\n';
				//cout << get(0, 0, 2 * n - 1, p1[u], p2[u]) - dep[u] + dep[v] << '\n'; // dep       
		}
	}
}