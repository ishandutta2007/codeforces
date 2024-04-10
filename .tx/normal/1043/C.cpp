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

    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    int f = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] - 'a' == f) {
            ans[i] = 1;
            f = 1 - f;
        }
    }

    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}//jjuqjf