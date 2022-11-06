#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int c = 0;
    int ls = -1;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (x == 0 && ls != 0) {
            c++;
        }
        ls = x;
    }

    if (c == 0) {
        cout << 0;
    } else if (x < y) {
        cout << 1LL * x * (c - 1) + y;
    } else {
        cout << 1LL * c * y;
    }

    return 0;
}