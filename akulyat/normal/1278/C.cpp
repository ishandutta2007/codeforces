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
    cin >> n;
    n *= 2;
    m.clear();
    ll sum = 0;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a == 2)
        	a = -1;
        sum += a;
        m.push_back(a);
    }
    vector<ll> p, s;
    p.push_back(0);
    for (auto i : m)
    	p.push_back(p.back() + i);
    reverse(m.begin(), m.end());
    s.push_back(0);
    for (auto i : m)
    	s.push_back(s.back() + i);
    reverse(m.begin(), m.end());
    while (p.size() > n/2 + 1)
    	p.pop_back();
    while (s.size() > n/2 + 1)
    	s.pop_back();


    map<ll, ll> need;
    for (ll i = 0; i < n/2 + 1; i++) {
    	need[s[i]] = i;
    }
    ll ans = n;
    for (ll i = 0; i < n/2 + 1; i++) {
    	ll lsum = 0 - p[i];
    	if (need.find(lsum) != need.end()) {
    		ans = min(ans, n - i - need[lsum]);
    	}
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    	solve();

    return 0;
}