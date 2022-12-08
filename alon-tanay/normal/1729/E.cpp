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

    for (int i = 0; i < 25; i++) {
        cout << "? 1 " << (i + 2) << endl;
        ll d1;
        cin >> d1;
        if (d1 == -1) {
            cout << "! " << (i + 1) << endl;
            return 0;
        }
        cout << "? " << (i + 2) << " 1" << endl;
        ll d2;
        cin >> d2;
        if (d1 != d2) {
            cout << "! " << d1 + d2 << endl;
            return 0;
        }
    }
    return 0;
}