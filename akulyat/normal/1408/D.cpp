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
const long long inf = 3 * ml; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<pll> a, b;
bool viv = false;


void solve() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (auto &p : a)
		cin >> p.F >> p.S;
	for (auto &p : b)
		cin >> p.F >> p.S;
	vector<pll> tos;
	tos.push_back({-1, inf});
	tos.push_back({inf, 0});
	for (auto p : a) {
		for (auto l : b) {
			if (p.F <= l.F) {
				tos.push_back({l.F - p.F, l.S - p.S + 1});
			}
		}
	}
	sort(tos.begin(), tos.end());
	for (int i = tos.size() - 2; i >= 0; i--)
		tos[i].S = max(tos[i].S, tos[i + 1].S);
	ll ans = inf;
	for (int i = 1; i < tos.size(); i++)
		ans = min(ans, tos[i - 1].F + 1 + tos[i].S);
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