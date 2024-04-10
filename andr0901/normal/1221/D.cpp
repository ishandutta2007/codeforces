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

void solve() {
    int n;
    cin >> n;
    vector <pii> a(n + 1);
    a[0] = {-10, 0};
    forn (i, 1, n + 1)
        cin >> a[i].fs >> a[i].sc; 
    vector <vector <ll>> dp(n + 1, vector <ll> (3, 2e18));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    forn (i, 1, n + 1) {
        forn (j, 0, 3) {
            forn (k, 0, 3) {
                if (a[i - 1].fs + j == a[i].fs + k)
                    continue;
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + 1LL * k * a[i].sc);
            }
        }
    }
    cout << *min_element(all(dp[n])) << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}