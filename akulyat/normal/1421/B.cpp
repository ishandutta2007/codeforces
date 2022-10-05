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
vector<string> s;
bool viv = false;


void solve() {
	cin >> n;
	s.resize(n);
	for (auto &str : s) {
		cin >> str;
	}
	vector<pll> ans;
	n--;
	if (s[0][1] == s[1][0]) {
		if (s[n][n - 1] == s[0][1])
			ans.push_back({n, n - 1});
		if (s[n - 1][n] == s[0][1])
			ans.push_back({n - 1, n});
	} else {
		if (s[n][n - 1] == s[n - 1][n]) {
			if (s[n][n - 1] == s[0][1])
				ans.push_back({0, 1});
			if (s[n][n - 1] == s[1][0])
				ans.push_back({1, 0});
		} else {
			if (s[0][1] == s[n][n - 1]) {
				ans.push_back({0, 1});
				ans.push_back({n - 1, n});
			} else {
				ans.push_back({1, 0});
				ans.push_back({n - 1, n});

			}
		}
	}
	cout << ans.size() << '\n';
	for (auto p : ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
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