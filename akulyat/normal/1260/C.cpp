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
    ll r, b, k;
    cin >> r >> b >> k;
    ll g = __gcd(r, b);
    ll f = (r * b) / g;
//    cout << r << ' ' << b << ' ' << f << endl;
    r /= g;
    b /= g;
    if (r > b)
        swap(r, b);
    ll kol = max((b - 2) / r, 0ll) + 1;
    if (kol >= k) {
        cout << "REBEL\n";
        return;
    }
    cout << "OBEY\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}