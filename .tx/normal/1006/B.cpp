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
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }

    sort(b.rbegin(), b.rend());

    int ans = 0;
    vector<bool> t(n);
    for (int i = 0; i < k; i++) {
        t[b[i].second] = true;
        ans += b[i].first;
    }

    cout << ans << "\n";
    vector<int> is;
    int cur = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cur++;
        if (t[i]) {
            is.push_back(cur);
            tot += cur;
            cur = 0;
        }
    }

    is.back() += n - tot;

    for (int i : is) {
        cout << i << " ";
    }


    return 0;
}