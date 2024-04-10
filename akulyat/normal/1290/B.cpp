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
vector<vector<ll>> v;
string s;
bool viv = false;

void prepare() {
	vector<ll> cnt(26, 0);
	v.push_back(cnt);
	for (auto i : s) {
		cnt[i - 'a']++;
		v.push_back(cnt);
	}
}

void check(ll l, ll r) {
	r++;
	auto cnt = v[r];
	for (ll i = 0; i < 26; i++)
		cnt[i] -= v[l][i];
	ll dif = 0;
	for (auto i : cnt)
		dif += (i > 0);
	if (dif > 2 || l + 1 == r) {
		cout << "Yes\n";
		return;
	}
	if (dif == 1) {
		cout << "No\n";
		return;
	}
	if (s[l] == s[r - 1]) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

void solve() {
	cin >> s;
	n = s.size();
	prepare();
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--, r--;
		check(l, r);
	}
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