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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vector<int> gone(n);
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        --x;
        if (gone[x]) {
            cout << 0 << " ";
            continue;
        }
        int ans = 1;
        while (a.back() != x) {
            gone[a.back()] = 1;
            a.pop_back();
            ans++;
        }
        gone[x] = 1;
        a.pop_back();
        cout << ans << " ";
    }

    return 0;
}//kjtgtb