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
 
ll n;
vector<ll> m;
bool viv = false;

void solve() {
	string s;
	cin >> s;
	vector<ll> cnt(26, 0);
	vector<vector<ll>> all;
	all.push_back(cnt);
	for (auto i : s) {
		cnt[i - 'a']++;
		all.push_back(cnt);
	}
	ll ans = 0;
	for (ll a = 0; a < 26; a++) 
		for (ll b = 0; b < 26; b++) {
			ll lans = 0;
			for (ll i = 0; i < (ll)all.size(); i++) 
				if (s[i] == 'a' + a) {
					lans += all[i][b];
				}
			ans = max(ans, lans);
			}
	for (auto i : cnt)
		ans = max(ans, i);
	for (auto i : cnt)
		ans = max(ans, i * (i - 1) / 2);
	cout << ans;
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