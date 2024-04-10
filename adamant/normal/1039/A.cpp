#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x),end(x)

void fail() {
    cout << "No" << endl;
    exit(0);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int a[n], x[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l[n], r[n];
    set<int, less<int>> upd_l;
    for(int i = 0; i < n; i++) {
        l[i] = a[i] + t;
        r[i] = a[n - 1] + 2 * t;
        upd_l.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
        l[x[i]] = max(l[x[i]], a[i] + t);
        if(i <= x[i]) {
            if(x[i] < n - 1) {
                r[x[i]] = min(r[x[i]], a[x[i] + 1] + t - 1);
            }
            for(int j = i; j < x[i]; j++) {
                auto it = upd_l.lower_bound(j);
                if(it == end(upd_l) || *it >= x[i]) {
                    break;
                }
                j = *it;
                upd_l.erase(it);
                l[j] = max(l[j], a[j + 1] + t);
            }
        } else {
            fail();
        }
    }
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            l[i] = max(l[i], l[i - 1] + 1);
        }
        if(l[i] > r[i]) {
            fail();
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++) {
        cout << l[i] << ' ';
    }
    return 0;
}