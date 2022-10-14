#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 200000;

void solve() {
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans -= (a[i] - a[i - 1]) * (1ll * i * (n - i) - 1);
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}