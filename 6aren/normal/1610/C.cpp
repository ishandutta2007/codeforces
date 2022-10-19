#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> a[i];
    }

    auto check = [&](int mid) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= cur && b[i] >= mid - cur - 1) {
                cur++;
            }
        }
        return cur >= mid;
    };

    // cout << check(2) << endl;

    int l = 1, r = n;
    int res = 0;
    while (r >= l) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else { 
            r = mid - 1;
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}