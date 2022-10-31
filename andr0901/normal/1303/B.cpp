#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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

void solve() {
    int n, g, b;
    cin >> n >> g >> b;
    int l = n - 1, r = 1e18;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int cycles = m / (g + b);
        int good = g * cycles;
        if (m % (g + b) >= g)
            good += g;
        else
            good += (m % (g + b)) % g;
        if (good >= (n + 1) / 2)
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}