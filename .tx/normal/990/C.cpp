#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int kg = 0;
    map<int, vector<int>> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int b = 0;
        int mb = 0;
        for (char c : s) {
            if (c == '(') {
                b++;
            } else {
                b--;
            }
            mb = min(b, mb);
        }
        a[i] = {b, mb};
        if (b == 0 && mb >= 0) {
            kg++;
        }
        if (b < 0) {
            m[b].push_back(mb);
        }
    }

    for (auto& i : m) {
        sort(i.second.begin(), i.second.end());
    }

    llong ans = 1LL * kg * kg;

    for (int i = 0; i < n; i++) {
        int b = a[i].first;
        int mb = a[i].second;
        if (b <= 0 || mb < 0) {
            continue;
        }

        auto it = m.find(-b);
        if (it == m.end()) {
            continue;
        }

        auto tt = lower_bound(it->second.begin(), it->second.end(), -b);
        int x = it->second.end() - tt;
        ans += x;
    }

    cout << ans;

    return 0;
}