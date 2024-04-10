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

ll n, w;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> w;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	multiset<int> have;
	ll ans = 0;
	while (v.size()) {
		int val = v.back();
		v.pop_back();
		auto z = have.lower_bound(val);
		if (z == have.end()) {
			have.insert(w);
			z = have.lower_bound(val);
			ans++;
		}
		auto was = *z;
		have.erase(have.find(was));
		was -= val;
		have.insert(was);
	}
	cout << ans << '\n';
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