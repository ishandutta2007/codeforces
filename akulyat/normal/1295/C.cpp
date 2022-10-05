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
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	vector<ll> cnt(26, -1);
	vector<vector<ll>> v;
	for (ll i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a'] = i;
		v.push_back(cnt);		
	}

	ll ans = 0;
	while (t.size()) {
		ll was = t.size();
		ll now = s.size() - 1;
		while (now >= 0 && t.size()) {
			now = v[now][t.back() - 'a'];
			if (now != -1)
				t.pop_back();
			now--;
		}
		if (t.size() == was) {
			cout << -1 << '\n';
			return;
		}
		ans++;
	}
	cout << ans << '\n';
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}