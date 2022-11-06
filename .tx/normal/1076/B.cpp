#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto sz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    llong n;
    cin >> n;
    llong ans = 0;
    while (n) {
        llong d = n;
        for (llong i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        if (d == n) {
            ans++;
            n = 0;
        } else if (d == 2) {
            ans += n / 2;
            n = 0;
        } else {
            ans++;
            n -= d;
        }
    }

    cout << ans;


    return 0;
}//xhsysz