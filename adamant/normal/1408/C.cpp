#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;

void solve() {
    int n, l;
    cin >> n >> l;
    int a[n + 2];
    a[0] = 0, a[n + 1] = l;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double ta[n + 2];
    double tb[n + 2];
    ta[0] = tb[n + 1] = 0;
    for(int i = 1; i <= n + 1; i++) {
        ta[i] = ta[i - 1] + double(a[i] - a[i - 1]) / i;
        tb[n + 1 - i] = tb[n + 2 - i] + double(a[n + 2 - i] - a[n + 1 - i]) / i;
    }
    for(int i = 1; i <= n + 1; i++) {
        if(ta[i] > tb[i]) {
            // between a[i - 1] and a[i]
            int va = i;
            int vb = n + 2 - i;
            // (t - ta[i - 1]) * va = (tb[i - 1] - t) * vb
            double t = double(ta[i - 1] * va + tb[i - 1] * vb) / (va + vb);
            cout << fixed << setprecision(12) << t << "\n";
            return;
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}