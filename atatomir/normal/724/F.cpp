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
#define maxD 12

ll n, d, mod, i, j, k, act, aux, t;
ll dp[maxN][maxD][maxN];

ll fact[maxN];
ll inv_fact[maxN];
ll inv_two;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void pre() {
    int i;

    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[n] = poww(fact[n], mod - 2);
    for (i = n - 1; i > 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

    inv_two = poww(2, mod - 2);
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &d, &mod);
    pre();


    for (i = 0; i <= n; i++) dp[1][0][i] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= d; j++) {
            for (k = 1; k <= n; k++) {
                dp[i][j][k] += dp[i][j][k - 1];

                act = 1;
                for (t = 1; t <= j; t++) {
                    if (i - k * t <= 0) break;

                    if (k == 1) {
                        dp[i][j][k] += dp[i - t][j - t][0];
                        if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
                        continue;
                    }

                    act = act * (dp[k][d - 1][k - 1] + t - 1);
                    if (act >= mod) act %= mod;

                    aux = (act * inv_fact[t]) % mod;
                    dp[i][j][k] += (aux * dp[i - k * t][j - t][k - 1]) % mod;
                    if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
                }
            }
        }
    }

    if (n <= 2) {
        printf("1");
        return 0;
    }

    ll ans = dp[n][d][(n - 1) / 2];
    if (n % 2 == 0) {
        act = dp[n / 2][d - 1][(n / 2) - 1] + 1;
        act = (act * (act + mod - 1)) % mod;
        act = (act * inv_two) % mod;

        ans += act;
    }

    ans %= mod;
    printf("%lld", ans);


    return 0;
}