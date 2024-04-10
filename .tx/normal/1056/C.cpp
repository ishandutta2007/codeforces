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
//    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int n2 = 2 * n;
    vector<int> a(n2);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> p(n2, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        p[x] = y;
        p[y] = x;
    }

    int t;
    cin >> t;

    if (t == 1) {
        int nn = n;
        while (nn) {
            int x = -1;
            int y = -1;
            for (int i = 0; i < n2; i++) {
                if (p[i] != -1 && (x == -1 || a[i] > y)) {
                    x = i;
                    y = a[i];
                }
            }

            if (x != -1) {
                cout << x + 1 << endl;
                a[x] = -1;
                a[p[x]] = -1;
                p[p[x]] = -1;
                p[x] = -1;
                cin >> x;
                --nn;
                continue;
            }

            for (int i = 0; i < n2; i++) {
                if (a[i] != -1 && (x == -1 || a[i] > y)) {
                    x = i;
                    y = a[i];
                }
            }

            cout << x + 1 << endl;
            cin >> y;
            --y;
            a[x] = -1;
            a[y] = -1;
            --nn;
        }
    } else {
        for (int nn = n; nn > 0; nn--) {
            int o;
            cin >> o;
            --o;
            if (p[o] != -1) {
                cout << p[o] + 1 << endl;
                a[o] = -1;
                a[p[o]] = -1;
                p[p[o]] = -1;
                p[o] = -1;
                continue;
            }

            a[o] = -1;
            int x = -1;
            int y = -1;
            for (int i = 0; i < n2; i++) {
                if (p[i] != -1 && (x == -1 || a[i] > y)) {
                    x = i;
                    y = a[i];
                }
            }

            if (x != -1) {
                cout << x + 1 << endl;
                a[x] = -1;
                p[p[x]] = -1;
                p[x] = -1;
                continue;
            }

            for (int i = 0; i < n2; i++) {
                if (a[i] != -1 && (x == -1 || a[i] > y)) {
                    x = i;
                    y = a[i];
                }
            }

            cout << x + 1 << endl;
            a[x] = -1;
        }
    }

    return 0;
}//jbhrvi