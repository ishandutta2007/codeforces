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

ll n, m;
vector<ll> k, c;
bool viv = false;


void solve() {
	cin >> n >> m;
	k.resize(n);
	c.resize(m);
	for (auto &i : k)
		cin >> i, i--;
	for (auto &i : c)
		cin >> i;
	ll lans = 0;	
	sort(k.begin(), k.end());
	for (auto i : k)
		lans += c[i];
	ll ans = lans;
	int pl = 0;

	while (k.size()) {
		if (pl == m)
			return void(cout << ans << '\n');
		lans -= c[k.back()];
		k.pop_back();
		lans += c[pl];
		ans = min(ans, lans);
		pl++;
	}
	return void(cout << ans << '\n');
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}