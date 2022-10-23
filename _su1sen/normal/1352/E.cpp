#include<bits/stdc++.h>

using namespace std;

constexpr int M = 8001;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<bool> ok(n + 1, false);
        for (int l = 0; l < n; ++l) {
            int s = a[l];
            for (int r = l + 1; r < n; ++r) {
                s += a[r];
                if (s <= n) ok[s] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ok[a[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}