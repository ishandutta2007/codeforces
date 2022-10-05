#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

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
vector<ll> v;
bool viv = false;


void solve() {
	string a, b;
	cin >> a >> b;
	set<string> s;
	s.insert(a);
	s.insert(b);
	int n;
	cin >> n;
	for (auto i : s)
		cout << i << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++) {
		string b, c;
		cin >> b >> c;
		s.erase(b);
		s.insert(c);
		for (auto j : s)
			cout << j << ' ';
		cout << '\n';
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}