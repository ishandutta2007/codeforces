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
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<ll> cnt(20);
	for (auto i : v) {

		for (int j = 0; j < 20; j++) {
			if (i & 1)
				cnt[j]++;
			i >>= 1;			
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll val = 0;
		for (int j = 19; j >= 0; j--) {
			val <<= 1;
			if (cnt[j]) {
				val++;
				cnt[j]--;
			}
		}
		ans += val * val;
	}
	cout << ans << '\n';
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