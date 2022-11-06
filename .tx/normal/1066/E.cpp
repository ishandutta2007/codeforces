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
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    const int M = 998244353;
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int b1 = 0;
    for (char c : b) {
        if (c == '1') {
            b1++;
        }
    }
    llong ans = 0;
    llong p2 = 1;
    for (int i = 0; i < min(n, m); i++) {
        if (a[n - 1 - i] == '1') {
            ans = (ans + p2 * b1) % M;
        }
        if (b[m - 1 - i] == '1') {
            b1--;
        }
        p2 = p2 * 2 % M;
    }

    cout << ans;

    return 0;
}//ohvrvn