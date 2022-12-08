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
        ll n, k;
        cin >> n >> k;
        vector<ll> ls(k);
        for (ll &a : ls) {
            cin >> a;
        }
        if (k == 1) {
            cout << "Yes\n";
            continue;
        }
        bool fail = false;
        for (ll i = 1; i < k - 1; i++) {
            if (ls[i] - ls[i - 1] > ls[i + 1] - ls[i]) {
                fail = true;
            }
        }
        ll x = ls[1] - ls[0];
        if (x >= 0) {
            if ((n - k + 1) * x < ls[0]) {
                fail = true;
            }
        } else {
            if ((n - k + 1) * x < ls[0]) {
                fail = true;
            }
        }
        cout << (fail ? "No\n" : "Yes\n");
    }
    return 0;
}