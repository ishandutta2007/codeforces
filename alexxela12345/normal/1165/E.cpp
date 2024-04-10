#include <bits/stdc++.h>
#define int long long

const int mod = 998244353;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= (i + 1) * (n - i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] %= mod;
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[n - 1 - i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}