#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int M = 998244353;

llong d[2222][2222];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    d[1][0] = m;
    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][0];
        for (int j = 1; j <= k; j++) {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1] * (m - 1)) % M;
        }
    }

    cout << d[n][k];

    return 0;
}//wfiggi