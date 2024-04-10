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
    int c0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            c0++;
        }
    }

    if (c0 == n) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        return 0;
    }

    int p = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[(i - 1 + n) % n]) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << "NO";
        return 0;
    }

    vector<llong> ans(n);
    ans[p] = a[p];
    int t = (p - 1 + n) % n;
    ans[t] = llong(1e17);
    while (ans[t] % ans[p] != a[t]) {
        ans[t]++;
    }
    t = (t - 1 + n) % n;
    while (t != p) {
        ans[t] = ans[(t + 1) % n] + a[t];
        t = (t - 1 + n) % n;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] % ans[(i + 1) % n] != a[i]) {
            assert(false);
        }
    }

    cout << "YES\n";
    for (llong i : ans) {
        cout << i << " ";
    }

    return 0;
}//lsuael