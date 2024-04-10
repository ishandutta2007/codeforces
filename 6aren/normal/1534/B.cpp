#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = (i > 0 ? a[i - 1] : 0);
            int r = (i != n - 1 ? a[i + 1] : 0);
            if (a[i] > max(l, r)) ans += a[i] - max(l, r), a[i] = max(l, r);
        }
        for (int i = 0; i < n; i++) {
            int l = (i > 0 ? a[i - 1] : 0);
            int r = (i != n - 1 ? a[i + 1] : 0);
            ans += max(0, a[i] - l) + max(0, a[i] - r);
        }
        cout << ans << '\n';
    }

    return 0;
}