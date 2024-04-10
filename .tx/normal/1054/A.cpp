#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

void rd() {}
template <typename T, typename... Ts>
void rd(T& a, Ts&... as) { cin >> a; rd(as...); }
#define vars(a, ...) a __VA_ARGS__; rd(__VA_ARGS__)

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vars(llong, x, y, z, t1, t2, t3);
    llong a = abs(x - y) * t1;
    llong b = abs(x - y) * t2 + abs(z - x) * t2 + t3 * 3;
    if (b <= a) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}//bksgdl