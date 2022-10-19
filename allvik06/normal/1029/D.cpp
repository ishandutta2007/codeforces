#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> siz(n);
    for (int i = 0; i < n; ++i) {
        siz[i] = to_string(a[i]).size();
        a[i] %= k;
    }
    vector <int> d(11);
    d[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        d[i] = (d[i - 1] * 10) % k;
    }
    unordered_map <int, int> b[11];
    for (int i = 1; i < 11; ++i) {
        b[i].reserve(2 * n);
    }
    for (int i = 0; i < n; ++i) {
        ++b[siz[i]][a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        --b[siz[i]][a[i]];
        for (int j = 1; j <= 10; ++j) {
            int tmp = (d[j] * a[i]) % k;
            int ost = (k - tmp) % k;
            ans += b[j][ost];
        }
    }
    for (int i = 0; i < n; ++i) {
        ++b[siz[i]][a[i]];
    }
    for (int i = n - 1; i >= 0; --i) {
        --b[siz[i]][a[i]];
        for (int j = 1; j <= 10; ++j) {
            int tmp = (d[j] * a[i]) % k;
            int ost = (k - tmp) % k;
            ans += b[j][ost];
        }
    }
    cout << ans;
}