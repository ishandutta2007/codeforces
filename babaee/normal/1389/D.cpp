/*
    Soheil Mohammadkhani
    bullshit candidate master :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k;
pll p1, p2;

ll solve() {
    cin >> n >> k >> p1.X >> p1.Y >> p2.X >> p2.Y;
    if (max(p1.X, p2.X) <= min(p1.Y, p2.Y)) {
        k -= n * (min(p1.Y, p2.Y) - max(p1.X, p2.X) );
        ll sc = max(p1.Y, p2.Y) - min(p1.X, p2.X);
        sc -= min(p1.Y, p2.Y) - max(p1.X, p2.X);
        ll mxr = n * sc;
        if (k <= 0) return cout << 0 << endl, 0;
        if (k <= mxr) return cout << k << endl, 0;
        k -= mxr;
        cout << mxr + 2 * k << endl;
        return 0;
    }

    ll pre = max(p1.X, p2.X) - min(p1.Y, p2.Y) - 1, len =  max(p1.Y, p2.Y) - min(p1.X, p2.X);
    ll s = pre, ans = INF;
    s += min(len + 1, k + 1);
    k -= len;
    if (k <= 0) return cout << s << endl, 0;
    for (int i = 1; i < n; i++) {
        ans = min(2 * k + s, ans);
        s += pre;
        s += min(len + 1, k + 1);
        k -= min(len, k);
        ans = min(2 * k + s, ans);
        if (k <= 0) break;
    }

    ans = min(ans, s + 2 * k);
    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}