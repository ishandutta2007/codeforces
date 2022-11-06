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
    int n = isz(s);
    deque<int> d;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            d.push_back(i);
        } else {
            d.push_front(i);
        }
    }

    vector<char> ans(n);
    for (int i = 0; i < n; i++) {
        ans[d[i]] = s[i];
    }

    for (char c : ans) {
        cout << c;
    }

    return 0;
}//xwzicn