#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    for (int itt = 0; itt < tt; itt++) {
        int n, m;
        llong t;
        cin >> n >> m >> t;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        auto b = a;
        sort(begin(b), end(b));
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int md = (l + r) >> 1;
            int d = b[md - 1];
            int done = 0;
            llong ct = 0;
            int c = 0;
            llong cs = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] <= d) {
                    if (ct + a[i] > t) {
                        break;
                    }
                    ct += a[i];
                    cs += a[i];
                    done++;
                    c++;
                    if (c == m) {
                        c = 0;
                        ct += cs;
                        cs = 0;
                    }
                }
            }

            if (done >= md) {
                l = md;
            } else {
                r = md;
            }
        }
        cout << l << " " << (l == 0 ? 1 : b[l - 1]) << "\n";
    }

    return 0;
}