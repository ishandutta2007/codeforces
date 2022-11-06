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

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<array<int, 2>> q(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        q[i][0] = x;
        q[i][1] = y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<int> ans(n);
    ans[0] = 0;
    ans[1] = a[0][0];
    for (int i = 1; i + 1 < n; i++) {
        for (int j : a[ans[i]]) {
            if (j != ans[i - 1]) {
                ans[i + 1] = j;
                break;
            }
        }
    }

    bool ok = true;

    for (int i = 0; i < n; i++) {
        array<int, 2> t = { ans[(i + 1) % n], ans[(i + 2) % n] };
        array<int, 2> p = q[ans[i]];
        sort(begin(t), end(t));
        sort(begin(p), end(p));
        if (t != p) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        reverse(begin(ans) + 1, end(ans));
    }

    for (int i : ans) {
        cout << i + 1 << " ";
    }


    return 0;
}//htwvlm