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

    int n, a, b;
    cin >> n >> a >> b;
    int s = 0;
    int s0 = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        if (i) {
            q.push(x);
        } else {
            s0 = x;
        }
    }

    int ans = 0;
    while (1LL * s0 * a < 1LL * s * b) {
        ans++;
        s -= q.top();
        q.pop();
    }

    cout << ans;

    return 0;
}