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
 
 
ll n, i, j, have;
vector<pll> m;
bool viv = false;
 
ll rb(vector<pll> m) {
    vector<ll> r;
    for (auto i : m)
        r.push_back(i.S);
    sort(r.begin(), r.end());
    return r[n/2];
}
 
void print(int x) {
	if (x >= 10) {
		print(x / 10);
		putchar(x % 10 + '0');
	} else {
		putchar(x + '0');
	}
}
 
void read(ll &x) {
	static char c;
	while ((c = getchar()) >= '0')
		x = (x << 3) + (x << 1) + (c - '0');
}
void solve() {
    n = 0, read(n);
    have = 0, read(have);
    m.clear();
    for (ll i = 0; i < n; i++) {
        ll a = 0, b = 0;
        read(a);
        read(b);
        m.push_back({a, b});
    }
    sort(m.begin(), m.end());
    ll l = m[n/2].F;
    ll r = rb(m);
    if (viv)
        cout << "___ " << l << ' ' << r << endl;
    r++;
    for (auto i : m)
        have -= i.F;
    while (l + 1 < r) {
        ll mi = l + r >> 1;
        ll want = n/2 + 1;
        ll need = 0;
        for (ll i = n-1; i >= 0; i--)
            if (want && m[i].S >= mi)
                need += max(0ll, mi - m[i].F), want--;
        if (want == 0 && need <= have)
            l = mi;
        else
            r = mi;
        if (viv)
            cout << "___ " << l << ' ' << r << endl;
    }
    print(l);
    putchar('\n');
}
 
int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 0;
    read(t);
    while (t--)
        solve();
 
    return 0;
}