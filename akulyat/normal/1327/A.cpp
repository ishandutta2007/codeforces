#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	if ((n + k) & 1) {
		cout << "NO\n";
		return;
	}
	if (n < k * k) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}