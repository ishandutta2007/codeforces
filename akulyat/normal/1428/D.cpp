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

void bad() {
	cout << "-1\n";
	exit(0);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<ll> free_row;
	for (int i = 0; i < n; i++)
		free_row.push_back(i);

	vector<ll> free, free_t;

	vector<vector<ll>> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == 1) {
			ll row = free_row.back();
			ans[i].push_back(row);
			free_row.pop_back();

			free.push_back(i);
		}
		if (v[i] == 2) {
			if (free.empty())
				bad();
			ll pr = -1;
			pr = free.back();
			free.pop_back();

			ans[i].push_back(ans[pr][0]);

			free_t.push_back(i);
		}
		if (v[i] == 3) {
			if (free.empty() && free_t.empty())
				bad();
			ll row = free_row.back();
			ans[i].push_back(row);
			free_row.pop_back();

			ll pr = -1;
			if (free_t.size()) {
				pr = free_t.back();
				free_t.pop_back();
			} else {
				pr = free.back();
				free.pop_back();
			}
			ans[pr].push_back(row);

			free_t.push_back(i);
		}
	}

	ll sz = 0;
	for (int i = 0; i < n; i++)
		sz += ans[i].size();
	cout << sz << '\n';
	for (int i = 0; i < n; i++) {
		for (auto j : ans[i]) {
			cout << j + 1 << ' ' << i + 1 << '\n';
		}
	}
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