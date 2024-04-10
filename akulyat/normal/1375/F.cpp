#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, k;
vector<ll> v;
bool viv = false;

void y(ll val) {
	cout << val << endl;
	ll k;
	cin >> k;
	if (k == 0)
		exit(0);
	k--;
	v[k] += val;
}

void solve() {
	v.resize(3);
	for (auto &i : v)
		cin >> i;
	cout << "First" << endl;
	// ll inf = 20;
	ll inf = 10 * mod;
	y(inf);

	auto vv = v;
	sort(vv.begin(), vv.end());
	ll val = 2 * vv[2] - vv[0] - vv[1];
	y(val);

	vv = v;
	sort(vv.begin(), vv.end());
	val = vv[2] - vv[1];
	y(val);
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}