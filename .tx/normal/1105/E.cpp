#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1;
        return 0;
    }
    int x;
    cin >> x;
    map<string, int> mp;
    set<int> cur;
    vector<llong> g(k);
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            cur.clear();
        } else {
            string s;
            cin >> s;
            if (!mp.count(s)) {
                mp[s] = isz(mp);
            }
            x = mp[s];
            for (int i : cur) {
                if (i != x) {
                    g[i] |= 1LL << x;
                    g[x] |= 1LL << i;
                }
            }
            cur.insert(x);
        }
    }

    x = k / 2;
    int y = k - x;

    vector<int> a(1 << x);
    for (int m = 1; m < (1 << x); m++) {
        int t = __builtin_ctz(m);
        int nb = m & g[t];
        a[m] = max(a[m ^ (1 << t)], a[m ^ nb ^ (1 << t)] + 1);
    }

    vector<int> b(1 << y);
    for (int m = 1; m < (1 << y); m++) {
        int t = __builtin_ctz(m);
        int nb = m & (g[t + x] >> x);
        b[m] = max(b[m ^ (1 << t)], b[m ^ nb ^ (1 << t)] + 1);
    }

    int ans = 0;

    for (int m = 0; m < (1 << x); m++) {
        int al = 0;
        for (int i = 0; i < x; i++) {
            if ((m >> i) & 1) {
                al |= g[i] >> x;
            }
        }
        al ^= (1 << y) - 1;
        ans = max(ans, a[m] + b[al]);
    }//

    cout << ans << "\n";

    return 0;
}