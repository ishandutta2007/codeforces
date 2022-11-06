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
    vector<pair<pair<int, int>, int>> a(n);
    vector<llong> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.second;
        ans[i] = a[i].first.second;
    }

    sort(a.begin(), a.end());
    llong s = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++) {
        ans[a[i].second] += s;
        q.push(a[i].first.second);
        s += a[i].first.second;
        while (q.size() > k) {
            s -= q.top();
            q.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}