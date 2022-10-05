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

ll n, q;
vector<int> v;
bool viv = false;


void solve() {
	cin >> n >> q; 
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	while (v.size() && (v.back() + 1 == v.size()))
		v.pop_back();
	ld ans = 1;
	if (v.empty()) {
		cout << ans << "\n";
	}
	while (q--) {
		ll len;
		ld p;
		cin >> len >> p;
		if (v.size()) {
			if (len >= v.size())
				ans *= (1 - p);
		}
	}
	ans = 1 - ans;
	if (v.size()) {
		cout << ans << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}