#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;

ll n, b;

ll check(ll x) {
    ll pow = x;
    ll ans = 0;
    while (pow <= n) {
        ans += n / pow;
        if ((n + x - 1) / x < pow)
            break;
        pow *= x;
    }
    //cout << ans << " " << x << "\n";
    return ans;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> b;
    ll ans = 1e18;
    bool f = 1;
    map <int, int> m;
    for (ll i = 2; i * i <= b; i++) {
        while (b % i == 0) {
            m[i]++;
            b /= i;
        }
    }
    if (b > 1)
        m[b]++;
    for (auto i : m) {
        ans = min(ans, check(i.fs) / i.sc);
    }
    cout << ans;
    return 0;
}