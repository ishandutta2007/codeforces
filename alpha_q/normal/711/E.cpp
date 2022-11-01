#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

const ull MOD = 1e6 + 3;
const ull POW = MOD - 1;

ull n, k;

ull bigMod (ull a, ull e, ull m) {
    ull r = 1; 
    a %= m, e %= (m - 1);
    while (e) {
        if (e & 1) r = (r * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return r;
}

int main (int argc, char const *argv[]) {
    scanf("%lld %lld", &n, &k);

    ull lg;
    for (lg = 1; (1LL << lg) < k; ++lg); 

    if (n < lg) {
        printf("1 1\n");
        return 0;
    }

    ull NK = ((n % POW) * ((k - 1) % POW)) % POW;
    ull Down = bigMod(2, NK, MOD);

    ull PROD = 1, Two = bigMod(2, n % POW, MOD);
    for (ull i = 1; i <= MOD; ++i) {
        PROD *= (Two - i);
        PROD %= MOD;
    }

    ull PROD_Right = 1;
    if (k - 1 > MOD) PROD_Right = 0;
    else {
        for (ull i = 1; i <= k - 1; ++i) {
            PROD_Right *= (Two - i);
            PROD_Right %= MOD;
        }
    }

    ull Up = Down - PROD_Right;
    Up = ((Up % MOD) + MOD) % MOD;

    ull tot = k - 1, two_count = 0;
    for (ull j = 1; (1LL << j) <= tot; ++j) {
        two_count -= tot/(1LL << j);
        two_count %= POW;
    }

    two_count %= POW, two_count += POW, two_count %= POW;
    ull bad = bigMod(2, two_count, MOD);

    Up = (Up * bad) % MOD, Down = (Down * bad) % MOD;
    printf("%lld %lld\n", Up, Down);
    return 0;
}