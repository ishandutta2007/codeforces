#ifdef VSE
#define _GLIBCXX_DEBUG
#endif
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
    cin >> n >> k;
    vector<int> a(n);
    int s = 0;
    for (auto& i : a) {
        cin >> i;
        s += i;
    }

    if (s % k != 0) {
        cout << "No";
        return 0;
    }

    s /= k;
    int cs = 0;
    int last = -1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cs += a[i];
        if (cs > s) {
            cout << "No";
            return 0;
        }
        if (cs == s) {
            ans.push_back(i - last);
            last = i;
            cs = 0;
        }
    }

    cout << "Yes\n";
    for (auto& i : ans) {
        cout << i << " ";
    }


    return 0;
}//jaennx