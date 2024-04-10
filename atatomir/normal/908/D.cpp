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

#define maxN 1024
#define mod 1000000007

ll k, pa, pb, ii, i, j, jj, x;
ll dp[maxN][maxN], cha, chb;
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll inv(ll x) {
    return poww(x, mod - 2);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> k >> pa >> pb;
    cha = (pa * inv(pa + pb)) % mod;
    chb = (pb * inv(pa + pb)) % mod;

    dp[0][1] = 1;
    ll aux = inv(1 + mod - cha);
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {

            //! add an a
            ii = i;
            jj = j + 1;

            dp[ii][jj] = (dp[ii][jj] + dp[i][j] * cha) % mod;

            //! add a b
            ii = i + j;
            jj = j;

            if (ii >= k) {
                ans += ((dp[i][j] * ii) % mod) * chb;
                ans %= mod;
            } else {
                dp[ii][jj] = (dp[ii][jj] + dp[i][j] * chb) % mod;
            }

        }

        ll fr = (dp[i][k] * chb) % mod;
        fr = (fr * aux) % mod;
        ll ba = i + k + cha * aux;
        ba %= mod;
        ans = (ans + fr * ba) % mod;
    }

    cout << ans;


    return 0;
}