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
        vector<int> as(n);
        int cntO = 0;
        int cntE = 0;
        for (int &a : as) {
            cin >> a;
            if (a & 1) {
                cntO++;
            } else {
                cntE++;
            }
        }
        vector<vector<bool>> dp0(cntO + 1, vector<bool>(cntE + 1));
        vector<vector<bool>> dp1(cntO + 1, vector<bool>(cntE + 1));
        dp0[0][0] = true;
        for (int co = 0; co <= cntO; co++) {
            for (int ce = 0; ce <= cntE; ce++) {
                if (co == 0 && ce == 0) {
                    continue;
                }
                if ((co + ce + n) & 1) {
                    // Bob
                    bool win0 = false;
                    bool win1 = false;
                    if (co > 0) {
                        // cout << "win0 |= " << dp1[co - 1][ce] << " | " << co
                        //  << endl;
                        win0 |= (!dp0[co - 1][ce]);
                        win1 |= (!dp1[co - 1][ce]);
                    }
                    if (ce > 0) {
                        win0 |= (!dp0[co][ce - 1]);
                        win1 |= (!dp1[co][ce - 1]);
                    }
                    dp0[co][ce] = !win0;
                    dp1[co][ce] = !win1;

                } else {
                    // Alice
                    bool win0 = false;
                    bool win1 = false;
                    if (co > 0) {
                        win0 |= (dp1[co - 1][ce]);
                        win1 |= (dp0[co - 1][ce]);
                    }
                    if (ce > 0) {
                        win0 |= (dp0[co][ce - 1]);
                        win1 |= (dp1[co][ce - 1]);
                    }
                    dp0[co][ce] = win0;
                    dp1[co][ce] = win1;
                }
                // int res = 0;
                // if (co > 0) {
                //     int d = dp[co - 1][ce];
                //     if (d == 1) {
                //         int r = ((co - 1) & 1) ? 2 : 1;
                //         res |= r;
                //     } else if (d == 2) {
                //         int r = ((co - 1) & 1) ? 1 : 2;
                //         res |= r;
                //     }
                // }
                // if (ce > 0) {
                //     int d = dp[co][ce - 1];
                //     if (d == 1) {
                //         int r = ((co)&1) ? 2 : 1;
                //         res |= r;
                //     } else if (d == 2) {
                //         int r = ((co)&1) ? 1 : 2;
                //         res |= r;
                //     }
                // }
                // dp[co][ce] = res;
            }
        }
        // for (int co = 0; co <= cntO; co++) {
        //     for (int ce = 0; ce <= cntE; ce++) {
        //         cout << dp0[co][ce] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "ZZ" << endl;
        // for (int co = 0; co <= cntO; co++) {
        //     for (int ce = 0; ce <= cntE; ce++) {
        //         cout << dp1[co][ce] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << ((dp0[cntO][cntE]) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}