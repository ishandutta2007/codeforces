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

// vector<int> dp;
vector<int> as;

// int rec(int l, int r) {
//     if (dp[l] != -1) {
//         return dp[l];
//     }
//     int res;

//     for (int) dp[l] = res;
//     return res;
// }

const int mxN = 100005;

ll pw(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) {
            res *= b;
            res %= MOD;
        }
        e >>= 1;
        b *= b;
        b %= MOD;
    }
    return res;
}

ll fact[mxN];
ll invf[mxN];
ll choose(ll n, ll k) {
    return (((fact[n] * invf[k]) % MOD) * invf[n - k]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (ll i = 1; i < mxN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invf[mxN - 1] = pw(fact[mxN - 1], MOD - 2);
    for (ll i = mxN - 1; i; i--) {
        invf[i - 1] = (invf[i] * i) % MOD;
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        as.resize(n);
        for (int &a : as) {
            cin >> a;
        }
        vector<ll> suml(n + 1);
        vector<ll> sumr(n);
        ll cs = 0;
        for (int i = 0; i < n; i++) {
            cs += as[i];
            suml[i] = cs;
        }
        if (cs == 0) {
            cout << pw(2, n - 1) << "\n";
            continue;
        }
        suml[n] = -1;
        cs = 0;
        for (int i = n - 1; i >= 0; i--) {
            cs += as[i];
            sumr[i] = cs;
        }
        ll res = 1;
        int sz = 1;
        int r = n - 1;
        for (int i = 1; i <= n; i++) {
            if (suml[i] != suml[i - 1]) {
                // cout << i << endl;
                while (sumr[r] < suml[i - 1]) {
                    r--;
                    if (r < 0) {
                        break;
                    }
                }
                int cnt = 0;
                if (r >= 0) {
                    while (sumr[r] == suml[i - 1]) {
                        cnt++;
                        r--;
                        if (r < 0) {
                            break;
                        }
                    }
                }
                // cout << r << " - " << cnt << endl;
                if (r < i) {
                    if (i < n) {
                        // cout << cnt << "!" << endl;
                        res *= pw(2, max(0, cnt));
                        res %= MOD;
                    }
                    break;
                }
                // cout << sz << " " << cnt << endl;
                int mn = min(sz, cnt);
                ll cur = 0;
                for (int k = 0; k <= mn; k++) {
                    cur += choose(sz, k) * choose(cnt, k);
                    cur %= MOD;
                }
                res *= cur;
                res %= MOD;
                sz = 0;
                if (r <= i) {
                    break;
                }
            }
            sz++;
        }
        cout << res << "\n";
        // ll res = 1;
        // int l = 0, r = n-1;
        // while (l < r) {
        //     int ll = l + 1;
        //     while (as[ll] == 0) {
        //         ll++;
        //     }
        //     int rr = r - 1;
        //     while (as[rr] == 0) {
        //         rr--;
        //     }
        //     if(ll == r) {

        //     }
        //     ll --;
        //     rr ++;
        // }
        // dp.clear();
        // dp.resize(n,-1);
        // cout << rec(0,n) << "\n";
    }
    return 0;
}