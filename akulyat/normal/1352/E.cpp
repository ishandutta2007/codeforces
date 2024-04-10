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
	cin >> n;
	vector<ll> v, p;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<bool> have(n * (n + 3) + 10, false);
	for (int i = 0; i < v.size(); i++) {
		ll sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			if (j != i)
				have[sum] = true;
		}
	}
	ll ans = 0;
	for (auto &i : v)
		if (have[i])
			ans++;
		cout << ans << '\n';
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