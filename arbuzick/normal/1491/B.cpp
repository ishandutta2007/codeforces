#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool c = 1;
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) > 1) {
            c = 0;
            break;
        }
    }
    if (c) {
        int ans = min(u, v) + v;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                ans = min(u, v);
            }
        }
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}