#include <bits/stdc++.h>

using namespace std;
#define int long long
int mod = 998244353;
signed main() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        c.push_back((i + 1) * (n - i) * a[i]);
    }
    sort(c.begin(), c.end());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + (c[i] % mod) * b[i]) % mod;
    }
    cout << ans;
}