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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int c = 0;
    int ans = 0;
    int s = 0;
    for (int h = 222222; h >= 0; h--) {
        while (c < n && a[c] > h) {
            c++;
        }
        if (c == n) {
            break;
        }
        if (s + c > k) {
            s = c;
            ans++;
        } else {
            s += c;
        }
    }

    if (s) {
        ans++;
    }

    cout << ans;

    return 0;
}//irtdvj