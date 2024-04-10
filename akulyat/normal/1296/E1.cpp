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
 
ll n, m, k;
vector<ll> v;
bool viv = false;


void solve() {
	ll n;
	string s;
	vector<ll> m;
	cin >> n;
	cin >> s;
	vector<ll> cnt(26, -1);

	for (ll i = 0; i < n; i++) {
		ll maxi = -1;
		for (ll j = s[i] - 'a' + 1; j < 26; j++) 
			maxi = max(maxi, cnt[j]);
		cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], maxi + 1);
		m.push_back(maxi + 1);
	}
	ll ans = *max_element(m.begin(), m.end()) + 1;
	if (ans <= 2) {
		cout << "YES\n";
		for (auto i : m)
			cout << i;
		cout << endl;
		return;
	}
	cout << "NO\n";
	// m.resize(n);
	// cnt = 0;
	// for (ll i = 0; i < 26; i++) {
	// 	for (ll j = 0; j < n; j++) {
	// 		if (s[j] == 'a' + i) {
	// 			m[j] = cnt;
	// 			cnt++;
	// 		}
	// 	}
	// }

}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}