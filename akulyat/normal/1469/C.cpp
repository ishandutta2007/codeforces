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

ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<pll> seg(n, {0, 0});
	for (int i = 0; i < n; i++)
		seg[i] = {v[i], v[i]};
	for (int i = 1; i < n - 1; i++)
		seg[i].S += (k - 1);
	for (int i = 1; i < n; i++) {
		seg[i].S = min(seg[i].S, seg[i - 1].S + k - 1);
		seg[i].F = max(seg[i].F, seg[i - 1].F - k + 1);
	}
	for (auto p : seg)
		if (p.F > p.S) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}