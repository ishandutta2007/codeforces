#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int M = int(1e9) + 7;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<vector<int>> ds(1111111);
    for (int i = 1; i < isz(ds); i++) {
        for (int j = i; j < isz(ds); j += i) {
            ds[j].push_back(i);
        }
    }

    int n;
    cin >> n;
    vector<llong> d(n + 1);
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = isz(ds[x]) - 1; j >= 0; j--) {
            if (ds[x][j] > n) {
                continue;
            }
            d[ds[x][j]] += d[ds[x][j] - 1];
            d[ds[x][j]] %= M;
        }
    }

    llong ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + d[i]) % M;
    }

    cout << ans;

    return 0;
}