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

ll a, b;
string s;
bool viv = false;


void solve() {
	cin >> a >> b;
	int n = a + b;
	cin >> s;
	for (auto i : s) {
		if (i == '0')
			a--;
		if (i == '1')
			b--;
	}
	for (int i = 0; i < n; i++) {
		if (s[n - 1 - i] == '0') {
			if (s[i] == '1') {
				cout << "-1\n";
				return;
			}
			if (s[i] == '?') {
				a--;
				s[i] = '0';
			}
		}
		if (s[n - 1 - i] == '1') {
			if (s[i] == '0') {
				cout << "-1\n";
				return;
			}
			if (s[i] == '?') {
				b--;
				s[i] = '1';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[n - 1 - i] == '?' && s[i] == '?') {
			int cnt = 2;
			if (i == n - 1 - i)
				cnt = 1;
			if (a >= cnt) {
				s[i] = s[n - 1 - i] = '0';
				a -= cnt;
			} else {
				s[i] = s[n - 1 - i] = '1';
				b -= cnt;				
			}
		}
	}
	if (a || b) {
		cout << "-1\n";
		return;
	}
	cout << s << '\n';
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