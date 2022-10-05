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

ll n, k;
vector<ll> v;
string s;
bool viv = false;


void solve() {
	cin >> n >> k;
	cin >> s;
	ll cnt0 = 0, cnt1 = 0;
	for (int i = k; i < n; i++) {
		if (s[i] != '?' && s[i - k] != '?' && s[i] != s[i - k]) {
			cout << "NO\n";
			return;
		}
		if (s[i] == '?' && s[i - k] != '?')
			s[i] = s[i - k];
	}
	for (int i = n - k - 1; i >= 0; i--)
		if (s[i] == '?' && s[i + k] != '?')
			s[i] = s[i + k];
	for (int i = 0; i < k; i++)
		cnt0 += (s[i] == '0');
	for (int i = 0; i < k; i++)
		cnt1 += (s[i] == '1');
	if (cnt0 * 2 > k || cnt1 * 2 > k) {
		cout << "NO\n";
		return;
	}
	for (int i = k; i < n; i++) {
		cnt0 += (s[i] == '0');
		cnt0 -= (s[i - k] == '0');
		cnt1 += (s[i] == '1');
		cnt1 -= (s[i - k] == '1');
		if (cnt0 * 2 > k || cnt1 * 2 > k) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";	
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