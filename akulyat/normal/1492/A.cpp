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


void solve() {
	ll p, a, b, c;
	cin >> p >> a >> b >> c;
	// a *= 2;
	// b *= 2;
	// c *= 2;
	ll pa = p / a * a;
	ll pb = p / b * b;
	ll pc = p / c * c;

	while (pa < p)
		pa += a;
	while (pb < p)
		pb += b;
	while (pc < p)
		pc += c;

	ll ans = pa - p;
	ans = min(ans, pb - p);
	ans = min(ans, pc - p);
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