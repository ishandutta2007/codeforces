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

    int a, b;
    cin >> a >> b;
    int l = 0, r = 333333;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        int mm = m;
        int x = a, y = b;
        while ((x >= m || y >= m) && m > 0) {
            if (x >= m) {
                x -= m;
            } else {
                y -= m;
            }
            --m;
        }
        if (m == 0) {
            l = mm;
        } else {
            r = mm;
        }
    }

    vector<int> x, y;
    while ((b >= l || a >= l) && l > 0) {
        if (a >= l) {
            x.push_back(l);
            a -= l;
        } else {
            y.push_back(l);
            b -= l;
        }
        --l;
    }

    cout << x.size() << "\n";
    for (int i : x) {
        cout << i << " ";
    }
    cout << "\n" << y.size() << "\n";
    for (int i : y) {
        cout << i << " ";
    }

    return 0;
}//ghrohp