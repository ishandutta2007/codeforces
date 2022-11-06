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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> l(q + 1, -1), r(q + 1, -1);
    int fnz = -1;
    bool wq = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (l[a[i]] == -1) {
            l[a[i]] = i;
        }
        r[a[i]] = i;
        if (a[i] == q) {
            wq = true;
        }
        if (fnz == -1 && a[i] != 0) {
            fnz = a[i];
        }
    }

    set<pair<int, int>> s;
    for (int i = 1; i <= q; i++) {
        if (l[i] != -1) {
            s.insert({l[i], i});
            s.insert({r[i] + 1, -i});
        }
    }

    vector<int> b(n);
    set<int> cur;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.begin()->first == i) {
            int x = s.begin()->second;
            s.erase(s.begin());
            if (x > 0) {
                cur.insert(x);
            } else {
                cur.erase(-x);
            };
        }
        if (a[i] == 0 && !wq) {
            b[i] = q;
            wq = true;
        } else if (!cur.empty()) {
            b[i] = *cur.rbegin();
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
        if (b[i] == 0) {
            if (!wq) {
                b[i] = q;
                wq = true;
            } else {
                if (i == 0) {
                    b[i] = fnz;
                } else {
                    b[i] = b[i - 1];
                }
            }
        }
    }

    if (*max_element(b.begin(), b.end()) != q) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i : b) {
        cout << i << " ";
    }

    return 0;
}//pqxxoa