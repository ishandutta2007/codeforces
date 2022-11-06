#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int in = 0; in < n; in++) {
        string s;
        cin >> s;
        if (s == "+") {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            x = max(x, a);
            y = max(y, b);
        } else {
            int h, w;
            cin >> h >> w;
            if (h > w) {
                swap(h, w);
            }
            if (x <= h && y <= w) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}//fblnxc