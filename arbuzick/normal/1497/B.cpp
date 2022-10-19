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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(n);
    for (int i =0 ; i < n; ++i) {
        cin >> b[i];
        a[b[i] % m]++;
    }
    int ans = 0;
    if (a[0] > 0) {
        ans++;
    }
    for (int i = 1; i + i <= m; ++i) {
        if (a[i] || a[m - i]) {
            ans += max(1LL, max(a[i], a[m - i]) - min(a[i], a[m - i]));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}