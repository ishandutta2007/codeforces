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
    string s;
    cin >> s;

    int ans = 0;
    int cg = 0, cs = 0;
    int ag = count(begin(s), end(s), 'G');
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n) {
            if (s[j] == 'G') {
                cg++;
            } else {
                cs++;
            }
            j++;
            if (cs <= 1) {
                ans = max(ans, cg + 1);
            } else {
                break;
            }
        }
        if (s[i] == 'G') {
            cg--;
        } else {
            cs--;
        }
    }

    cout << min(ans, ag);

    return 0;
}//navqjo