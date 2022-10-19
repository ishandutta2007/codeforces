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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> add(n + 1);
    for (int i = 0; i < n; ++i) {
        if (i + 2 < n && a[i] > 1) {
            add[i + 2]++;
            add[min(n, i + a[i] + 1)]--;
        }
    }
    int ans = 0;
    int kek = 0;
    for (int i = 0; i < n; ++i) {
        kek += add[i];
        ans += max(0LL, a[i] - 1 - kek);
        int val = max(0LL, kek - (a[i] - 1));
        add[i + 1] += val;
        add[min(n, i + 2)] -= val;
    }
    cout << ans << '\n';
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