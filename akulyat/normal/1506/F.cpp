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

int n;
vector<pii> v;
bool viv = false;

int line(pii a) {
	return a.F - a.S;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F, p.F--;
	for (auto &p : v)
		cin >> p.S, p.S--;


	sort(v.begin(), v.end());
	if (v[0] != (pii){0, 0})
		v.push_back({0, 0});
	sort(v.begin(), v.end());

	n = v.size();

	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int was = line(v[i - 1]);
		int will = line(v[i]);

		if (viv)
			cout << "\t" << was << " -> " << will << endl;

		int dif = will - was;
		if (was & 1) {
			ans += (dif + 1) / 2;
		} else {
			ans += dif / 2;
			if (!dif) {
				ans += (v[i].S - v[i - 1].S);
			}
		}
	}
	cout << ans << '\n';
	if (viv)
		cout << endl << endl;
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