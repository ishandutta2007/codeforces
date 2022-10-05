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
vector<ll> v, s;
bool viv = false;

ld r(ll x, ll y) {
	return sqrt(x * x + y * y);
}

void solve() {
	cin >> n;
	s.clear();
	v.clear();
	for (int i = 0; i < 2 * n; i++) {
		ll x, y;
		cin >> x >> y;
		if (!x)
			s.push_back(abs(y));
		else
			v.push_back(abs(x));
	}
	sort(v.begin(), v.end());
	sort(s.begin(), s.end());
	ld ans = 0;
	for (int i = 0; i < n; i++)
		ans += r(v[i], s[i]);
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	cout << fixed << setprecision(20);
	while (t--)
		solve();

	return 0;
}