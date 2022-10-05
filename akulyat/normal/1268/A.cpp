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


ll n, i, j, k;
vector<ll> m;
string s;
bool viv = false;

void good(string t, string s) {
	ll dif = n;
	for (ll i = n - 1; i >= 0; i--)
		if (s[i] != t[i])
			dif = i;
	if (dif == n || t[dif] > s[dif]) {
		cout << t;
		exit(0);
	}
}

void solve() {
	cin >> n >> k;
	cin >> s;
	cout << n << endl;
	string t;
	for (ll i = 0; i < n; i++) {
		t += s[i % k];
	}

	good(t, s);

	ll p = k - 1;
	s[p] += 1;
	while (p >= 0 && s[p] > '9') {
		s[p] -= 10;
		if (p)
			s[p-1]++;
		p--;
	}
	t = "";
	for (ll i = 0; i < n; i++)
		t += s[i % k];
	cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while(t--)
    	solve();

    return 0;
}