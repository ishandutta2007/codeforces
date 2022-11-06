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

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        if (i) {
            a[i] += a[i - 1];
        }
    }

    const int M = int(1e9) + 7;
    vector<llong> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % M;
    }

    for (int iq = 0; iq < q; iq++) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int x = a[r] - (l ? a[l - 1] : 0);
        int y = r - l + 1 - x;

        llong ans = (p2[x] - 1) * p2[y] % M;
        cout << ans << "\n";
    }

    return 0;
}//snmkkz