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
	string s;
	cin >> s;
	n = s.size();
	ll sum = 0;
	for (auto i : s)
		sum += i - '0';
	if (sum % 3) {
		cout << "cyan\n";
		return;
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) 
			if (i != j) {
				ll res = (s[i] - '0') * 10 + (s[j] - '0');
				if (res % 20 == 0) {
					cout << "red\n";
					return;
				}
			}
	}
	cout << "cyan\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();

    return 0;
}