#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

int m, c, x;

bool check(int mid) {
    if (mid > m || mid > c)
        return false;
    return m - mid + c - mid + x >= mid;
}

void solve() {
    cin >> m >> c >> x;
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid;
    }
    cout << l << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}