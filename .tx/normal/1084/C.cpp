#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    const int M = int(1e9) + 7;

    llong ans = 1;

    int cur = 0;
    for (char c : s) {
        if (c == 'a') {
            cur++;
        } else if (c == 'b') {
            ans *= (cur + 1);
            ans %= M;
            cur = 0;
        }
    }

    ans *= (cur + 1);
    ans %= M;

    cout << (ans - 1 + M) % M;

    return 0;
}