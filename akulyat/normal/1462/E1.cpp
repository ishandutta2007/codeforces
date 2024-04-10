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

ll n, m, k;
vector<ll> v;
bool viv = false;

vector<ll> f, of;
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
void prepare() {
	f.push_back(1);
	for (int i = 1; i <= ml / 2; i++)
		f.push_back(f.back() * i), f.back() %= mod;
	for (auto i : f)
		of.push_back(bpow(i, mod));
}

ll C(ll n, ll k) {
	if (k <= 2) {
		if (k == 0)
			return 1;
		if (k == 1)
			return n;
		if (k == 2)
			return n * (n - 1) / 2;
	}
	ll res = f[n];
	res %= mod;
	res *= of[k];
	res %= mod;
	res *= of[n - k];
	res %= mod;
	return res;
}

ll task = -1;
void solve() {
	task = 1;
	cin >> n;
	k = 2, m = 3;
	if (task == 2)
		cin >> m >> k;

	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	int r = 0;
	ll ans = 0;
	for (int l = 0; l < n; l++) {
		while (r != n && v[r] - v[l] <= k) {
			r++;
		}
		if (r - l >= m) {
			ans += C(r - l - 1, m - 1);			
		}
		if (viv)
			cout << "\tlr = " << l << ' ' << r << '\n';
		if (viv)
			cout << "\tsee: " << ans << '\n';
		if (task == 2)
			ans %= mod;
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}