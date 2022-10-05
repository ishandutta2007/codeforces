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
	cin >> n;
	v.resize(n);
	for (auto &i : v) 
		cin >> i;
	vector<pii> tos;
	for (int i = 0; i < n; i++)
		tos.push_back({v[i], i});
	sort(tos.begin(), tos.end());
	for (int i = 0; i < n; i++) {
		bool good = true;
		if (i > 0)
			if (tos[i].F == tos[i - 1].F)
				good = false;
		if (i + 1 < n)
			if (tos[i].F == tos[i + 1].F)
				good = false;
		if (good) {
			cout << tos[i].S + 1 << '\n';
			return;
		}
	}

	cout << -1 << '\n';
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