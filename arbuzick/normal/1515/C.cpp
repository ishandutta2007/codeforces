#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f;
        a[i].s = i;
    }
    sort(rall(a));
    vector<int> ans(n);
    for (int i = 0; i < m; ++i) {
        ans[a[i].s] = i;
    }
    for (int i = m; i < n; ++i) {
        ans[a[i].s] = m - i % m - 1;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
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