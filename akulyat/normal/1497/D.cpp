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
vector<int> t, s;
bool viv = false;


void solve() {
	cin >> n;
	t.resize(n);
	s.resize(n);
	for (auto &i : t)
		cin >> i;
	for (auto &i : s)
		cin >> i;

	vector<ll> ans(n, 0);
	for (int r = n - 1; r >= 0; r--) {
		for (int l = 0; l < r; l++) {
			if (t[l] != t[r]) {
				ll lans = ans[l];
				ll rans = ans[r];
				int add = abs(s[l] - s[r]);
				ans[l] = max(ans[l], rans + add);
				ans[r] = max(ans[r], lans + add);
			}
		}
	}
	ll ANS = 0;
	for (auto i : ans)
		ANS = max(ANS, i);
	cout << ANS << '\n';
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