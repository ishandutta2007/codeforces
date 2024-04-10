#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int ask(int y) {
    cout << y << endl;
    int x;
    cin >> x;
    if (x == 0) {
        exit(0);
    }
    return x;
}

int main() {
#ifdef VSE
//    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = ask(1);
    }

    int l = 2, r = m;
    int pt = 0;
    while (true) {
        int t = (l + r) >> 1;
        int f = ask(t) * a[pt];
        pt = (pt + 1) % n;
        if (f < 0) {
            r = t - 1;
        } else {
            l = t + 1;
        }
    }

    return 0;
}//trslul