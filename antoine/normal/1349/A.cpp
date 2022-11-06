#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a/gcd(a,b)*b;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;


    ll g = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (i) {
            res = gcd(res, lcm(g, x));
        }
        g = gcd(g, x);
    }

    cout << res;
    return 0;
}