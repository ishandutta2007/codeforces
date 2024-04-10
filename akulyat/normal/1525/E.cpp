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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<vector<int>> v;
bool viv = false;

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

int work(vector<int> a) {
	vector<int> cnt(n + 1);
	ll res = 1;
	for (auto val : a)
		cnt[val]++;
	int var = 0;
	for (int i = n; i > 0; i--) {
		var += cnt[i];
		res *= var;
		res %= mod;
		var--;
	}
	return res;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i, i--;
	}
	ll ans = 0;
	for (int j = 0; j < m; j++) {
		vector<int> a;
		for (int i = 0; i < n; i++)
			a.push_back(v[i][j]);
		int add = work(a);
		// cout << "\t" << add << endl;
		ans += add;
		ans %= mod;
	}	
	for (int i = 1; i <= n; i++) {
		ans *= bpow(i, mod);
		ans %= mod;
	}
	ans = m - ans;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
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