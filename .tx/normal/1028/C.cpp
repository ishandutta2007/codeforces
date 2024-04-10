#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

struct rect {
    int x1, y1, x2, y2;
};

rect f(rect a, rect b) {
    return rect{max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<rect> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }

    vector<rect> l(n), r(n);
    l[0] = a[0];
    for (int i = 1; i < n; i++) {
        l[i] = f(l[i - 1], a[i]);
    }

    r[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        r[i] = f(r[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++) {
        const int inf = 2e9;
        rect cur = rect{-inf, -inf, inf, inf};
        if (i) {
            cur = f(cur, l[i - 1]);
        }
        if (i < n - 1) {
            cur = f(cur, r[i + 1]);
        }
        if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2) {
            cout << cur.x1 << " " << cur.y1 << "\n";
            return 0;
        }
    }

    assert(false);

    return 0;
}//kyeaxi