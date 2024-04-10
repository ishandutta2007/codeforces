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
    vector<int> a;
    map<int, int> m;
    int c0 = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int b = 0;
        int mn = 0;
        for (char c : s) {
            if (c == '(') {
                b++;
            } else {
                b--;
            }
            mn = min(mn, b);
        }
        if (b >= 0 && mn < 0 || b < 0 && mn < b) {
            continue;
        }
        if (b < 0) {
            m[b]++;
        } else if (b == 0) {
            c0++;
        } else {
            a.push_back(b);
        }
    }

    int ans = c0 / 2;
    for (int b : a) {
        if (m[-b]) {
            ans++;
            m[-b]--;
        }
    }

    cout << ans;

    return 0;
}//zslijg