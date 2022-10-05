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
vector<string> v;
bool viv = false;


void solve() {
	string s;
	cin >> s;
	cin >> n;
	v.resize(n);
	for (auto &l : v)
		cin >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[0] == v[i][v[i].size() - 1] && s[1] == v[j][0]) {
				cout << "YES";
				return;
			}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < v[i].size(); j++)
			if (s[0] == v[i][j - 1] && s[1] == v[i][j]) {
				cout << "YES";
				return;				
			}
	cout << "NO";
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