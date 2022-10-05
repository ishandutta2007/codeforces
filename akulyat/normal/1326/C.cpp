#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

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


ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<ll> pl;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= n + 1 - k)
			ans += v[i], pl.push_back(i);
	}
	ll res = 1;
	for (int i = 1; i < pl.size(); i++) {
		res *= (pl[i] - pl[i - 1]);
		res %= mod;
	}
	cout << ans << ' ' << res << endl;	
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}