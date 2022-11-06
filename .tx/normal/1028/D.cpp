#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    set<int> buy, sell, u;
    llong ans = 1;
    for (int in = 0; in < n; in++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "ADD") {
            if (!buy.empty() && x < *buy.rbegin()) {
                buy.insert(x);
            } else if (!sell.empty() && x > *sell.begin()) {
                sell.insert(x);
            } else {
                u.insert(x);
            }
        } else {
            if (buy.count(x)) {
                if (x < *buy.rbegin()) {
                    ans = 0;
                }
                buy.erase(x);
                sell.insert(u.begin(), u.end());
                u.clear();
            } else if (sell.count(x)) {
                if (x > *sell.begin()) {
                    ans = 0;
                }
                sell.erase(x);
                buy.insert(u.begin(), u.end());
                u.clear();
            } else {
                for (int i : u) {
                    if (i < x) {
                        buy.insert(i);
                    } else if (i > x) {
                        sell.insert(i);
                    }
                }
                u.clear();
                ans = (ans * 2) % (int(1e9) + 7);
            }
        }
    }

    ans = (ans * (u.size() + 1)) % (int(1e9) + 7);

    cout << ans;

    return 0;
}//llfuvd