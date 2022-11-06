#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (m + 1 < n) {
        cout << "Impossible\n";
        return 0;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n && m > 0; i++) {
        for (int j = i + 1; j <= n && m > 0; j++) {
            if (__gcd(i, j) == 1) {
                ans.emplace_back(i, j);
                --m;
            }
        }
    }

    if (m == 0) {
        cout << "Possible\n";
        for (auto& i : ans) {
            cout << i.first << " " << i.second << "\n";
        }
    } else {
        cout << "Impossible\n";
    }

    return 0;
}