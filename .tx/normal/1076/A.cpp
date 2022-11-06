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

    int n;
    string s;
    cin >> n >> s;
    int p = n - 1;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] > s[i + 1]) {
            p = i;
            break;
        }
    }
    s.erase(s.begin() + p);
    cout << s;

    return 0;
}//avvdcv