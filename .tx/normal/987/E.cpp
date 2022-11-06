#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int a[1111111];
int b[1111111];

llong mmerge(int l1, int r1, int l2, int r2) {
    llong res = 0;
    int bi = l1;
    int sb = bi;
    while (l1 < r1 || l2 < r2) {
        if (l1 < r1 && (l2 >= r2 || a[l1] < a[l2])) {
            b[bi++] = a[l1++];
        } else {
            res += r1 - l1;
            b[bi++] = a[l2++];
        }
    }

    for (int i = sb; i < bi; i++) {
        a[i] = b[i];
    }
    return res;
}

llong msort(int l, int r) {
    if (l + 1 == r) {
        return 0;
    }

    int m = (l + r) >> 1;
    return msort(l, m) + msort(m, r) + mmerge(l, m, m, r);
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ci = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == i) {
            ci++;
        }
    }

    llong inv = msort(0, n);

    for (int i = 1; i < n; i++) {
        assert(a[i - 1] < a[i]);
    }
//    cerr << inv << " " << fixed << setprecision(5) << 1.0 * inv / n << " " << ci << endl;

    if (inv % 2 == n % 2) {
        cout << "Petr";
    } else {
        cout << "Um_nik";
    }

    return 0;
}