#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    forn (i, 0, n - 1) {
        if (a[i] + k >= a[i + 1]) {
            m += (a[i] - (a[i + 1] - k));
            if (a[i + 1] - k <= 0) {
                m -= (-a[i + 1] + k);
            }
        } else {
            m -= (a[i + 1] - k - a[i]);
            if (m < 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}