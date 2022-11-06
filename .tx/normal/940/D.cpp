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
    string b;
    cin >> b;
    int r = 1e9, l = -1e9;
    bool ar = true, al = true;
    for (int i = 4; i < n; i++) {
        if (b[i] == '1') {
            if (b[i - 1] == '0') {
                int mx = -1e9;
                for (int t = 0; t < 5; t++) {
                    mx = max(mx, a[i - t]);
                }
                l = max(l, mx + 1);
                al = false;
            } else {
                if (b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1') {
                    int mn = 1e9;
                    for (int t = 0; t < 5; t++) {
                        mn = min(mn, a[i - t]);
                    }
                    r = max(r, mn);
                }
            }
        } else {
            if (b[i - 1] == '1') {
                int mn = 1e9;
                for (int t = 0; t < 5; t++) {
                    mn = min(mn, a[i - t]);
                }
                r = min(r, mn - 1);
                ar = false;
            } else {
                if (b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0') {
                    int mx = -1e9;
                    for (int t = 0; t < 5; t++) {
                        mx = max(mx, a[i - t]);
                    }
                    l = min(l, mx);
                }
            }
        }
    }

    if (l > r) {
        if (al) {
            l = r;
        } else {
            r = l;
        }
    }

    cout << l << " " << r;

    return 0;
}//zmwdxk