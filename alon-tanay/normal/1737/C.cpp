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

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int r1, c1, r2, c2, r3, c3;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        int x, y;
        cin >> x >> y;
        int x1, y1;
        if (((r1 + c1) & 1) == ((r2 + c2) & 1)) {
            x1 = r3;
            y1 = c3;
        } else if (((r1 + c1) & 1) == ((r3 + c3) & 1)) {
            x1 = r2;
            y1 = c2;
        } else {
            x1 = r1;
            y1 = c1;
        }
        if ((x1 == 1 || x1 == n) && (y1 == 1 || y1 == n)) {
            if (x == x1 || y == y1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if (((x1 & 1) != (x & 1)) && ((y1 & 1) != (y & 1))) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}