#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<pii> vec;
bool viv = false;

int V;
vector<pii> e[2 * ml + 100 * kk];
vector<int> d;
vector<bool> used;

void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u.F] == -1)
			DFS(u.F, c + 1);
}

void build(int ans) {
	V = 2 * n + (1 << ans);
	// e.assign(V, {});
	for (int i = 0; i < V; i++)
		e[i].clear();
	for (int i = 0; i < n; i++) {
		int v1 = 2 * i + 0;
		int v2 = 2 * i + 1;
		int u1 = vec[i].F & ((1 << ans) - 1);
		int u2 = vec[i].S & ((1 << ans) - 1);
		u1 += 2 * n, u2 += 2 * n;

		e[v1].push_back({v2, 3 * i + 0});
		e[v2].push_back({v1, 3 * i + 0});

		e[v1].push_back({u1, 3 * i + 1});
		e[u1].push_back({v1, 3 * i + 1});

		e[v2].push_back({u2, 3 * i + 2});
		e[u2].push_back({v2, 3 * i + 2});
	}
	used.assign(3 * n, false);
	d.assign(V, -1);
}

bool can(int ans) {
	build(ans);
	DFS(0);
	for (int i = 0; i < V; i++)
		if (e[i].size() & 1)
			return false;
	for (int i = 0; i < 2 * n; i++)
		if (d[i] == -1)
			return false;
	return true;
}

// set<pii> used;

bool u(int v) {
	return used[e[v].back().S];
}

void cycle(vector<int> &res) {
	int v = res.back();
	while (e[v].size() && u(v))
		e[v].pop_back();
	if (e[v].empty())
		return;
	int u = e[v].back().F;
	used[e[v].back().S] = true;
	// used.insert({v, u});
	// used.insert({u, v});
	e[v].pop_back();

	res.push_back(u);
	cycle(res);
}

vector<int> euler() {
	vector<int> st(1, 0);
	vector<int> res;
	while (st.size()) {
		auto v = st.back();
		st.pop_back();

		vector<int> add(1, v);
		cycle(add);

		for (auto ver : add)
			st.push_back(ver);
		res.push_back(st.back());
		st.pop_back();
	}
	return res;
}


vector<int> ec;

void DFS2(int v, int c = 0) {
	// cout << "DFS2(" << v << ")" << endl;
	while (e[v].size()) {
		int u = e[v].back().F;
		bool was = used[e[v].back().S];
		used[e[v].back().S] = true;
		e[v].pop_back();
		if (!was) {
			DFS2(u);
			ec.push_back(v);
		}
	}
}

void show(int ans) {
	cout << ans << '\n';
	build(ans);
	// auto res = euler();
	DFS2(0);
	auto res = ec;
	// res.pop_back();
	// for (auto i : res)
	// 	cout << i << ' ';
	// cout << endl;
	// return;

	vector<int> order;
	for (auto i : res) {
		if (i < 2 * n)
			order.push_back(i);
	}
	if ((order[0] ^ 1) == order.back()) {
		order.push_back(order[0]);
		reverse(order.begin(), order.end());
		order.pop_back();
	}
	for (auto i : order)
		cout << i + 1 << ' ';
}

void solve() {
	cin >> n;
	vec.resize(n);
	for (auto &p : vec)
		cin >> p.F >> p.S;
	int l = 0, r = 21;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (can(m))
			l = m;
		else
			r = m;
	}
	show(l);
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}