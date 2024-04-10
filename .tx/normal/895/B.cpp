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

    int n, x, k;
    cin >> n >> x >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    auto f = [&](int l, int r) {
        return r / x - (l - 1) / x;
    };

    sort(begin(a), end(a));

    llong ans = 0;
    int pp = 0;
    for (int i = 0; i < n; i++) {
        if (i && a[i] != a[i - 1]) {
            pp = i;
        }
        int l = pp - 1, r = n;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (f(a[i], a[m]) < k) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r == n || f(a[i], a[r]) > k) {
            continue;
        }
        int j1 = r;
        l = pp - 1, r = n;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (f(a[i], a[m]) <= k) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == pp - 1 || f(a[i], a[l]) < k) {
            continue;
        }
        int j2 = l;
        ans += (j2 - j1 + 1);
    }

    cout << ans;

    return 0;
}//gmvcuc