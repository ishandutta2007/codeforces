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

ll n, x, pos;
ll less_x, more_x;
vector<ll> v;
set<ll> s;
bool viv = false;

ll f(ll n) {
	ll res = 1;
	for (int i = 1; i <= n; i++)
		res *= i, res %= mod;
	return res;
}

ll work(int l, int r, int lx, int mx) {
	if (viv) {
		cout << "work " << l << ' ' << r << ": " << lx << ' ' << mx << endl;
	}
	if (lx < 0 || mx < 0)
		return 0;
	pos++;
	if (pos < l || pos > r) {
		pos--;
		return 0;
	}
	pos--;
	if (l == r) {
		return f(n - s.size());
	}	
	int m = l + r >> 1;
	ll res = 0;
	s.insert(m);
	ll add1, add2;
	if (viv)
		cout << "\t\t" << m << ' ' << pos << endl;
	if (m != pos) {
		add1 = work(l, m, lx, mx - 1);
		add2 = work(m + 1, r, lx - 1, mx);
	} else {
		add1 = work(l, m, lx, mx);
		add2 = work(m + 1, r, lx, mx);
	}
	if (m != pos) {
		add1 *= mx;
		add2 *= lx;
	} else {
		add1 *= 0;
		add2 *= 1;
	}
	s.erase(s.find(m));
	add1 %= mod;
	add2 %= mod;
	
	res += add1;
	res += add2;
	res %= mod;
	return res;
}

void solve() {
	cin >> n >> x >> pos;
	// pos++;
	// pos--;
	x--;
	less_x = x; 
	more_x = n - 1 - x; 
	auto ans = work(0, n, less_x, more_x);
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