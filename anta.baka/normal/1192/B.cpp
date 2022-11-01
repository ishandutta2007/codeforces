#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 1e5;

int n, q;
ll w;
vector<pair<int, ll>> g[N];
int U[N], V[N];
ll W[N];

struct segTree {
	struct node {
		ll ad, a;
	};
	node merge(node& a, node& b) {
		return { 0, max(a.a, b.a) };
	}
	int n;
	vector<node> t;
	segTree() {}
	void create(int n, vector<ll>& v) {
		this->n = n;
		t.resize(4 * n);
		build(0, 0, n - 1, v);
	}
	void build(int v, int l, int r, vector<ll>& a) {
		if (l == r) {
			t[v] = { 0, a[l] };
		}
		else {
			int m = (l + r) >> 1;
			build(v * 2 + 1, l, m, a);
			build(v * 2 + 2, m + 1, r, a);
			t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}
	void push(int v) {
		if (t[v].ad) {
			ll x = t[v].ad;
			t[v].ad = 0;
			t[v * 2 + 1].ad += x;
			t[v * 2 + 1].a += x;
			t[v * 2 + 2].ad += x;
			t[v * 2 + 2].a += x;
		}
	}
	void upd(int v, int l, int r, int l1, int r1, ll x) {
		if (r < l1 || r1 < l) {
			return;
		}
		if (l1 <= l && r <= r1) {
			t[v].ad += x;
			t[v].a += x;
			return;
		}
		push(v);
		int m = (l + r) >> 1;
		upd(v * 2 + 1, l, m, l1, r1, x);
		upd(v * 2 + 2, m + 1, r, l1, r1, x);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
	ll get(int v, int l, int r, int l1, int r1) {
		if (r < l1 || r1 < l) {
			return 0;
		}
		if (l1 <= l && r <= r1) {
			return t[v].a;
		}
		push(v);
		int m = (l + r) >> 1;
		return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
	}
};

int siz[N];
int p[N];
bool ban[N];
int tin[N], tak_tik;
ll dep[N];
vector<ll> kek;
segTree t[N];
int tik_tak;
unordered_map<int, int> in[N], out[N], pred[N];
multiset<ll> kds[N];
int tsz[N];
multiset<ll> alc;

void calc_sz(int v, int p) {
	siz[v] = 1;
	for (auto& to : g[v]) {
		if (to.first != p && !ban[to.first]) {
			calc_sz(to.first, v);
			siz[v] += siz[to.first];
		}
	}
}

int get_c(int v, int p, int n) {
	for (auto& to : g[v]) {
		if (to.first != p && !ban[to.first] && 2 * siz[to.first] > n) {
			return get_c(to.first, v, n);
		}
	}
	return v;
}

void dfs(int v, int p, int up, int pu) {
	if (v != up) {
		if (pu == -1) {
			pu = v;
		}
		pred[up][v] = pu;
	}
	kek.pb(dep[v]);
	in[up][v] = ++tik_tak;
	for (auto& to : g[v]) {
		if (to.first != p && !ban[to.first]) {
			dep[to.first] = dep[v] + to.second;
			dfs(to.first, v, up, pu);
		}
	}
	out[up][v] = tik_tak;
}

ll take(int v) {
	return (*(--kds[v].end())) + (*(--(--kds[v].end())));
}

void cd(int v, int pp) {
	calc_sz(v, -1);
	v = get_c(v, -1, siz[v]);
	dep[v] = 0;
	kek.clear();
	tik_tak = -1;
	dfs(v, -1, v, -1);
	tsz[v] = sz(kek);
	t[v].create(tsz[v], kek);
	p[v] = pp;
	ban[v] = true;
	kds[v].insert(0);
	kds[v].insert(0);
	tin[v] = tak_tik++;
	for (auto& to : g[v]) {
		if (!ban[to.first]) {
			cd(to.first, v);
			kds[v].insert(t[v].get(0, 0, tsz[v] - 1, in[v][to.first], out[v][to.first]));
		}
	}
	alc.insert(take(v));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> q >> w;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].pb({ v, w });
		g[v].pb({ u, w});
		U[i] = u;
		V[i] = v;
		W[i] = w;
	}
	memset(p, -1, sizeof(p));
	cd(0, -1);
	ll last = 0;
	while (q--) {
		int d;
		ll e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % w;
		ll x = -W[d] + e;
		W[d] = e;
		int u = U[d];
		if (tin[V[d]] < tin[u]) {
			u = V[d];
		}
		while (u != -1) {
			alc.erase(alc.find(take(u)));
			int o = U[d];
			if (in[u][V[d]] > in[u][o]) {
				o = V[d];
			}
			int son = pred[u][o];
			kds[u].erase(kds[u].find(t[u].get(0, 0, tsz[u] - 1, in[u][son], out[u][son])));
			t[u].upd(0, 0, tsz[u] - 1, in[u][o], out[u][o], x);
			kds[u].insert(t[u].get(0, 0, tsz[u] - 1, in[u][son], out[u][son]));
			alc.insert(take(u));
			u = p[u];
		}
		last = *(--alc.end());
		cout << last << '\n';
	}
}