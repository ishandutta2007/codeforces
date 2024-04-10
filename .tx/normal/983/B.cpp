#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int get(vector<int> a) {
    vector<int> b;
    while (true) {
        int x = 1;
        while (x * 2 <= a.size()) {
            x *= 2;
        }
        if (x == a.size()) {
            int res = 0;
            for (int i : a) {
                res ^= i;
            }
            return res;
        }

        b.clear();
        for (int i = 0; i + x < a.size(); i++) {
            b.push_back(a[i] ^ a[i + x]);
        }
        a.swap(b);
    }
}

int d[5555][5555];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
//    vector<int> c(n);
//    for (int i = 0; i < n; i++) {
//        c.clear();
//        for (int j = i; j < n; j++) {
//            c.push_back(a[j]);
//            d[i][j] = get(c);
//        }
//    }

    for (int i = 0; i < n; i++) {
        d[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            d[i][j] = d[i][j - 1] ^ d[i + 1][j];
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            d[i][j] = max(d[i][j], max(d[i + 1][j], d[i][j - 1]));
        }
    }

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << d[x][y] << "\n";
    }

    return 0;
}