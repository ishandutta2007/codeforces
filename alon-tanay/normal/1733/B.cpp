#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (x > 0 && y > 0) {
            cout << "-1\n";
            continue;
        }
        int mx = max(x, y);

        if (mx == 0 || n - 1 < mx) {
            cout << "-1\n";
            continue;
        }
        bool fail = false;
        vector<int> res(mx, 1);
        int idx = 2 + mx;
        if (idx > n + 1) {
            fail = true;
        } else {
            while (idx <= n) {
                for (int i = 0; i < mx; i++) {
                    res.push_back(idx);
                }
                idx += mx;
                if (idx > n + 1) {
                    fail = true;
                    break;
                }
            }
        }
        if (fail) {
            cout << "-1\n";
            continue;
        }
        for (int r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}