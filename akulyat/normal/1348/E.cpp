#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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

ll n, sum, s1, s2, k;
bool viv = false;
vector<pll> v;

void ans(ll v) {
	cout << v << endl;
	exit(0);
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i.F >> i.S, sum += i.F, sum += i.S, s1 += i.F, s2 += i.S;

	ll mx = sum / k;
	ll mn = max(0ll, mx - 1);
	ll z = sum - mx * k;

	for (auto i : v)
		if (min(i.F, i.S) >= k)
			ans(mx);

	vector<pll> pr;
	pr.push_back({0, 0});
	for (auto i : v) {
		if (i.F + i.S >= k) {
			ll mn = k - i.S;
			ll mx = i.F;
			mn = max(mn, 1ll);
			mx = min(mx, k - 1);
			pr.push_back({mn, mx});
		}
	}

	vector<vector<ll>> dp(pr.size() + 1, vector<ll>(k));	
	dp[0][0] = true;
	if (viv)
		for (auto i : pr) {
			cout << i.F << ' ' << i.S << ";" << endl;
		}
	for (int i = 0; i < pr.size(); i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i][j]) {
				dp[i + 1][j] = true;
				ll can = ((s1 - j) % k + k) % k;
				if (can <= z)
					ans(mx);
				for (int u = pr[i].F; u <= pr[i].S; u++) {
					int v = j + u;
					if (v >= k)
						v -= k;
					dp[i + 1][v] = true; 
					ll can = ((s1 - v) % k + k) % k;
					if (can <= z)
						ans(mx);
				}
			}
		}
	}
	ans(mn);
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