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

    int n;
    cin >> n;
    int c = 1;

    while (n) {
        if (n == 3) {
            cout << c << " " << c << " " << 3 * c;
            break;
        }
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << c << " ";
        }
        n /= 2;
        c *= 2;
    }

    return 0;
}//tysvgn