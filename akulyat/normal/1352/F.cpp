#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;
string s;


void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll bl = b + 1;
	string ans, s;
	for (int i = 0; i < bl; i++) 
		s += char('0' + (i & 1));
	if (b == 0 && a == 0)
		s = '1';

	for (int i = 0; i < s.size(); i++) {
		ans += s[i];
		if (ans.back() == '0')
			while (a)
				ans += '0', a--;
		if (ans.back() == '1')
			while (c)
				ans += '1', c--;
	}
	cout << ans << endl;
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}