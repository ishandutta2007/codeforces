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
	ll n;
	cin >> n;
	m.resize(n);
	ll sum = 0;
	for (auto &i: m)
		cin >> i, sum += i;

	ll who = 0;
	ll a, b;
	a = b = 0;
	for (auto i : m) {
		ll s = i / 2;
		if (who)
			a += s, b += i - s;
		else
			b += s, a += i - s;
		who = who ^ true;
	}
	cout << min(a, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    t = 1;
    while(t--)
    	solve();

    return 0;
}