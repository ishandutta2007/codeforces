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

    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    set<pair<int, int>> q;
    vector<int> ans(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (q.empty() || q.begin()->first > a[i].first) {
            ans[a[i].second] = ++c;
        } else {
            ans[a[i].second] = q.begin()->second;
            q.erase(q.begin());
        }

        q.insert({a[i].first + d + 1, ans[a[i].second]});
    }

    cout << c << "\n";
    for (int i : ans) {
        cout << i << " ";
    }


    return 0;
}//ljckce