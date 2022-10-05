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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
const int K = 512;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> e;
vector<int> sg;
vector<ll> cnt;
vector<ll> inv;
const bool viv = false;

ll mpow(int v, int p = mod - 2) {
	if (p == 0)
		return 1;
	ll res = mpow(v, p / 2);
	assert(res < mod);
	res = res * res;
	res %= mod;
	if (p & 1) {
		res = res * v;
		res %= mod;
	}
	return res;
}


struct matrix {
	int sz;
	int ver;
	vector<vector<ll>> A;
	vector<ll> b;
	vector<ll> x;

	void build() {
		sz = K;		
		A.resize(sz, vector<ll>(sz, 0));
		b.resize(sz, 0);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				A[i][j] = cnt[i ^ j] * inv[n + 1];
				A[i][j] %= mod;
			}
			A[i][i] += mod - 1;
			A[i][i] %= mod;
			if (i) {
				b[i] = mod - inv[n + 1];
				b[i] %= mod;
			}
		}

		if (viv) {
			cout << "Start: \n";
			for (int i = 0; i < sz; i++) {
				for (int j = 0; j < sz; j++)
					cout << A[i][j] << ' ';
				cout << " = " << b[i] << endl;
			}
			cout << endl;
		}
	}

	void solve(int c) {
		if (viv)
			cout << "\tsolve(" << c << ")" << endl;
		assert(A[c][c]);
		int mul = mpow(A[c][c]);
		for (int j = c; j < sz; j++) {
			A[c][j] *= mul;
			A[c][j] %= mod;
		}
		b[c] *= mul;
		b[c] %= mod;

		for (int i = 0; i < sz; i++) 
			if (i != c) {
				int coef = A[i][c];
				for (int j = c; j < sz; j++) {
					A[i][j] -= A[c][j] * coef;
					A[i][j] %= mod;
					A[i][j] += mod;
					A[i][j] %= mod;
				}
				b[i] -= b[c] * coef;
				b[i] %= mod;
				b[i] += mod;
				b[i] %= mod;
			}
		if (viv) {
			cout << "After " << c << ": \n";
			for (int i = 0; i < sz; i++) {
				for (int j = 0; j < sz; j++)
					cout << A[i][j] << ' ';
				cout << " = " << b[i] << endl;
			}
			cout << endl;
		}
	}

	vector<ll> solve() {
		if (viv)
			cout << "\tsolve()" << endl;
		for (int i = 0; i < sz; i++) {
			solve(i);
		}
		x = b;
		return x;
	}

};


void DFS(int v) {
	set<int> sons;
	for (auto u : e[v]) {
		if (sg[u] == -1)
			DFS(u);
		sons.insert(sg[u]);
	}
	int my_val = 0;
	while (sons.find(my_val) != sons.end())
		my_val++;
	sg[v] = my_val;
	cnt[sg[v]]++;
}

void read() {
	cin >> n >> m;
	e.assign(n, {});
	sg.assign(n, -1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
	}
}

void prepare() {
	cnt.assign(K, 0);
	for (int i = 0; i < n; i++)
		if (sg[i] == -1)
			DFS(i);	
	if (viv) {
		cout << "sg = ";
		for (auto i : sg)
			cout << i << ' ';
		cout << endl;
		cout << "cnt = ";
		for (auto i : cnt)
			cout << i << ' ';
		cout << endl;
	}
	inv.assign(n + K + 10, 1);
	for (int i = 1; i < inv.size(); i++)
		inv[i] = mpow(i);
}

void solve() {
	read();
	prepare();
	matrix M;
	M.build();
	auto x = M.solve();
	cout << x[0] << '\n';
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