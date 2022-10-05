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

	vector<pair<pii, pii>> ans;
	int pl = 0;
	for (int i = 0; i < n; i++)
		if (v[pl] > v[i])
			pl = i;
	for (int i = 0; i < n; i++) {
		if (abs(pl - i) & 1) {
			v[i] = v[pl] + 1;
			ans.push_back({{pl, i}, {v[pl], v[i]}});
		} else {
			if (pl - i) {
				v[i] = v[pl];
				ans.push_back({{pl, i}, {v[pl], v[i]}});				
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto pr : ans) {
		cout << pr.F.F + 1 << ' ';
		cout << pr.F.S + 1 << ' ';
		cout << pr.S.F << ' ';
		cout << pr.S.S << ' ';
		cout << '\n';
	}
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