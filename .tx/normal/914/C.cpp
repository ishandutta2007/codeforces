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

void add(int& a, int b) {
    a = (a + b % M) % M;
}

int o[1111][1111][2];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;
    if (k == 0) {
        cout << 1;
        return 0;
    }

    vector<int> d(1111);
    d[1] = 0;
    for (int i = 2; i < isz(d); i++) {
        d[i] = d[__builtin_popcount(i)] + 1;
    }

    o[0][0][1] = 1;
    int n = isz(s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '1') {
                add(o[i + 1][j + 1][1], o[i][j][1]);
                add(o[i + 1][j + 1][0], o[i][j][0]);
                add(o[i + 1][j][0], o[i][j][1] + o[i][j][0]);
            } else {
                add(o[i + 1][j][1], o[i][j][1]);
                add(o[i + 1][j + 1][0], o[i][j][0]);
                add(o[i + 1][j][0], o[i][j][0]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == k - 1) {
            add(ans, o[n][i][0] + o[n][i][1]);
        }
    }

    if (k == 1) {
        add(ans, M - 1);
    }

    cout << ans << "\n";

    return 0;
}//bywcnd