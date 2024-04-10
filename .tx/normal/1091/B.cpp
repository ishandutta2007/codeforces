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
    vector<pair<int, int>> a(n);
    for (auto& i : a) {
        cin >> i.first >> i.second;
    }

    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (auto& p : a) {
            cnt[{p.first + x, p.second + y}]++;
        }
    }

    for (auto& i : cnt) {
        if (i.second == n) {
            cout << i.first.first << " " << i.first.second;
            break;
        }
    }

    return 0;
}//hnbbpv