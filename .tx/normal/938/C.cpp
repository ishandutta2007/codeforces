#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    map<int, int> sq;
    for (int i = 1; i * i <= int(2e9); i++) {
        sq[i * i] = i;
    }

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "1 1\n";
            continue;
        }
//        if (sq.find(x) != end(sq)) {
//            cout << sq[x] << " " << sq[x] + 1 << "\n";
//            continue;
//        }

        bool ok = false;

        for (int i = 1; i * i <= int(2e9); i++) {
            if (sq.find(i * i - x) != end(sq)) {
                int n = i;
                int m = n / sq[i * i - x];
                if (n / m != sq[i * i - x]) {
                    continue;
                }
                cout << n << " " << m << "\n";
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
        }
    }

    return 0;
}//efscrl