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

const int mxN = 505;
ll fact[mxN];
ll invf[mxN];

ll choose(ll n, ll k) {
    return (((fact[n] * invf[k]) % MODL) * invf[n - k]) % MODL;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (ll i = 1; i < mxN; i++) {
        fact[i] = (fact[i - 1] * i) % MODL;
    }
    invf[mxN - 1] = pw(fact[mxN - 1], MOD - 2);
    for (ll i = mxN - 1; i; i--) {
        invf[i - 1] = (invf[i] * i) % MODL;
    }

    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1));
    for (int xi = 0; xi <= x; xi++) {
        dp[0][xi] = 1;
    }
    for (ll ni = 2; ni <= n; ni++) {
        for (ll xi = 0; xi <= x; xi++) {
            if (xi >= ni) {
                for (ll j = 0; j < ni - 1; j++) {
                    dp[ni][xi] += ((choose(ni, j) * pw(ni - 1, j)) % MODL) *
                                  dp[ni - j][xi - ni + 1];
                    dp[ni][xi] %= MOD;
                }
            }
            dp[ni][xi] += pw(min(xi, ni - 1), ni);
            dp[ni][xi] %= MOD;
        }
    }
    // for (int ni = 0; ni <= n; ni++) {
    //     for (int xi = 0; xi <= x; xi++) {
    //         cout << dp[ni][xi] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][x] << "\n";
    return 0;
}