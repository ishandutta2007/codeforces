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

    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = n - x;
        a[x].push_back(i);
    }

    vector<int> ans(n);
    int cc = 0;
    for (int i = 1; i <= n; i++) {
        if (isz(a[i]) % i != 0) {
            cout << "Impossible";
            return 0;
        }
        for (int j = 0; j < isz(a[i]); j++) {
            if (j % i == 0) {
                cc++;
            }
            ans[a[i][j]] = cc;
        }
    }

    cout << "Possible\n";

    for (auto& i : ans) {
        cout << i << " ";
    }

    return 0;
}//fscpoe