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
	string s;
	cin >> s;
	n = s.size();
	vector<vector<int>> lst(2, vector<int>(2, -1));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != '?') {
			lst[s[i] - '0'][i & 1] = i;
		}
		int c1 = min(lst[0][0], lst[0][1]);
		int c2 = min(lst[0][0], lst[1][0]);
		int c3 = min(lst[1][1], lst[0][1]);
		int c4 = min(lst[1][1], lst[1][0]);
		int cant = max(max(c1, c2), max(c3, c4));
		ans += (i - cant);
	}
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