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

ll n, m, a, b;
bool viv = false;
string s;


void solve() {
	cin >> n >> m;
	cin >> a >> b;
	if (n == a && n == b + m) {
		cout << "Yes\n";
		return;
	}
	if (n == b && n == a + m) {
		cout << "Yes\n";
		return;
	}
	if (m == a && m == b + n) {
		cout << "Yes\n";
		return;
	}
	if (m == b && m == a + n) {
		cout << "Yes\n";
		return;
	}
	cout << "No\n";
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