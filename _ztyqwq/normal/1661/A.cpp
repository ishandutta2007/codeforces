#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto&x : a) cin >> x;
    for (auto&x : b) cin >> x;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1])
                 , abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]));
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}