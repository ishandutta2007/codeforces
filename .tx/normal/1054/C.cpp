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
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<int> a(n);
    vector<int> ll = l, rr = r;
    vector<int> d(n);

    for (int k = n; k > 0; k--) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (d[i]) {
                continue;
            }
            if (l[i] == 0 && r[i] == 0) {
                c++;
                a[i] = k;
            }
        }

        int x = 0;
        for (int i = 0; i < n; i++) {
            if (d[i]) {
                continue;
            }
            if (l[i] == 0 && r[i] == 0) {
                d[i] = true;
                x++;
                continue;
            }
            l[i] -= x;
            r[i] -= c - x;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                x++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                y++;
            }
        }

        if (x != ll[i] || y != rr[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i : a) {
        cout << i << " ";
    }

    return 0;
}//pgvhkf