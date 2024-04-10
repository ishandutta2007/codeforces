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

ll n;
vector<vector<ll>> e;
vector<ll> d, sz, p;
vector<vector<ll>> pp;
vector<ll> ans;
pll corners;
pll c_sz;
bool viv = false;

void DFS(int v, int c = 0) {
	d[v] = c;
	sz[v] = 1;
	for (auto u : e[v])
		if (d[u] == -1) {
			p[u] = v;
			DFS(u, c + 1);
			sz[v] += sz[u];
		}
}

int LA(int v, int up);
int zson(int v);

void prepare() {
	pp.clear();
	int st = 0;
	while ((1 << st) < n)
		st++;
	st++;
	pp.resize(st);
	pp[0] = p;
	for (int i = 1; i < st; i++) {
		pp[i].resize(n);
		for (int v = 0; v < n; v++) {
			pp[i][v] = pp[i - 1][pp[i - 1][v]];
		}
	}
}

void get_0() {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) {
			ans[0] += (ll)(sz[i]) * (ll)(sz[i] - 1) / 2;
		}
	}
}

void get_1() {
	int son = zson(1);
	sz[son] -= sz[1];
	ll sum = 0;
	ans[1] = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) {
			ans[1] += (sum + 1) * (ll)sz[i];
			sum += sz[i];
		}
	}
}


int LA(int v, int up) {
	for (int i = (int)pp.size() - 1; i >= 0; i--) {
		if ((1 << i) <= up) {
			v = pp[i][v];
			up -= (1 << i);
		}
	}
	return v;
}

int zson(int v) {
	assert(v != 0);
	return LA(v, d[v] - 1);
}

bool my_p(int v, int pr) {
	if (d[pr] > d[v])
		return false;
	int up = d[v] - d[pr];
	return LA(v, up) == pr;
}

ll counter() {
	if (viv) {
		cout << "\tcorners: " << corners.F << ' ' << corners.S << endl;
	}
	ll sz1 = sz[corners.F];
	ll sz2 = sz[corners.S];
	if (corners.S == 0) {
		int son = zson(corners.F);
		sz2 -= sz[son];
	}
	if (viv) {
		cout << "\t\tsz: " << sz1 << ' ' << sz2 << endl;
	}
	c_sz = {sz1, sz2};
	return sz1 * sz2;
}

void work2(int v) {
	ans[v + 1] = counter();
	if (v + 1 < n) {
		if (my_p(corners.F, v + 1)) {
			ans[v + 1] = 0;
			return;
		}
		if (my_p(corners.S, v + 1)) {			
			ans[v + 1] = 0;
			return;
		}
		if (my_p(v + 1, corners.F)) {
			c_sz.F -= sz[v + 1];
		} else {
			if (my_p(v + 1, corners.S)) {
				if (corners.S == 0) {
					if (zson(corners.F) != zson(v + 1))
						c_sz.S -= sz[v + 1];
				} else {
					c_sz.S -= sz[v + 1];
				}
			}
		}
	}

	ans[v + 1] = c_sz.F * c_sz.S;
}

bool work(int v) {
	if (viv)
		cout << "work(" << v << ") = " << corners.F << ' ' << corners.S << endl;
	if (my_p(corners.F, v) || my_p(corners.S, v)) {
		work2(v);
		return true;
	}
	if (my_p(v, corners.F)) {
		corners.F = v;
		work2(v);
		return true;
	} else {
		if (my_p(v, corners.S)) {
			if (zson(v) == zson(corners.F)) {
				return false;
			}
			corners.S = v;
			work2(v);
			return true;
		} else {
			if (viv)
				cout << "FALSE " << v << endl;
			return false;
		}
	}
}

void get_n() {
	int leaf = 0;
	for (int i = 0; i < n; i++)
		leaf += (e[i].size() == 1);
	ans[n] = 0;
	ans[n] += (leaf == 2);
}

void solve() {
	cin >> n;
	e.assign(n, {});
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.assign(n, -1);
	p.assign(n, 0);
	sz.assign(n, 0);
	DFS(0, 0);
	prepare();
	ans.assign(n + 1, 0);
	get_0();
	corners = {0, 0};
	bool cont = true;
	for (int i = 1; i < n; i++)
		if (cont)
			cont = work(i);
	get_n();
	get_1();

	ll sum = 0;
	for (auto i : ans)
		sum += i;
	// if (sum * 2 != n * (n - 1)) {
	// 	cout << "BAD\n\t";
	// }

	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	// if (sum * 2 != n * (n - 1)) {
	// 	cout << endl;
	// }
	// assert(sum * 2 == n * (n - 1));
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}