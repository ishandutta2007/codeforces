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
        ll res = 0;
        vector<pl> as(n);
        vector<pl> evs;
        ll mx = 0;
        for (pl &a : as) {
            cin >> a.f >> a.s;
            mx = max(mx, min(a.f, a.s));
        }
        for (pl a : as) {
            ll big = max(a.f, a.s);
            ll small = min(a.f, a.s);
            if (big <= mx) {
                res += small * 2;
            } else {
                res += big * 2;
                evs.push_back({big, small - big});
            }
        }
        sort(evs.begin(), evs.end());
        ll best = res + mx * 2;
        for (pl ev : evs) {
            res += ev.s * 2;
            best = min(best, res + ev.f * 2);
        }
        cout << best << "\n";
    }
    return 0;
}