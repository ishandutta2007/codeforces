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
    llong t;
    cin >> n >> t;
    vector<llong> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i && x[i] < x[i - 1]) {
            cout << "No";
            return 0;
        }

        if (x[i] < i + 1) {
            cout << "No";
            return 0;
        }
    }

    vector<llong> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + t;
    }

    int p = 1;
    for (int i = 0; i < n; i++) {
        p = max(p, i + 1);
        if (p > x[i]) {
            cout << "No";
            return 0;
        }

        while (p < x[i]) {
            b[p - 1] = a[p] + t;
            p++;
        }
    }

    for (int i = 1; i < n; i++) {
        b[i] = max(b[i], b[i - 1] + 1);
    }

    p = 1;
    for (int i = 0; i < n; i++) {
        p = max(p, i + 1);
        while (p < n && a[p] + t <= b[p - 1]) {
            p++;
        }
        if (p != x[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n";
    for (llong i : b) {
        cout << i << " ";
    }

    return 0;
}//vbvvol