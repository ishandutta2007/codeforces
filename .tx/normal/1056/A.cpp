#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int k;
    cin >> k;
    set<int> a;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }


    for (int i = 1; i < n; i++) {
        cin >> k;
        set<int> b;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (a.count(x)) {
                b.insert(x);
            }
        }
        a = b;
    }

    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}//kozcpp