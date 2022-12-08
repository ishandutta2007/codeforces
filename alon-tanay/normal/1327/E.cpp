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

const int MOD = 998244353;
const ll MODL = 998244353;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

ll pw(ll b, ll e) {
    if (e < 0) {
        return 0;
    }
    ll res = 1;
    while (e) {
        if (e & 1) {
            res *= b;
            res %= MODL;
        }
        e >>= 1;
        b *= b;
        b %= MODL;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++) {
        ll cur = (18LL * pw(10, n - i)) % MODL;
        cur += (((n - i - 1) * 81LL * 10LL) % MOD) * pw(10, n - i - 2);
        cur %= MOD;
        cout << cur << " ";
    }
    cout << "10\n";
    return 0;
}