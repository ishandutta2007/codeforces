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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, q;
vector<int> v;

struct DSU {
	int n;
	int ans = 1;
	vector<int> p;
	vector<int> sz;
	int prt = 1;
	multiset<int> used;
	multiset<int, greater<int>> cand;

	DSU(int _n) : n(_n) {
		sz.resize(n, 1);
		p.resize(n);
		iota(p.begin(), p.end(), 0);

		for (int i = 0; i < n; i++) {
			if (!i)
				used.insert(sz[i]);
			else
				cand.insert(sz[i]);
		}
	}

	int pp(int v) {
		if (v == p[v])
			return v;
		return p[v] = pp(p[v]);
	}

	void inc() {
		if (viv)
			cout << "inc(" << ")" << endl;
		prt++;
		bal();
	}

	void er(int val) {
		if (viv)
			cout << "er(" << val << ")" << endl;
		auto z = used.find(val);
		if (z == used.end()) {
			auto z = cand.find(val);
			if (z == cand.end()) {
				cout << "FUCK UP" << endl;
				exit(1);
			}
			cand.erase(z);
			return;
		}
		ans -= *z;
		used.erase(z);
		if (viv)
			cout << "/er(" << val << ")" << endl;
	}

	void add(int val) {
		if (viv)
			cout << "add(" << val << ")" << endl;
		cand.insert(val);
	}

	void bal() {
		if (viv)
			cout << "bal(" << ")" << endl;
		while (used.size() < prt) {
			auto z = cand.begin();
			ans += *z;
			used.insert(*z);
			cand.erase(z);
		}
		int cnt = 0;
		while (cand.size() && *used.begin() < *cand.begin()) {
			cnt++;
			if (cnt > 100) {
				exit(0);
			}
			auto u = *used.begin();
			auto c = *cand.begin();
			ans -= u;
			if (viv)
				cout << "was " << u << ' ' << c << endl;
			used.erase(used.find(u));
			cand.erase(cand.find(c));
			used.insert(c);
			cand.insert(u);
			ans += c;
			// u = *used.begin();
			// c = *cand.begin();
			// cout << "now " << u << ' ' << c << endl;
		}
	}

	void upd(int u, int v) {
		if (viv)
			cout << "upd(" << u << ' ' << v << ")" << endl;
		u = pp(u);
		v = pp(v);
		if (u == v) {
			inc();
			return;
		}
		er(sz[u]);
		er(sz[v]);
		sz[u] += sz[v];
		p[v] = u;
		add(sz[u]);
		bal();
	}
};

void solve() {
	cin >> n >> q;
	DSU d(n);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		d.upd(a, b);
		cout << d.ans - 1 << '\n';
	}

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}