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

    int n, x;
    cin >> n >> x;
    set<int> s;
    set<int> sx;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
        sx.insert(a & x);
    }

    if (s.size() != n) {
        cout << 0;
        return 0;
    }

    if (sx.size() == n) {
        cout << -1;
        return 0;
    }

    for (int i : s) {
        if ((i & x) != i && s.count(i & x)) {
            cout << 1;
            return 0;
        }
    }

    cout << 2;

    return 0;
}