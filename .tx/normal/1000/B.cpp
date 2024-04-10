#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int ans = 0;
    int ls = 0;
    int lt = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (lt == 1) {
            ans += a[i] - ls;
        }
        ls = a[i];
        lt ^= 1;
    }

    if (n % 2 == 0) {
        ans += m - ls;
    }

    vector<int> af(n);
    ls = m;
    lt = (n + 1) % 2;
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) {
            af[i] = af[i + 1];
        }
        if (lt == 1) {
            af[i] += ls - a[i];
        }
        ls = a[i];
        lt ^= 1;
    }

    int gans = ans;

    for (int i = 0; i < n; i++) {
        if (a[i] != 1 && (i == 0 || a[i] > a[i - 1] + 1)) {
            if (i % 2) {
                int cur = ans - af[i];
                cur += m - a[i] - af[i] + 1;
                gans = max(gans, cur);
            } else {
                int cur = ans - af[i] - 1;
                cur += m - a[i] - af[i];
                gans = max(gans, cur);
            }
        }
        if (a[i] != m - 1 && (i == n - 1 || a[i] + 1 < a[i + 1])) {
            if (i % 2) {
                int cur = ans - af[i] + 1;
                cur += m - (a[i] + 1) - (af[i] - 1);
                gans = max(gans, cur);
            } else {
                int cur = ans - af[i];
                cur += m - (a[i] + 1) - af[i];
                gans = max(gans, cur);
            }
        }
    }

    cout << gans;

    return 0;
}