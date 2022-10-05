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
	ll n, p, k;
	cin >> n >> p >> k;

	string s;
	cin >> s;
	
	ll x, y;
	cin >> x >> y;


	p--;
	reverse(s.begin(), s.end());
	while (p--)
		s.pop_back();
	reverse(s.begin(), s.end());
	n = s.size();

	vector<string> t(k);
	for (int i = 0; i < n; i++) {
		t[i % k] += s[i];
	}

	ll ans = inf;
	ll gap = 0;
	for (auto s : t) {
		// cout << '\t' << s << '\n';
		if (s.size()) {
			ll lans = (s.size() - 1) * y * k;
			lans += gap;
			if (s.back() == '0')
				lans += x;
			ans = min(ans, lans);
			for (int i = (int)s.size() - 2; i >= 0; i--) {
				lans -= y * k;
				if (s[i] == '0')
					lans += x;
				ans = min(ans, lans);
			}
		}
		gap += y;
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