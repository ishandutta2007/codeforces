#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'U') {
            y[i] = 1;
        } else if (c == 'D') {
            y[i] = -1;
        } else if (c == 'L') {
            x[i] = -1;
        } else {
            x[i] = 1;
        }

        if (i) {
            x[i] += x[i - 1];
            y[i] += y[i - 1];
        }
    }

    int fx, fy;
    cin >> fx >> fy;

    int l = -1, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        bool ok = false;
        for (int i = 0; i + m <= n; i++) {
            int cx = x[n - 1] - ((i + m) ? x[i + m - 1] : 0) + (i ? x[i - 1] : 0);
            int cy = y[n - 1] - ((i + m) ? y[i + m - 1] : 0) + (i ? y[i - 1] : 0);

            int d = abs(cx - fx) + abs(cy - fy);
            if (d <= m && (m - d) % 2 == 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << (r == n + 1 ? -1 : r);


    return 0;
}//qhmlbb