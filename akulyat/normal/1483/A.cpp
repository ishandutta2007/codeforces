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

ll n, d;
vector<vector<int>> v;
bool viv = false;


void solve() {
	cin >> n >> d;
	v.resize(d);
	map<int, int> cnt;
	for (int i = 0; i < d; i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto &j : v[i])
			cin >> j, j--;
		if (k == 1)
			cnt[v[i][0]]++;
	}
	vector<ll> ans(d);
	for (int i = 0; i < d; i++) {
		if (v[i].size() == 1) {
			ans[i] = v[i][0];
		} else {
			bool need = true;
			for (auto f : v[i]) {
				if (need && (cnt[f] + 1) <= (d + 1) / 2) {
					ans[i] = f;
					cnt[f]++;
					need = false;
				}
			}
		}
	}
	for (auto p : cnt)
		if (p.S > (d + 1) / 2) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
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