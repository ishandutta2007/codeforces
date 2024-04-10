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
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push(x);
    }

    llong ans = 0;
    for (int i = 0; i < n; i++) {
        if (b.empty() || (!a.empty() && a.top() > b.top())) {
            ans += a.top();
            a.pop();
        } else {
            b.pop();
        }
        if (a.empty() || (!b.empty() && b.top() > a.top())) {
            ans -= b.top();
            b.pop();
        } else {
            a.pop();
        }
    }

    cout << ans;

    return 0;
}//ounxwe