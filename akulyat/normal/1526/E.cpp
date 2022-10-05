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

ll n, k;
vector<ll> v, nxt;
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

vector<ll> f, fi;
void prepare() {
	f.push_back(1);
	for (int i = 1; i <= ml; i++)
		f.push_back(f[i - 1] * i), f.back() %= mod;
	for (auto i : f)
		fi.push_back(bpow(i, mod));
}

ll C(int n, int k) {
	if (k < 0 || k > n)
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
	cin >> n >> k;
	k--;
	v.resize(n);
	for (auto &i : v) {
		cin >> i;
	}	
	auto p = v;
	for (int i = 0; i < n; i++)
		v[p[i]] = i;
	nxt.resize(n, -1);
	for (int i = 1; i < n; i++)
		nxt[v[i - 1]] = v[i];
	for (int i = 1; i < n; i++) {
		if (nxt[i - 1] > nxt[i])
			k--;
	}
	cout << C(n + k, k) << '\n';
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