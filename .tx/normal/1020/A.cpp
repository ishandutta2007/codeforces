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

    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int ik = 0; ik < k; ik++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) {
            cout << abs(fa - fb) << "\n";
            continue;
        }
        if (a <= fa && fa <= b) {
            cout << abs(ta - tb) + abs(fb - fa) << "\n";
            continue;
        }
        cout << min(abs(fa - a) + abs(ta - tb) + abs(fb - a), abs(fa - b) + abs(ta - tb) + abs(fb - b)) << "\n";
    }

    return 0;
}//vasmxk