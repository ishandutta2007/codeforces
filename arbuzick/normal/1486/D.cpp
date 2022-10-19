#include <bits/stdc++.h>

using namespace std;

//#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] >= m) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }
        int mn = n + 1;
        vector<int> pr(n + 1);
        for (int i = 0; i < n; ++i) {
            pr[i + 1] = pr[i] + b[i];
        }
        bool ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 >= k) {
                mn = min(mn, pr[i + 1 - k]);
            }
            if (pr[i + 1] - mn > 0) {
                ans = 1;
                break;
            }
        }
        if (ans) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}