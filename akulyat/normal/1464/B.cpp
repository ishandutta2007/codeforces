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

ll n, x, y;
vector<ll> v;
string s;
bool viv = false;

ll work(string s) {
	string s2 = s;
	for (auto &i : s2)
		if (i == '?')
			i = '0';
	ll lo = 0, lz = 0;

	ll sans = 0;
	for (auto i : s2) {
		if (i == '0')
			sans += y * lo;
		if (i == '1')
			sans += x * lz;
		lo += (i == '1');
		lz += (i == '0');
	}
	if (viv)
		cout << "start " << sans << endl;

	ll ans = sans;
	ll wo = 0, wz = 0;
	for (int i = 0; i < n; i++) {
		lo -= (s2[i] == '1');
		lz -= (s2[i] == '0');		
		if (s[i] == '?') {
			sans -= y * wo;
			sans -= x * lo;
			sans += x * wz;
			sans += y * lz;
			ans = min(ans, sans);
			if (viv)
				cout << "\t now " << sans << '\n';
			s2[i] = '1';
		}
		wo += (s2[i] == '1');
		wz += (s2[i] == '0');		
	}
	return ans;
}

ll work2(string s) {
	string s2 = s;
	for (auto &i : s2)
		if (i == '?')
			i = '1';
	ll lo = 0, lz = 0;

	ll sans = 0;
	for (auto i : s2) {
		if (i == '0')
			sans += y * lo;
		if (i == '1')
			sans += x * lz;
		lo += (i == '1');
		lz += (i == '0');
	}
	if (viv)
		cout << "start " << sans << endl;

	ll ans = sans;
	ll wo = 0, wz = 0;
	for (int i = 0; i < n; i++) {
		lo -= (s2[i] == '1');
		lz -= (s2[i] == '0');		
		if (s[i] == '?') {
			sans += y * wo;
			sans += x * lo;
			sans -= x * wz;
			sans -= y * lz;
			ans = min(ans, sans);
			if (viv)
				cout << "\t now " << sans << '\n';
			s2[i] = '0';
		}
		wo += (s2[i] == '1');
		wz += (s2[i] == '0');		
	}
	return ans;
}

void solve() {
	cin >> s;
	cin >> x >> y;
	n = s.size();

	ll ans1 = work(s);
	ll ans2 = work2(s);
	ll ans = min(ans1, ans2);
	cout << ans << '\n';
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