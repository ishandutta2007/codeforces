#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 55
#define mod 1000000007
#define act_state dp[ss][l1][l2][ll1][ll2]

int n, i, ss, dd, l1, l2, ll1, ll2;
int tp[maxN];
ll dp[2][maxN][maxN][maxN][maxN];

void add(ll&a , ll b) {
    a += b;
    if (a >= mod) a %= mod;
}

ll comb(ll x) {
    return (x * (x - 1)) / 2;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> tp[i];

    ss = 0; dd = 1;
    l1 = l2 = ll1 = ll2 = 0;
    if (tp[1] == 2) l1++;
    else            l2++;
    if (tp[2] == 2) ll1++;
    else            ll2++;
    dp[ss][l1][l2][ll1][ll2] = 1;

    for (i = 2; i < n; i++) {

        for (l1 = 0; l1 <= i + 1; l1++)
            for (l2 = 0; l1 + l2 <= i + 1; l2++)
                for (ll1 = 0; l1 + l2 + ll1 <= i + 1; ll1++)
                    for (ll2 = 0; l1 + l2 + ll1 + ll2 <= i; ll2++)
                        dp[dd][l1][l2][ll1][ll2] = 0;

        for (l1 = 0; l1 <= i; l1++) {
            for (l2 = 0; l1 + l2 <= i; l2++) {
                for (ll1 = 0; l1 + l2 + ll1 <= i; ll1++) {
                    for (ll2 = 0; l1 + l2 + ll1 + ll2 <= i; ll2++) {
                        if (act_state == 0) continue;

                        //cerr << i << ' ' << l1 << ' ' << l2 << ' ' << ll1 << ' ' << ll2 << " = " << act_state << '\n';

                        //! you need to generate another level
                        if (l1 + l2 == 0) {
                            if (ll1 + ll2 == 0) continue;
                            add(dp[ss][ll1][ll2][0][0], act_state);
                            continue;
                        }

                        //! you must continue this level
                        if (tp[i + 1] == 2) {
                            //! use only one
                            if (l1 > 0) add(dp[dd][l1 - 1][l2][ll1 + 1][ll2], act_state * l1);
                            if (l2 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 + 1][ll2], act_state * l2);

                            //! use both edges
                            if (l1 > 0 && ll1 > 0) add(dp[dd][l1 - 1][l2][ll1 - 1][ll2], act_state * l1 * ll1);
                            if (l1 > 0 && ll2 > 0) add(dp[dd][l1 - 1][l2][ll1 + 1][ll2 - 1], act_state * l1 * ll2);

                            if (l2 > 0 && ll1 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 - 1][ll2], act_state * l2 * ll1);
                            if (l2 > 0 && ll2 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 + 1][ll2 - 1], act_state * l2 * ll2);
                        } else {
                            //! use only one
                            if (l1 > 0) add(dp[dd][l1 - 1][l2][ll1][ll2 + 1], act_state * l1);
                            if (l2 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1][ll2 + 1], act_state * l2);

                            //! use two edges
                            if (l1 > 0 && ll1 > 0) add(dp[dd][l1 - 1][l2][ll1 - 1 + 1][ll2], act_state * l1 * ll1);
                            if (l1 > 0 && ll2 > 0) add(dp[dd][l1 - 1][l2][ll1 + 1 + 1][ll2 - 1], act_state * l1 * ll2);

                            if (l2 > 0 && ll1 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 - 1 + 1][ll2], act_state * l2 * ll1);
                            if (l2 > 0 && ll2 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 + 1 + 1][ll2 - 1], act_state * l2 * ll2);

                            //! use all three edges
                            if (l1 > 0 && ll1 > 1) add(dp[dd][l1 - 1][l2][ll1 - 2][ll2], act_state * l1 * comb(ll1));
                            if (l1 > 0 && ll2 > 1) add(dp[dd][l1 - 1][l2][ll1 + 2][ll2 - 2], act_state * l1 * comb(ll2));
                            if (l1 > 0 && ll1 * ll2 > 0) add(dp[dd][l1 - 1][l2][ll1 - 1 + 1][ll2 - 1], act_state * l1 * ll1 * ll2);

                            if (l2 > 0 && ll1 > 1) add(dp[dd][l1 + 1][l2 - 1][ll1 - 2][ll2], act_state * l2 * comb(ll1));
                            if (l2 > 0 && ll2 > 1) add(dp[dd][l1 + 1][l2 - 1][ll1 + 2][ll2 - 2], act_state * l2 * comb(ll2));
                            if (l2 > 0 && ll1 * ll2 > 0) add(dp[dd][l1 + 1][l2 - 1][ll1 - 1 + 1][ll2 - 1], act_state * l2 * ll1 * ll2);

                        }

                    }
                }
            }
        }


        swap(ss, dd);
    }

    ll ans = dp[ss][0][0][0][0];
    cout << ans;


    return 0;
}