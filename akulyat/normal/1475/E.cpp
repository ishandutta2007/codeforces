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

ll n, k;
vector<ll> v, f, of;
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

void prepare() {
	f.resize(1, 1);
	for (int i = 1; i < 10 * kk; i++)
		f.push_back(f[i - 1] * i), f.back() %= mod;
	for (auto i : f)
		of.push_back(bpow(i, mod));
}

ll C(int n , int k) {
	ll res = f[n];
	res *= of[k];
	res %= mod;
	res *= of[n - k];
	res %= mod;
	return res;
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.rbegin(), v.rend());
	v.push_back(0);
	if (v[k - 1] != v[k]) {
		cout << 1 << '\n';
		return;
	}

	int l_l = k - 1, l_r = l_l;
	int r_l = k, r_r = r_l;
	while (r_r < n && v[r_l] == v[r_r])
		r_r++;
	while (l_l > -1 && v[l_l] == v[l_r])
		l_l--;
	int l = l_r - l_l;
	int r = r_r - r_l;

	cout << C(l + r, r) << '\n';
}

int main() {
	prepare();
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}