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


ll n, i, j, x, a, y, b, w;
vector<ll> m;
bool viv = false;

ll proc(ll val, ll p) {
val /= 100;
val *= p;
return val;
}

bool can(ll k) {
ll to_xy = k/(a*b/__gcd(a, b));
ll to_x = k/(a);
ll to_y = k/(b);
/**
cout << to_xy << ' ';
cout << to_x << ' ';
cout << to_y << ' ';
cout << endl << endl;
**/
to_x -= to_xy;
to_y -= to_xy;
ll res = 0;
ll f = 0;
ll v = 0;
for (ll i = v; i < v+to_xy; i++)
    res += proc(m[i], x + y), f++;
v = f;
for (ll i = v; i < v+to_x; i++)
    res += proc(m[i], x), f++;
v = f;
for (ll i = v; i < v+to_y; i++)
    res += proc(m[i], y), f++;
v = f;

if (res >= w)
    return true;
return false;
}

void solve() {
cin >> n;
m.clear();
m.resize(n);
for (auto &i : m)
    cin >> i;
sort(m.rbegin(), m.rend());
cin >> x >> a;
cin >> y >> b;
if (x < y)
    swap(x, y), swap(a, b);
cin >> w;

ll l = 0;
ll r = n + 1;
while (l + 1 < r) {
    ll mi = l + r >> 1;
    if (can(mi))
        r = mi;
    else
        l = mi;
//    cout << "____ " << l << ' ' << mi << ' ' << r << endl;
    }
//cout << "---" << r << " " << n+1 << endl;
if (r == n + 1)
    r = -1;
cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}