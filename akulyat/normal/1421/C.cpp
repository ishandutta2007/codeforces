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
string s;
bool viv = false;
vector<pll> ans;

void pr(ll len) {
	ans.push_back({0, 1 + len});

	ll l = 1;
	ll r = l + len;
	string str;
	for (int i = l; i < r; i++)
		str += s[i];
	reverse(str.begin(), str.end());
	s = str + s;
}

void suf(ll len) {
	ans.push_back({1, s.size() - len});

	ll r = s.size() - 1;
	ll l = r - len;
	string str;
	for (int i = l; i < r; i++)
		str += s[i];
	reverse(str.begin(), str.end());
	s = s + str;
}

void solve() {
	cin >> s;
	pr(1);
	pr(1);
	suf(s.size() - 2);
	suf(1);

	cout << ans.size() << '\n';
	for (auto p : ans) {
		if (p.F == 0)
			cout << "L ";
		else
			cout << "R ";
		cout << p.S << '\n';
	}
	if (viv)
		cout << s << endl;
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