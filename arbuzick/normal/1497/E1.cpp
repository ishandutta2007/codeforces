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
        int c = 1, x = a[i];
        for (int j = 2; j * j <= x; ++j) {
            int cnt = 0;
            while (x % j == 0) {
                x /= j;
                cnt++;
            }
            if (cnt % 2) {
                c *= j;
            }
        }
        c *= x;
        a[i] = c;
    }
    unordered_set<int> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s.count(a[i])) {
            ans++;
            s.clear();
        }
        s.insert(a[i]);
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