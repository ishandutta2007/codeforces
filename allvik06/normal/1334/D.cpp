#include <bits/stdc++.h>

using namespace std;
#define int long long
int now = 0, n, l, r;
void dfs(int v) {
    if (v == n) {
        for (int i = 2; i < n; ++i) {
            if (now > r) {
                return;
            }
            if (now + 2 * (n - i) >= l) {
                dfs(i);
            }
            else {
                now += 2 * (n - i);
            }
        }
    }
    else {
        ++now;
        if (now >= l && now <= r) cout << v << " ";
        for (int j = v + 1; j < n; ++j) {
            if (now > r) {
                return;
            }
            ++now;
            if (now >= l && now <= r) cout << j << " ";
            ++now;
            if (now >= l && now <= r) cout << v << " ";
        }
        ++now;
        if (now >= l && now <= r) cout << n << " ";
        if (v == 1) dfs(n);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        now = 0;
        cin >> n >> l >> r;
        dfs(1);
        if (r == n * (n - 1) + 1) {
            cout << 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}