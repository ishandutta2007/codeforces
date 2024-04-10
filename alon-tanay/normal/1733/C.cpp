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
        int n;
        cin >> n;
        vector<int> as(n);
        for (int &a : as) {
            cin >> a;
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        cout << n - 1 << "\n";
        if ((as[0] + as[n - 1]) & 1) {
            as[n - 1] = as[0];
        } else {
            as[0] = as[n - 1];
        }
        cout << 1 << " " << n << "\n";
        for (int i = 1; i < n - 1; i++) {
            if ((as[i] + as[0]) & 1) {
                cout << 1 << " " << i + 1 << "\n";
            } else {
                cout << (i + 1) << " " << n << "\n";
            }
        }
    }
    return 0;
}