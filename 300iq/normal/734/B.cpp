#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ll k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int mx = (int) 5e6 + 7;
    ll res = 0;
    for (int cnt = 0; cnt < mx; cnt++) {
        if (cnt > min(k3, k2)) break;
        k3 -= cnt;
        k2 -= cnt;
        res = max(res, cnt * 32 + min(k2, min(k5, k6)) * 256);
        k3 += cnt;
        k2 += cnt;
    }
    cout << res << '\n';
}