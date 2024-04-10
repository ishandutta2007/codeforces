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

    int n, k;
    cin >> n >> k;
    map<int, int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st[x] = i;
    }
    if (st.size() < k) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
        cout << st.begin()->second + 1 << " ";
        st.erase(st.begin());
    }

    return 0;
}