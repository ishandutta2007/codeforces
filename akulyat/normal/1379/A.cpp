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

ll n;
vector<ll> v;
bool viv = false;

string make(string s, ll pl) {
	for (int i = 0; i < pl; i++)
		if (s[i] == '?')
			s[i] = 'z';
	for (int i = pl + 7; i < n; i++)
		if (s[i] == '?')
			s[i] = 'z';
	string t = "abacaba";
	for (int i = 0; i < 7; i++)
		if (s[pl + i] == '?')
			s[pl + i] = t[i];
	ll cnt = 0;
	for (int i = 0; i < s.size() - 6; i++)
		if (s.substr(i, 7) == t)
			cnt++;
	if (cnt == 1)
		return s;
	return "";
}

void solve() {
	string s;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n - 6; i++) {
		auto t = make(s, i);
		if (t.size()) {
			cout << "YES\n";
			cout << t << '\n';
			return;
		}
	}
	cout << "NO\n";

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