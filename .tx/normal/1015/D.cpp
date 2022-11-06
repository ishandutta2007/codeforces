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

    int n, k;
    llong s;
    cin >> n >> k >> s;
    if (s < k) {
        cout << "NO";
        return 0;
    }
    int x = 0;
    vector<int> ans;
    while (k) {
        if (s - (n - 1) >= k - 1) {
            s -= (n - 1);
            x = x == 0 ? n - 1 : 0;
            ans.push_back(x);
        } else {
            int t = s - (k - 1);
            s -= t;
            if (x + t >= 0 && x + t < n) {
                x += t;
            } else {
                x -= t;
            }
            ans.push_back(x);
        }
        k--;
    }

    if (s != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}//hjzxbx