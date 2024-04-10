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

#define mod 1000000007
#define maxN 1555
#define maxK 100011

int n, m, k, i, j;
ll a, b;
ll ch_p, ch_np;

ll fact[maxK];
ll C[maxK];
ll p[maxN], p_sum[maxN];

ll dp[maxN][maxN];
ll sum[maxN][maxN];
ll aux[maxN];




ll poww(ll a, ll b) {
    ll ans = 1;

    a %= mod;
    if (a < 0) a += mod;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void compute_comb_and_p() {
    int i, j;

    fact[0] = 1;
    fact[1] = 1;
    for (i = 2; i <= k; i++) fact[i] = (fact[i - 1] * i) % mod;

    C[0] = 1;
    for (i = 1; i <= k && i <= m; i++) {
        C[i] = fact[k] * poww(fact[k - i], mod - 2);
        C[i] %= mod;

        C[i] *= poww(fact[i], mod - 2);
        C[i] %= mod;
    }


    for (i = 0; i <= m; i++) {
        if (i <= k) {
            p[i] = ((C[i] * poww(ch_p, i)) % mod) * poww(ch_np, k - i);
            p[i] %= mod;
        }

        p_sum[i] = p[i];
        if (i > 0) p_sum[i] = (p_sum[i - 1] + p[i]) % mod;
    }
}




int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%lld%lld%d", &n, &m, &a, &b, &k);
    ch_p = (a * poww(b, mod - 2)) % mod;
    ch_np = ((b - a) * poww(b, mod - 2)) % mod;

    compute_comb_and_p();

    dp[0][m] = 1;
    sum[0][m] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            aux[j] = (aux[j - 1] + p[j] * sum[i - 1][j]) % mod;

        for (j = 1; j <= m; j++) {
            dp[i][j] = ((mod + sum[i - 1][m] - sum[i - 1][m - j]) * p_sum[j - 1]) % mod;
            dp[i][j] -= aux[j - 1];
            dp[i][j] = ((dp[i][j] + mod) * p[m - j]) % mod;

            sum[i][j] = sum[i][j - 1] + dp[i][j];
            sum[i][j] %= mod;
        }

    }

    printf("%lld", sum[n][m]);


    return 0;
}