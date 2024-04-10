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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int md = (l + r) >> 1;
        int cm = m;
        int ck = k;
        bool ok = true;
        for (int i = n - md; i < n; i++) {
            if (a[i] <= ck) {
                ck -= a[i];
            } else {
                if (a[i] > k || cm == 1) {
                    ok = false;
                    break;
                }
                cm--;
                ck = k - a[i];
            }
        }
        if (ok) {
            l = md;
        } else {
            r = md;
        };
    }

    cout << l;

    return 0;
}//mnbyye