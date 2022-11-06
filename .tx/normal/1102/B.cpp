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
    map<int, vector<int>> ps;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ps[x].push_back(i);
        if (isz(ps[x]) > k) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> ans(n);
    int c = 0;
    for (auto& i : ps) {
        for (auto& j : i.second) {
            ans[j] = c;
            c = (c + 1) % k;
        }
    }

    cout << "YES\n";

    for (auto& i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}//eypkay