#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

vector <int> new_dp, dp;

void upd(vector <int> a) {
    int sum = 0, mx = -1;
    forn (i, 0, sz(a))
        sum += a[i], mx = max(mx, a[i]);
    forn (i, 0, 10) {
        if (i + sz(a) >= 10) 
            new_dp[i + sz(a) - 10] = max(new_dp[i + sz(a) - 10], dp[i] + sum + mx);
        else 
            new_dp[i + sz(a)] = max(new_dp[i + sz(a)], dp[i] + sum); 
    }
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    dp.resize(10, -1e18);
    dp[0] = 0;
    forn (i, 0, n) {
        int k;
        cin >> k;
        vector <vector <int>> a(4);
        forn (j, 0, k) {
            int c, d;
            cin >> c >> d;
            a[c].pb(d);
        }
        forn (j, 0, 4)
            sort(rall(a[j]));
        new_dp = dp;
        if (sz(a[1]))
            upd({a[1][0]});
        if (sz(a[2]))
            upd({a[2][0]});
        if (sz(a[3]))
            upd({a[3][0]});
        if (sz(a[1]) && sz(a[2]))
            upd({a[1][0], a[2][0]});
        if (sz(a[1]) > 1)
            upd({a[1][0], a[1][1]});
        if (sz(a[1]) > 2)
            upd({a[1][0], a[1][1], a[1][2]});
        dp = new_dp;
    }
    cout << *max_element(all(dp));
    return 0;
}