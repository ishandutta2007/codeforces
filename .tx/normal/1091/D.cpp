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

llong mpow(llong a, llong p) {
    llong r = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            r = r * a % M;
        }
        a = a * a % M;
    }
    return r;
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    llong f = 1;
    for (int i = 2; i <= n; i++) {
        f = f * i % M;
    }

    llong ans = f;
    llong c = 1;
    for (int i = 2; i < n; i++) {
        c = c * i % M;
        ans = (ans + f - f * mpow(c, M - 2)) % M;
    }

    ans = (ans + M) % M;
    cout << ans << "\n";


    return 0;
}//uhglou