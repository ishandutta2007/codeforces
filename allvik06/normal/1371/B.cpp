#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        int minn = min(n - 1, r);
        int ans = minn * (minn + 1) / 2;
        if (n <= r) ++ans;
        cout << ans << "\n";
    }
}