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

int n, m, N;
vector<string> f;
vector<int> v;
vector<vector<int>> e, re;
bool viv = false;

void add(int a, int b) {
	if (viv)
		cout << "edge " << a << " -> " << b << endl;
	e[a].push_back(b);
	re[b].push_back(a);
}

bool ss(int i, int j) {
	return f[i][j] == '#';
}

void build() {
	N = n * m;
	e.resize(N);
	re.resize(N);
	for (int j = 0; j < m; j++) {
		vector<int> vva;
		for (int i = n - 1; i >= 0; i--) {
			int a = i * m + j;
			if (ss(i, j)) {
				if (vva.size())
					add(a, vva.back());
				vva.push_back(a);
			}
		}
	}
	for (int j = 0; j < m - 1; j++) {
		vector<int> vva;
		vector<int> vvb;
		for (int i = n - 1; i >= 0; i--) {
			int a = i * m + j;
			int b = i * m + j + 1;
			if (ss(i, j)) {
				if (vvb.size())
					add(a, vvb.back());
			}
			if (ss(i, j + 1)) {
				if (vva.size())
					add(b, vva.back());
			}
			if (ss(i, j)) {
				vva.push_back(a);
			}
			if (ss(i, j + 1)) {
				vvb.push_back(b);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int v = i * m + j;
			int u = i * m + j + 1;
			if (ss(i, j) && ss(i, j + 1)) {
				add(u, v);
				add(v, u);
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			int u = i * m + m + j;
			if (ss(i, j) && ss(i + 1, j)) {
				add(u, v);
				add(v, u);
			}
		}
	}
}

vector<int> tin, tout, q, C;
int t;
void DFS(int v) {
	tin[v] = t++;
	for (auto u : e[v])
		if (tin[u] == -1)
			DFS(u);
	q.push_back(v);
	tout[v] = t++;
}
void DFS2(int v, int c) {
	C[v] = c;
	for (auto u : re[v])
		if (C[u] == -1)
			DFS2(u, c);
}

void solver() {
	tin.resize(N, -1);
	tout.resize(N, -1);
	for (int i = 0; i < N; i++)
		if (tin[i] == -1)
			DFS(i);
	reverse(q.begin(), q.end());

	int c = 0;
	C.resize(N, -1);
	for (auto v : q) {
		if (C[v] == -1) {
			DFS2(v, c);
			c++;
		}
	}
	vector<bool> ins(c, false);
	for (int i = 0; i < N; i++) {
		for (auto u : e[i]) {
			int c1 = C[i];
			int c2 = C[u];
			if (c1 != c2)
				ins[c2] = true;
		}
	}
	vector<bool> need(c, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			if (ss(i, j)) {
				int cc = C[v];
				need[cc] = true;
			}
		}
	}
	for (int i = 0; i < c; i++)
		if (ins[i])
			need[i] = false;
	int ans = 0;
	for (auto i : need)
		ans += i;
	cout << ans << endl;

	if (viv) {
		cout << "ins: \t";
		for (auto i : ins)
			cout << i << ' ';
		cout << endl;
		cout << "need: \t";
		for (auto i : need)
			cout << i << ' ';
		cout << endl;
		for (int i = 0; i < c; i++) {
			if (need[i] || ins[i])
				cout << "comp " << i << ' ' << ins[i] << ' ' << need[i] << endl;
		}
	}
}

void show() {
	if (!viv)
		return;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v = i * m + j;
			if (ss(i, j)) {
				cout << i << ' ' << j << ' ' << v << ' ' << C[v] << endl;;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	f.resize(n);
	for (auto &s : f)
		cin >> s;
	for (auto &i : v)
		cin >> i;
	build();
	solver();
	show();
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