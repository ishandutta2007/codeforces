#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e15;

void solve() {
    int n, k;
    cin >> n >> k;
    n++;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> val(n);
    for (int i = 0; i + 1 < n; ++i) {
        if ((val[i] + a[i]) % 2 != 0) {
            for (int j = i + 1; j < n; ++j) {
                val[j] = inf;
            }
            break;
        } else {
            val[i + 1] = (val[i] + a[i]) / 2;
        }
    }
    vector<long long> val2(n);
    for (int i = n - 1; i > 0; --i) {
        if (val2[i] == inf || (val2[i] + a[i]) * 2 >= inf || (val2[i] + a[i]) * 2 <= -inf) {
            val2[i - 1] = inf;
        } else {
            val2[i - 1] = (val2[i] + a[i]) * 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (val[i] != inf && val2[i] != inf) {
            long long nw = val[i] + val2[i];
            if (abs(nw) <= k && (i != n - 1 || nw != 0)) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}