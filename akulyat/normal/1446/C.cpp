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
vector<ll> v;
bool viv = false;

ll work(vector<ll> v, ll b) {
	if (v.size() <= 2)
		return 0;
	if (viv) {
		cout << "work(";
		cout << "{";
		for (auto i : v)
			cout << i << ' ';		
		cout << "} ";
		cout << b << ")" << endl;
	}
	vector<ll> v0, v1;
	for (auto i : v)
		if (i & (1ll << b))
			v1.push_back(i ^ (1 << b));
		else
			v0.push_back(i);
	ll res0 = max(0ll, (ll)v1.size() - 1) + work(v0, b - 1);
	ll res1 = max(0ll, (ll)v0.size() - 1) + work(v1, b - 1);
	ll res = min(res0, res1);
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll ans = work(v, 31);
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