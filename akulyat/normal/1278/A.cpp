#include <bits/stdc++.h>

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


ll n, i, j;
vector<ll> m;
bool viv = false;

void solve() {
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	bool good = false;
	for (ll i = 0; i < (ll)t.size() - ((ll)s.size() - 1); i++) {
		string a;
		for (ll j = i; j < i + s.size(); j++)
			a += t[j];
		sort(a.begin(), a.end());
		if (a == s)
			good = true;
	} 
	if (good)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    	solve();

    return 0;
}