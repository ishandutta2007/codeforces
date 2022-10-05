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

ll n, val;
string s;
bool viv = false;

ll gval(char c) {
	return 1ll << (c - 'a');
}

void solve() {
	cin >> n >> val;
	cin >> s;
	val -= gval(s.back());
	s.pop_back();
	val += gval(s.back());
	s.pop_back();

	if (viv)
		cout << "\rnow " << val << endl;

	vector<ll> cnt(26, 0);
	for (auto i : s)
		cnt[i - 'a']++;

	for (int i = 0; i < 26; i++) {
		val += cnt[i] * gval(char('a' + i));
	}	

	if (viv) {
		cout << "\tcnt ";
		for (auto i : cnt)
			cout << i << ' ';
		cout << "\rnow " << val << endl;		
	}

	for (int i = 25; i >= 0; i--) {
		if (val > 0) {
			int p = i + 1;
			ll use = min(cnt[i], val / (1ll << p));
			val -= use * (1ll << p);
		}
	}
	if (val == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
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