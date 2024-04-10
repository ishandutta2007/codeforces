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
bool viv = false;

int get(vector<int> &v, int pl) {
	pl %= n;
	pl += n;
	pl %= n;
	return v[pl];
}

bool can(vector<int> &v, int pl, int mv) {
	if (get(v, pl) != -1)
		return false;
	if (get(v, pl + 1) == mv)
		return false;
	if (get(v, pl - 1) == mv)
		return false;
	return true;
}


map<vector<int>, pll> mem;

pll DFS(vector<int> &v, int who) {
	if (mem.find(v) != mem.end()) 
		return mem[v];

	pll total = {who ^ 1, 0};
	pll win = {who, 0};
	for (int i = 0; i < n; i++) {
		for (int mv = 0; mv < 2; mv++) {
			if (can(v, i, mv)) {
				v[i] = mv;
				auto res = DFS(v, who ^ 1);
				total.S += res.S;
				if (res.F == who)
					win.S += res.S;
				v[i] = -1;
			}
		}
	}
	if (win.S && total.S != win.S) {
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';
		exit(0);
	}
	if (win.S) 
		return mem[v] = win;
	if (!total.S) {
		return mem[v] = {who ^ 1, 1};
	}
	return mem[v] = total;
}

void work(int len) {
	n = len;
	mem.clear();
	vector<int> v(n, -1);
	pll vars = DFS(v, 0);
	cout << vars.F << ' ' << vars.S << '\n';
}

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

ll inv(ll val) {
	return bpow(val, mod, -1);
}

ll f[ml + kk];
ll fi[ml + kk];

void prepare() {
	if (viv) {
		for (int i = 2; i < 10; i++) 
			work(i);
	}
	f[0] = 1;
	for (int i = 1; i < ml + kk; i++)
		f[i] = f[i - 1] * i, f[i] %= mod;
	for (int i = 0; i < ml + kk; i++)
		fi[i] = inv(f[i]);
}

ll C(int n, int k) {
	if (n < 0 || k < 0 || n < k)
		return 0;
	ll res = 1;
	res *= f[n];
	res %= mod;
	res *= fi[k];
	res %= mod;
	res *= fi[n - k];
	res %= mod;
	return res;
}

void solve() {
	cin >> n;
	ll ans = 0;
	for (int p = 0; p <= n; p++) {
		if (!((n - p) & 1)) {
			int lit = n - p;	
			ll lans = 1;		
			if (p) {
				lans *= C(lit - 1, p - 1);
				lans %= mod;
				lans *= n;
				lans %= mod;
				lans *= inv(p);
				lans %= mod;
			}
			lans *= f[lit];
			lans *= 2;
			lans %= mod;
			if (viv)
				cout << "\t" << n << ' ' << p << ": " << lans << '\n';
			ans += lans;
			ans %= mod;
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}