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
 
ll n, l;
vector<string> m;
bool viv = false;

bool pal(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

void solve() {
	cin >> n >> l;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		m.push_back(s);
	}

	map<string, ll> c1, c2;
	bool mid = false;

	map<string, bool> used;
	for (ll i = 0; i < n; i++) {
		c1[m[i]]++;
		reverse(m[i].begin(), m[i].end());
		c2[m[i]]++;
		reverse(m[i].begin(), m[i].end());
	}

	string s1, s2, mi;

	for (ll i = 0; i < n; i++) {
		if (pal(m[i]) && !used[m[i]]) {
			for (ll i = 0; i < c1[m[i]] / 2; i++)
				s1 += m[i];
			if (c1[m[i]] & 1)
				mi = m[i];
			used[m[i]] = true;
		} else 
			if (!used[m[i]]) {
				for (ll j = 0; j < min(c1[m[i]], c2[m[i]]); j++)
					s1 += m[i];
				used[m[i]] = true;
				reverse(m[i].begin(), m[i].end());
				used[m[i]] = true;
				reverse(m[i].begin(), m[i].end());
			}
	}
	ll ans = s1.size() * 2 + mi.size();
	cout << ans << endl;
	cout << s1;
	cout << mi;
	reverse(s1.begin(), s1.end());
	cout << s1;
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