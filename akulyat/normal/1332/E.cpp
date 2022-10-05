#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 


ll n, m, l, r;
bool viv = false;
vector<ll> v;

ll poww(ll val, ll st = mod - 2) {
	vector<ll> b, sq;
	while (st)
		b.push_back(st & 1), st >>= 1;
	val %= mod;
	sq.push_back(val);
	while (sq.size() < b.size())
		sq.push_back(sq.back() * sq.back()), sq.back() %= mod;

	ll res = 1;
	for (int i = 0; i < b.size(); i++)
		if (b[i])
			res *= sq[i], res %= mod;
	return res;
}

void solve() {
	cin >> n >> m >> l >> r;
	r -= l;
	r++;

	ll ans = poww(r, n * m);
	ans %= mod;
	if (r & 1 && !((n * m) & 1))
		ans++, ans %= mod;
	if (!((n * m) & 1))
		ans *= poww(2);
	ans %= mod;
	cout << ans << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}