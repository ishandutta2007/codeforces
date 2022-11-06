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
    for (auto& i : a) {
        cin >> i;
    }

    llong ans = 0;
    for (int i = 1; i < n; i++) {
        llong x = (a[i - 1] + k - 1) / k;
        ans += x;
        llong l = x * k - a[i - 1];
        a[i] = max(0LL, a[i] - l);
    }
    ans += (a[n - 1] + k - 1) / k;

    cout << ans;

    return 0;
}//hpesvh