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
        ll n, x, y;
        cin >> n >> x >> y;
        vector<int> as(n);
        for (int &b : as) {
            char c;
            cin >> c;
            b = (c == '1');
        }
        for (int &b : as) {
            char c;
            cin >> c;
            b ^= (c == '1');
        }
        ll ss = 0;
        for (int a : as) {
            ss += a;
        }
        if (ss & 1) {
            cout << "-1\n";
            continue;
        }
        if (ss == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (ss > 2) {
            cout << (ss / 2) * y << "\n";
        } else {
            int a, b;
            for (int i = 0; i < n; i++) {
                if (as[i]) {
                    a = b;
                    b = i;
                }
            }
            if (a + 1 == b) {
                cout << min(y * 2, x) << "\n";
            } else {
                cout << y << "\n";
            }
        }
    }
    return 0;
}