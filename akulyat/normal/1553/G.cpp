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

const int sz = kk * kk + 100;

ll n, q;
vector<ll> v, p;
bool viv = false;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i])
			res.push_back(i);
		if ((ll)i * i < last)
			for (int j = i * i; j <= last; j += i)
				prime[j] = false;
	}
	return res;
}

vector<vector<int>> d;
void work(int pl) {
	int val = pl;
	for (auto dd : p) {
		if (val % dd == 0) {
			d[pl].push_back(dd);
			while (val % dd == 0)
				val /= dd;
		}
	}
	if (val - 1)
		d[pl].push_back(val);
}

vector<vector<int>> e, e2;

void add(int val) {
	auto vec = d[val];
	for (auto i : vec)
		for (auto j : vec) {
			e[i].push_back(j);
			e2[i].push_back(j);
		}
}

void add2(int val) {
	auto vec = d[val];
	for (auto i : d[val + 1])
		vec.push_back(i);
	for (auto i : vec)
		for (auto j : vec) {
			e2[i].push_back(j);
		}
}

void DFS(int v, int c, vector<int> &col, vector<vector<int>> &e) {
	col[v] = c;
	for (auto u : e[v])
		if (col[u] == -1)
			DFS(u, c, col, e);
}

vector<int> col, col2;
set<pii> s;
void prepare() {
	col.resize(sz, -1);
	col2.resize(sz, -1);
	int tc = 0;

	tc = 0;
	for (int i = 0; i < sz; i++) {
		if (col[i] == -1) {
			DFS(i, tc, col, e);
			tc++;
		}
	}
	// tc = 0;
	// for (int i = 0; i < sz; i++) {
	// 	if (col2[i] == -1) {
	// 		DFS(i, tc, col2, e2);
	// 		tc++;
	// 	}
	// }

	for (int i = 0; i < sz; i++) {
		int v = i;
		for (auto u : e2[v]) {
			s.insert({col[v], col[u]});
			s.insert({col[u], col[v]});
		}
	}
}

void solve() {
	p = erat(kk);
	if (viv)
		cout << "A " << endl;
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (viv)
		cout << "A " << endl;

	d.resize(sz);
	for (int i = 2; i < d.size(); i++)
		work(i);
	if (viv)
		cout << "A " << endl;

	e.resize(sz);
	e2.resize(sz);

	for (auto val : v)
		add(val);
	for (auto val : v)
		add2(val);
	if (viv)
		cout << "A " << endl;

	prepare();
	if (viv)
		cout << "BA " << endl;

	// for (int i = 0; i < 20; i++)
	// 	cout << i << ": " << col2[i] << endl;

	while (q--) {
		int i, j;
		cin >> i >> j;
		i--, j--;
		int a = v[i];
		int b = v[j];
		ll res = 2;

		for (auto d1 : d[a])
			for (auto d2 : d[b]) {
			if (s.count({col[d1], col[d2]}))
				res = 1;
			if (col[d1] == col[d2])
				res = 0;
			}


		cout << res << '\n';
	}
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