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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                inv++;
            }
        }
    }

    inv %= 2;

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        int l, r;
        cin >> l >> r;
        r -= l - 1;
        int d = r * (r - 1) / 2;
        if (d % 2) {
            inv ^= 1;
        }

        cout << (inv % 2 ? "odd" : "even") << "\n";
    }

    return 0;
}//xyqqkf